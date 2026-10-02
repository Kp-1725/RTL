module tb_fifo;
    logic clk, rst, wr_en, rd_en;
    logic [31:0] data_in, data_out;
    logic full, empty;
    logic [31:0] expected_queue[$];
    integer checks;
    integer assertion_checks, assertion_passes;

    fifo dut (
        .clk(clk), .rst(rst), .wr_en(wr_en), .rd_en(rd_en),
        .data_in(data_in), .data_out(data_out), .full(full), .empty(empty)
    );

    always #5 clk = ~clk;

`ifdef VERILATOR_COVERAGE
    always @(posedge clk) begin
        if (!rst) begin
            assertion_checks = assertion_checks + 1;
            if (!(full && empty)) assertion_passes = assertion_passes + 1;
            else $fatal(1, "FAIL: full and empty asserted together");
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
        assert (empty === (expected_queue.size() == 0)) else $fatal(1, "FAIL: empty mismatch");
        assert (full === (expected_queue.size() == 6)) else $fatal(1, "FAIL: full mismatch");
        checks = checks + 1;
    endtask

    task automatic write_item(input logic [31:0] value);
        @(negedge clk);
        wr_en = 1'b1; rd_en = 1'b0; data_in = value;
        @(posedge clk); #1;
        if (expected_queue.size() < 6) expected_queue.push_back(value);
        check_flags();
    endtask

    task automatic read_item;
        logic [31:0] expected_value;
        logic had_read;
        @(negedge clk);
        wr_en = 1'b0; rd_en = 1'b1;
        had_read = expected_queue.size() > 0;
        if (had_read) expected_value = expected_queue.pop_front();
        @(posedge clk); #1;
        if (had_read && expected_value !== data_out) $fatal(1, "FAIL: data mismatch");
        check_flags();
    endtask

    initial begin
        $dumpfile("fifo_agent.vcd");
        $dumpvars(0, tb_fifo);
        clk = 0; rst = 1; wr_en = 0; rd_en = 0; data_in = 0; checks = 0;
        assertion_checks = 0; assertion_passes = 0;
        repeat (2) @(posedge clk); #1;
        expected_queue = {};
        check_flags();
        rst = 0;

        read_item();
        write_item(8'h11);
        read_item();
        write_item(8'h21);
        write_item(8'h22);
        write_item(8'h23);
        write_item(8'h24);
        write_item(8'h25);
        write_item(8'h26);
        write_item(8'hff);
        read_item();
        read_item();
        read_item();
        read_item();
        read_item();
        read_item();

        write_item(8'ha1);
        write_item(8'ha2);
        @(negedge clk);
        wr_en = 1'b1; rd_en = 1'b1; data_in = 8'ha3;
        expected_queue.push_back(8'ha3);
        expected_queue.pop_front();
        @(posedge clk); #1;
        if (data_out !== 8'ha1) $fatal(1, "FAIL: simultaneous data mismatch");
        check_flags();
        read_item();

        write_item(8'h55);
        @(negedge clk); rst = 1'b1; wr_en = 1'b1; rd_en = 1'b1;
        @(posedge clk); #1;
        expected_queue = {};
        if (data_out !== 8'h00) $fatal(1, "FAIL: reset output mismatch");
        check_flags();
        $display("PASS: generated FIFO testbench completed (%0d checks).", checks);
        $display("ASSERTION_COVERAGE checks=%0d passes=%0d", assertion_checks, assertion_passes);
        $finish;
    end
endmodule
