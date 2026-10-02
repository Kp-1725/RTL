module tb_smoke_counter;
    logic clk;
    logic rst;
    logic [7:0] q;

    smoke_counter dut (
        .clk(clk),
        .rst(rst),
        .q(q)
    );

    always #5 clk = ~clk;

    initial begin
        $dumpfile("smoke_counter.vcd");
        $dumpvars(0, tb_smoke_counter);

        clk = 0;
        rst = 1;

        repeat (2) @(posedge clk);
        rst = 0;

        repeat (4) @(posedge clk);

        if (q == 8'd4) begin
            $display("PASS: SystemVerilog compile and simulation succeeded.");
        end else begin
            $display("FAIL: q=%0d expected 4", q);
            $fatal(1, "Smoke test failed");
        end

        $finish;
    end
endmodule
