    if(BRAM_RST) /*asyncronous resest*/ BRAM_RDDATA <= 0;
    else if(BRAM_EN) begin
        if(BRAM_WE == 4'b0000) BRAM_RDDATA <= mem[addr];
        else begin
            if(BRAM_WE[0] == 1) mem[addr][8*(0+1)-1:8*0] <= BRAM_WRDATA[8*(0+1)-1:8*0];
            if(BRAM_WE[1] == 1) mem[addr][8*(1+1)-1:8*1] <= BRAM_WRDATA[8*(1+1)-1:8*1];
            if(BRAM_WE[2] == 1) mem[addr][8*(2+1)-1:8*2] <= BRAM_WRDATA[8*(2+1)-1:8*2];
            if(BRAM_WE[3] == 1) mem[addr][8*(3+1)-1:8*3] <= BRAM_WRDATA[8*(3+1)-1:8*3];
            end
        end
    end
endmodule
