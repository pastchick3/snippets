// iverilog -o inverter.vvp inverter_tb.v inverter.v
// vvp inverter.vvp
// gtkwave inverter.vcd

module inverter(input in, output out);
    assign out = ~in;
endmodule
