`timescale 1ns/1ps

module CC_bench;

reg enable;
reg reset;
reg clk;

wire [7:0] out;

CC CC_ (
	.enable(enable),
	.reset(reset),
	.clk(clk),
	.out(out));

	initial begin
		$dumpfile("CC.vcd");
		$dumpvars(0, CC_bench.CC_);
		clk = 0;
		reset = 1;
		#26 reset = 0;
		#500000 $finish;
	end

	always begin
		#25 clk = ~clk;
	end

	always begin
		#24;
		enable = $random;
		#26;
	end
endmodule
