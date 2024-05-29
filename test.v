module rotate(
input [7:0] A,
input [2:0] ctrl,
input dir,
output reg[7:0] out
);

always @(*)
begin
    case(dir)
    1'b1:begin for(integer i =0;i<8;i=i+1) begin out[i] = A[(ctrl+i)%8]; end end
    1'b0: begin for(integer i =0;i<8;i=i+1) begin out[i] = A[(ctrl-i+8)%8]; end end
    endcase
end 
endmodule

module testbench();
// Declare internal signals for connecting to the rotate module
reg [7:0] A;
reg [2:0] ctrl;
wire [7:0] out;
reg dir;
// Instantiate the rotate module
rotate UUT (
    .A(A), 
    .ctrl(ctrl), 
    .out(out),
    .dir(dir)
);

initial 
begin
    A = 8'b00011001; ctrl = 3'b000;dir=1;
    #10 A = 8'b00011001; ctrl = 3'b001;dir=1;
    #10 A = 8'b00011001; ctrl = 3'b010;dir=1;
    #10 A = 8'b00011001; ctrl = 3'b011;dir=0;
    #10 A = 8'b00011001; ctrl = 3'b100;dir=0;
    #10 A = 8'b00011001; ctrl = 3'b101;dir=0;
    #10 A = 8'b00011001; ctrl = 3'b110;dir=1;
    #10 A = 8'b00011001; ctrl = 3'b111;dir=1;
    #10 $finish; // Properly terminate the simulation
end

initial 
begin
    $monitor($time, " A: %b, ctrl: %b, Value: %b, Direction: %b", A, ctrl, out,dir);
end

endmodule