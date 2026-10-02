module FIFO_32bit_6depth (
  input wire clk,
  input wire rst,
  input wire wr_en,
  input wire rd_en,
  input wire [31:0] data_in,
  output reg [31:0] data_out,
  output reg full,
  output reg empty
);

  parameter depth = 6;
  reg [5:0] wr_ptr;
  reg [5:0] rd_ptr;
  reg [31:0] mem [0:5];

  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      wr_ptr <= 6'b0;
      rd_ptr <= 6'b0;
      full <= 1'b0;
      empty <= 1'b1;
    end else begin
      if (wr_en && !full) begin
        mem[wr_ptr] <= data_in;
        wr_ptr <= wr_ptr + 1;
        if (wr_ptr == rd_ptr) begin
          full <= 1'b1;
        end
      end
      if (rd_en && !empty) begin
        data_out <= mem[rd_ptr];
        rd_ptr <= rd_ptr + 1;
        if (rd_ptr == wr_ptr) begin
          empty <= 1'b1;
        end
      end
    end
  end

  assign full = (wr_ptr == rd_ptr) && !empty;
  assign empty = (wr_ptr == rd_ptr) && full;

endmodule
