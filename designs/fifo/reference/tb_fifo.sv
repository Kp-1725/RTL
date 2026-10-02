module tb_fifo;
    localparam int DATA_WIDTH = 8;
    localparam int DEPTH = 4;

    logic clk;
    logic rst;
    logic wr_en;
    logic rd_en;
    logic [DATA_WIDTH-1:0] data_in;
    logic [DATA_WIDTH-1:0] data_out;
    logic full;
    logic empty;

    logic [DATA_WIDTH-1:0] expected_queue[$];
    integer checks;
    integer assertion_checks;
    integer assertion_passes;

    fifo #(
        .DATA_WIDTH(DATA_WIDTH),
        .DEPTH(DEPTH)
    ) dut (
        .clk(clk),
        .rst(rst),
        .wr_en(wr_en),
        .rd_en(rd_en),
        .data_in(data_in),
        .data_out(data_out),
        .full(full),
        .empty(empty)
    );

    always #5 clk = ~clk;

`ifdef VERILATOR_COVERAGE
    always @(posedge clk) begin
        if (!rst) begin
            assertion_checks = assertion_checks + 1;
            if (!(full && empty)) begin
                assertion_passes = assertion_passes + 1;
            end else begin
                $fatal(1, "FAIL: full and empty asserted together");
            end
        end
    end

    property p_flags_are_not_both_active;
        @(posedge clk) !(full && empty);
    endproperty
    assert property (p_flags_are_not_both_active);
    cover property (@(posedge clk) full);
    cover property (@(posedge clk) empty);
`endif

    task automatic check_flags;
        begin
            assert (empty === (expected_queue.size() == 0))
                else $fatal(1, "FAIL: empty mismatch at time %0t", $time);
            assert (full === (expected_queue.size() == DEPTH))
                else $fatal(1, "FAIL: full mismatch at time %0t", $time);
            checks = checks + 1;
        end
    endtask

    task automatic write_item(input logic [DATA_WIDTH-1:0] value);
        begin
            @(negedge clk);
            wr_en = 1'b1;
            rd_en = 1'b0;
            data_in = value;
            @(posedge clk);
            #1;
            if (expected_queue.size() < DEPTH) begin
                expected_queue.push_back(value);
            end
            check_flags();
        end
    endtask

    task automatic read_item;
        logic [DATA_WIDTH-1:0] expected_value;
        logic had_read;
        begin
            @(negedge clk);
            wr_en = 1'b0;
            rd_en = 1'b1;
            had_read = (expected_queue.size() > 0);
            if (had_read) begin
                expected_value = expected_queue.pop_front();
            end
            @(posedge clk);
            #1;
            if (had_read && expected_value !== data_out) begin
                $fatal(1, "FAIL: read data mismatch: expected %0d got %0d", expected_value, data_out);
            end
            check_flags();
        end
    endtask

    task automatic simultaneous_item(
        input logic [DATA_WIDTH-1:0] value
    );
        logic [DATA_WIDTH-1:0] expected_value;
        logic had_read;
        logic had_write;
        begin
            @(negedge clk);
            wr_en = 1'b1;
            rd_en = 1'b1;
            data_in = value;
            had_read = (expected_queue.size() > 0);
            had_write = (expected_queue.size() < DEPTH);
            if (had_read) begin
                expected_value = expected_queue.pop_front();
            end
            if (had_write) begin
                expected_queue.push_back(value);
            end
            @(posedge clk);
            #1;
            if (had_read && expected_value !== data_out) begin
                $fatal(1, "FAIL: simultaneous read mismatch: expected %0d got %0d", expected_value, data_out);
            end
            check_flags();
        end
    endtask

    initial begin
        $dumpfile("fifo.vcd");
        $dumpvars(0, tb_fifo);

        clk = 1'b0;
        rst = 1'b1;
        wr_en = 1'b0;
        rd_en = 1'b0;
        data_in = '0;
        checks = 0;
        assertion_checks = 0;
        assertion_passes = 0;

        repeat (2) @(posedge clk);
        #1;
        expected_queue = {};
        check_flags();
        rst = 1'b0;

        // Empty FIFO and underflow attempt.
        read_item();

        // Single write/read and FIFO ordering.
        write_item(8'h11);
        read_item();

        // Fill the FIFO and verify the full boundary.
        write_item(8'h21);
        write_item(8'h22);
        write_item(8'h23);
        write_item(8'h24);
        if (!full) begin
            $fatal(1, "FAIL: FIFO did not become full");
        end

        // Overflow attempt must not alter stored data or flags.
        write_item(8'hff);

        // Multiple reads verify FIFO order and empty boundary.
        read_item();
        read_item();
        read_item();
        read_item();
        if (!empty) begin
            $fatal(1, "FAIL: FIFO did not become empty");
        end

        // Simultaneous read/write while partially occupied.
        write_item(8'ha1);
        write_item(8'ha2);
        simultaneous_item(8'ha3);
        read_item();
        read_item();

        // Reset during operation clears state and output.
        write_item(8'h55);
        @(negedge clk);
        rst = 1'b1;
        wr_en = 1'b1;
        rd_en = 1'b1;
        data_in = 8'he7;
        @(posedge clk);
        #1;
        expected_queue = {};
        if (data_out !== 8'h00) begin
            $fatal(1, "FAIL: reset did not clear data_out");
        end
        check_flags();
        rst = 1'b0;

        @(negedge clk);
        wr_en = 1'b0;
        rd_en = 1'b0;
        check_flags();

        $display("PASS: FIFO reference tests completed (%0d checks).", checks);
        $display("ASSERTION_COVERAGE checks=%0d passes=%0d", assertion_checks, assertion_passes);
        $finish;
    end
endmodule
