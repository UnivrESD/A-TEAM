//Fir_Filter Behavioral Model
//Jonathan Allen
//ECE 659 HW#1
module fir_filter(
	clk,
	reset,
	data_in,
	data_out,
	coef_in,
	load_c
);
genvar j;
parameter TAPS = 25;
//Input Ports
input clk;
input reset;
input [7:0] data_in;
input [7:0] coef_in;
input load_c;

//Output Ports
output [17:0] data_out;

//Data Type Declarations for IO
wire clk;
wire reset;
wire [7:0] data_in;
wire [7:0] coef_in;
wire load_c;
reg [17:0] temp;

reg [17:0] data_out;

//Other Declarations
reg [7:0] r_storage [TAPS-1:0];
reg [7:0] coef_storage [TAPS-1:0];
integer i;
reg [15:0] product_array [TAPS-1:0];

generate
	for(j=0;j<TAPS;j=j+1)
		begin:mpy_struct
			lpm_mult0 m (r_storage[j],coef_storage[j],clk,product_array[j]);
		end
endgenerate	
/*
lpm_mult0 m0(r_storage[0],coef_storage[0],clk,product_array[0]);
lpm_mult0 m1(r_storage[1],coef_storage[1],clk,product_array[1]);
lpm_mult0 m2(r_storage[2],coef_storage[2],clk,product_array[2]);
lpm_mult0 m3(r_storage[3],coef_storage[3],clk,product_array[3]);
lpm_mult0 m4(r_storage[4],coef_storage[4],clk,product_array[4]);
lpm_mult0 m5(r_storage[5],coef_storage[5],clk,product_array[5]);
lpm_mult0 m6(r_storage[6],coef_storage[6],clk,product_array[6]);
lpm_mult0 m7(r_storage[7],coef_storage[7],clk,product_array[7]);
lpm_mult0 m8(r_storage[8],coef_storage[8],clk,product_array[8]);
lpm_mult0 m9(r_storage[9],coef_storage[9],clk,product_array[9]);
lpm_mult0 m10(r_storage[10],coef_storage[10],clk,product_array[10]);
lpm_mult0 m11(r_storage[11],coef_storage[11],clk,product_array[11]);
lpm_mult0 m12(r_storage[12],coef_storage[12],clk,product_array[12]);
lpm_mult0 m13(r_storage[13],coef_storage[13],clk,product_array[13]);
lpm_mult0 m14(r_storage[14],coef_storage[14],clk,product_array[14]);
lpm_mult0 m15(r_storage[15],coef_storage[15],clk,product_array[15]);
lpm_mult0 m16(r_storage[16],coef_storage[16],clk,product_array[16]);
lpm_mult0 m17(r_storage[17],coef_storage[17],clk,product_array[17]);
lpm_mult0 m18(r_storage[18],coef_storage[18],clk,product_array[18]);
lpm_mult0 m19(r_storage[19],coef_storage[19],clk,product_array[19]);
lpm_mult0 m20(r_storage[20],coef_storage[20],clk,product_array[20]);
lpm_mult0 m21(r_storage[21],coef_storage[21],clk,product_array[21]);
lpm_mult0 m22(r_storage[22],coef_storage[22],clk,product_array[22]);
lpm_mult0 m23(r_storage[23],coef_storage[23],clk,product_array[23]);
lpm_mult0 m24(r_storage[24],coef_storage[24],clk,product_array[24]);
*/
//par_add0 parallel_add(product_array[0],product_array[1],product_array[2],product_array[3],data_out);


//Code starts here
always @ (posedge clk)
begin

	if(reset==1'b1)begin		//reset
		
		for(i=0;i<TAPS;i=i+1)begin
			r_storage[i]<= 8'b00000000;
			coef_storage[i]<=8'b00000000;
		end
	end
	else if(load_c==1'b1)begin	//load coeficients
		for(i=TAPS-1;i>0;i=i-1)begin
			coef_storage[i] = coef_storage[i-1];
		end
		coef_storage[0]=coef_in;
	end
	else begin
		for(i=TAPS-1;i>0;i=i-1)begin
			r_storage[i] = r_storage[i-1];
		end
		r_storage[0]=data_in;
		temp=0;
		for(i=0;i<TAPS;i=i+1)begin
			temp=temp+product_array[i];
		end
		data_out=temp;
	end
end
endmodule