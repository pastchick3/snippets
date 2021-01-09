module inverter_tb();
    reg in;
    wire out;
    inverter inverter(in, out);

    initial
        begin
            $dumpfile("inverter.vcd");
            $dumpvars(0, inverter);

            in = 0;
            #10 in = 1;
            #10 in = 0;
            #10 in = 1;
            #10 $finish;
        end
endmodule
