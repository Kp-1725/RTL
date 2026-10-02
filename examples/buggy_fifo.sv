module buggy_fifo #(
    parameter int DATA_WIDTH = 8,
    parameter int DEPTH = 4
) (
    input  logic                  clk,
    input  logic                  rst,
    input  logic                  wr_en,
    input  logic                  rd_en,
    input  logic [DATA_WIDTH-1:0] data_in,
    output logic [DATA_WIDTH-1:0] data_out,
    output logic                  full,
    output logic                  empty
);

    logic [DATA_WIDTH-1:0] memory [0:DEPTH-1];
    logic [$clog2(DEPTH)-1:0] read_pointer;
    logic [$clog2(DEPTH)-1:0] write_pointer;
    logic [$clog2(DEPTH + 1)-1:0] count;

    assign full  = (count == DEPTH);
    assign empty = (count == 0);

    always_ff @(posedge clk) begin
        if (rst) begin
            read_pointer <= '0;
            write_pointer <= '0;
            count <= '0;
            data_out <= '0;
        end else begin
            if (wr_en && !full) begin
                memory[write_pointer] <= data_in;
                write_pointer <= (write_pointer == DEPTH - 1) ? '0 : write_pointer + 1'b1;
                count <= count + 1'b1;
            end

            if (rd_en && !empty) begin
                data_out <= memory[read_pointer];
                read_pointer <= (read_pointer == DEPTH - 1) ? '0 : read_pointer + 1'b1;
                count <= count - 1'b1;
            end
        end
    end
endmodule
