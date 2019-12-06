module CC  (
  input wire                   clk,    
  input wire                   reset,  
  input wire                   enable, 
  output wire [7:0] out  // data to read
);

reg [7:0] count;

assign out = count;


always @(posedge clk) begin

	if (reset) begin
		count <= 0;
	end 
	else if(enable)
	begin 
		count<=count+1;
	end

end 

endmodule
