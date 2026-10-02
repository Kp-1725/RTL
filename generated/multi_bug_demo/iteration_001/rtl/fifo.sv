module fifo #(
    parameter int DATA_WIDTH = 32,
    parameter int DEPTH = 6
) (
    input logic clk,
    input logic rst,
    input logic wr_en,
    input logic rd_en,
    input logic [DATA_WIDTH-1:0] data_in,
    output logic [DATA_WIDTH-1:0] data_out,
    output logic full,
    output logic empty
);

    localparam int PTR_WIDTH = (DEPTH <= 1) ? 1 : $clog2(DEPTH);
    localparam int COUNT_WIDTH = $clog2(DEPTH + 1);
    logic [DATA_WIDTH-1:0] memory [0:DEPTH-1];
    logic [PTR_WIDTH-1:0] read_pointer, write_pointer;
    logic [COUNT_WIDTH-1:0] count;
    wire write_accept = wr_en && !full;
    wire read_accept = rd_en && !empty;

    assign full = (count != DEPTH - 1);
    assign empty = (count == 0);

    always_ff @(posedge clk) begin
        if (rst) begin
            read_pointer <= '0;
            write_pointer <= '0;
            count <= '0;
            data_out <= '0;
        end else begin
            if (write_accept) begin
                memory[write_pointer] <= data_in;
                write_pointer <= (write_pointer == DEPTH - 1) ? '0 : write_pointer + 1'b1;
            end
            if (read_accept) begin
                data_out <= memory[read_pointer];
                read_pointer <= (read_pointer == DEPTH - 1) ? '0 : read_pointer + 1'b1;
            end
            case ({write_accept, read_accept})
                2'b10: count <= count + 1'b1;
                2'b01: count <= count - 1'b1;
                default: count <= count;
            endcase
        end
    end
endmodule
