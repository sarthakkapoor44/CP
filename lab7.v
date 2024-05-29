`timescale 1ns / 1ps

module sort_system(
    input wire clk,
    input wire reset,
    input wire dataValid,
    input wire [3:0] wAddress,
    input wire [5:0] dataIn,
    output reg outValid,
    output wire [3:0] outAddress,
    output wire [5:0] dataOut
);

// Internal signals
reg write_enable = 0;
reg read_enable = 0;
reg [3:0] internal_address;
reg [5:0] internal_data;
wire [5:0] memory_data_out; // Output from memory
reg sorting_done = 0;
reg [3:0] read_counter = 0;
reg [3:0] data_count = 0;
// reg [15:0] valid_address = 0;

reg [3:0] first_valid_index = 0;
reg [4:0] cState=19, nState=19;
reg [5:0] minval;
reg [3:0] minreg = 4'b0000;
reg [5:0] tempreg;

// reg flag = 0;



// Instantiate the memory module
memory_module mem (
    .clk(clk),
    .write_enable(write_enable),
    .read_enable(read_enable),
    .address(internal_address),
    .data_in(internal_data),
    .data_out(memory_data_out)
);

always @(posedge clk) 
begin
    if (reset) begin
        data_count <= 0;
        sorting_done <= 0;
        outValid<=0;
        read_counter <= 0;
        cState <= 19;
        nState <= 19;
        write_enable <= 0; // Ensure write_enable is low after reset
        minval <= 6'b111111;
        minreg <= 4'b0000;
        first_valid_index <= 0;
    end
    else if (dataValid && !sorting_done) 
    begin
       // Enable writing when dataValid is high
        internal_address <= wAddress;
         write_enable <= 1; 
        internal_data <= dataIn;
        data_count <= data_count + 1;
   
        minval <= 6'b111111;
        read_enable<=0;
    end
    else  if (sorting_done && read_counter < data_count) begin
         
                read_enable <= 1;
                outValid<=1;
                internal_address <= read_counter; // Sequentially read out sorted data
           
            read_counter <= read_counter + 1;
       end else begin
           read_enable <= 0;
       end
       cState <= nState;

       $monitor ("time: %d:: fvi: %b, minval: %b, minreg: %b , cState: %b, mdo: %d, internal address: %b", $time, first_valid_index, minval, minreg, cState, memory_data_out, internal_address);
end



always @(cState, dataValid)
begin
if(data_count>0 && !dataValid && !sorting_done)
    begin
        cState = nState;
        case (cState)
            0:
            begin
                if(first_valid_index == 0)
                begin
                    minreg = 0;
                    minval = memory_data_out;
                end
                else if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 0;
                end
                if(data_count == 1) nState = 16;
                else begin
                    read_enable = 1;
                    internal_address = 1;
                    nState = 1;
                end
            end
            1:
            begin
                if(first_valid_index == 1)
                begin
                    minreg = 1;
                    minval = memory_data_out;
                end
                else if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 1;
                end
                if(data_count == 2) nState = 16;
                else begin
                    internal_address = 2;
                    read_enable = 1;
                    nState = 2;
                end
            end
            2:
            begin
                if(first_valid_index == 2)
                begin
                    minreg = 2;
                    minval = memory_data_out;
                end
                else if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 2;
                end
                if(data_count == 3) nState = 16;
                else begin
                    nState = 3;
                    read_enable = 1;
                    internal_address = 3;
                end
            end 
            3:
            begin
                if(first_valid_index == 3)
                begin
                    minreg = 3;
                    minval = memory_data_out;
                end
                else if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 3;
                end
                read_enable = 1;
                internal_address = 4;
                if(data_count == 4) nState = 16;
                else nState = 4;
            end
            4:
            begin
                if(first_valid_index ==4)
                begin
                    minreg =4;
                    minval = memory_data_out;
                end
                else if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg =4;
                end
                read_enable = 1;
                internal_address = 5;
                if(data_count == 5) nState = 16;
                else nState = 5;
            end
            5:
            begin
                if(first_valid_index == 5)
                begin
                    minreg = 5;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 5;
                end
                read_enable = 1;
                internal_address = 6;
                if(data_count == 6) nState = 16;
                else nState = 6;
            end
            6:
            begin
                if(first_valid_index == 6)
                begin
                    minreg = 6;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 6;
                end
                read_enable = 1;
                internal_address = 7;
                if(data_count == 7) nState = 16;
                else nState = 7;
            end
            7:
            begin
                if(first_valid_index == 7)
                begin
                    minreg = 7;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 7;
                end
                read_enable = 1;
                internal_address = 8;
                if(data_count == 8) nState = 16;
                else nState = 8;
            end
            8:
            begin
                if(first_valid_index == 8)
                begin
                    minreg = 8;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 8;
                end
                read_enable = 1;
                internal_address = 9;
                if(data_count == 9) nState = 16;
                else nState = 9;
            end
            9:
            begin
                if(first_valid_index == 9)
                begin
                    minreg = 9;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 9;
                end
                read_enable = 1;
                internal_address = 10;
                if(data_count == 10) nState = 16;
                else nState = 10;
            end
            10:
            begin
                if(first_valid_index == 10)
                begin
                    minreg = 10;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 10;
                end
                read_enable = 1;
                internal_address = 11;
                if(data_count == 11) nState = 16;
                else nState = 11;
            end
            11:
            begin
                if(first_valid_index == 11)
                begin
                    minreg = 11;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 11;
                end
                read_enable = 1;
                internal_address = 12;
                if(data_count == 12) nState = 16;
                else nState = 12;
            end
            
            12:
            begin
                if(first_valid_index ==12)
                begin
                    minreg =12;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg =12;
                end
                read_enable = 1;
                internal_address =13;
                if(data_count == 13) nState = 16;
                else nState = 13;
            end
            13:
            begin
                if(first_valid_index == 13)
                begin
                    minreg = 13;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 13;
                end
                read_enable = 1;
                internal_address = 14;
                if(data_count == 14) nState = 16;
                else nState = 14;
            end
            14:
            begin
                if(first_valid_index == 14)
                begin
                    minreg = 14;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 14;
                end
                read_enable = 1;
                internal_address = 15;
                if(data_count == 15) nState = 16;
                else nState = 15;
            end
            15:
            begin
                if(first_valid_index == 15)
                begin
                    minreg = 15;
                    minval = memory_data_out;
                end
                if(minval > memory_data_out)
                begin
                    minval = memory_data_out;
                    minreg = 15;
                end
                // read_enable = 1;
                // internal_address = 15;
                nState = 16;

            end   

            16: //swap state
            begin
                // swap(minreg,fvi);
                read_enable = 1;
                internal_address = first_valid_index;
                tempreg = memory_data_out;
                nState = 17;
            end

            17:
            begin
                read_enable = 0;
                internal_address = first_valid_index;
                internal_data = minval;
                write_enable = 1;
                nState = 18;
            end

            18:
            begin
                internal_address = minreg;
                internal_data = tempreg;
                write_enable = 1;

                first_valid_index= first_valid_index+1;
                if(first_valid_index == data_count) 
                begin sorting_done=1; end 
                else nState = first_valid_index;
                internal_address = first_valid_index;
                
            end
            19: //start state
            begin
                write_enable=0;
                internal_address = 0;
                read_enable =1;
                minval = 6'b111111;
                minreg = 0;
                nState = 0;
            end
        endcase
    end
end


assign dataOut = memory_data_out;
assign outAddress = internal_address;

endmodule

module memory_module(
    input wire clk,
    input wire write_enable,
    input wire read_enable,
    input wire [3:0] address,
    input wire [5:0] data_in,
    output reg [5:0] data_out
);

// Define the memory storage
reg [5:0] memory_storage [0:15]; // 16 locations, each 6 bits wide

always @(posedge clk, read_enable, write_enable, address) begin
    if (write_enable) begin
        // Write data to memory
        memory_storage[address] <= data_in;
    end
    if (read_enable) begin
        // Read data from memory
        data_out <= memory_storage[address];
    end
end

endmodule



                
module sort_system_tb;

// Inputs
reg clk;
reg reset;
reg dataValid;
reg [3:0] wAddress;
reg [5:0] dataIn;

// Outputs
wire outValid;
wire [3:0] outAddress;
wire [5:0] dataOut;

// Instantiate the Unit Under Test (UUT)
sort_system uut (
    .clk(clk), 
    .reset(reset), 
    .dataValid(dataValid), 
    .wAddress(wAddress), 
    .dataIn(dataIn), 
    .outValid(outValid), 
    .outAddress(outAddress), 
    .dataOut(dataOut)
);

initial 
begin
    // Initialize Inputs
    clk = 0;
    reset = 1;
    dataValid = 0;
    wAddress = 0;
    dataIn = 0;

    // Wait 100 ns for global reset to finish
    #100;
    reset = 0; // Release reset
    
    // Add stimulus here
    // Example: write some unsorted data
    
    #20    dataValid = 1; wAddress = 0; dataIn = 6'd15;
    
    #20
        dataValid = 1; wAddress = 1; dataIn = 6'd3;
    
   #20
        dataValid = 1; wAddress = 2; dataIn = 6'd8;
  
    // Continue for more data points...
    // Finish writing data
    #20
        dataValid = 0;
    
    #1000 $finish;
    
end


// Clock generation
always #10 clk = !clk;

endmodule

                
i