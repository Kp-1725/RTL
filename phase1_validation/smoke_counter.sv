module smoke_counter (
    input logic clk,
    input logic rst,
    output logic [7:0] q
);

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            q <= 8'd0;
        end else begin
            q <= q + 8'd1;
        end
    end

endmodule
