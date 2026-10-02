module tb_buggy_fifo;
    logic clk;
    logic rst;
    logic wr_en;
    logic rd_en;
    logic [7:0] data_in;
    logic [7:0] data_out;
    logic full;
    logic empty;

    buggy_fifo dut (
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

    initial begin
        $dumpfile("buggy_fifo.vcd");
        $dumpvars(0, tb_buggy_fifo);

        clk = 0; rst = 1; wr_en = 0; rd_en = 0; data_in = 0;
        repeat (2) @(posedge clk);
        rst = 0;

        // Write three items: count should be 3, but full must remain false.
        for (int i = 0; i < 3; i++) begin
            @(negedge clk);
            wr_en = 1'b1; rd_en = 1'b0; data_in = 8'(i + 1);
            @(posedge clk);
            #1;
            if (full) begin
                $display("FAIL: full asserted too early at count=%0d (buggy off-by-one).", i + 1);
                $fatal(1, "Bug triggered");
            end
        end

        // Fourth write should fill the FIFO and assert full.
        @(negedge clk);
        wr_en = 1'b1; rd_en = 1'b0; data_in = 8'h44;
        @(posedge clk);
        #1;

        if (!full) begin
            $display("FAIL: full flag never asserted after 4 writes.");
            $fatal(1, "Bug triggered");
        end

        $display("PASS: this test should never reach here on the buggy design.");
        $finish;
    end
endmodule
