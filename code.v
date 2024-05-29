module floor_decider(
    input  [1:0] NextStopDirection, 
    input  [2:0] NextFloor, FinalFloor, currFloor, 
    input  [3:0] DirectionUp, DirectionDown,
    input  [4:0] Floors,
    output reg [1:0] temp_NextStopDirection, 
    output reg [2:0] temp_NextFloor, temp_FinalFloor, 
    input clk, reset
);

parameter UP_DIRECTION = 2'b10;
parameter DOWN_DIRECTION = 2'b01;
parameter REST = 2'b00;
integer i;
integer flag, flag2, flag3;


always @(posedge clk)
begin
    if(!reset)
    begin
        if(temp_FinalFloor == currFloor) temp_NextStopDirection = REST;
        
        if(temp_NextStopDirection == REST)
        begin
            flag = 1;
            for(i = 0; i < 5; i = i+1)
            begin
                if(i >= currFloor) flag = 0;
                if(Floors[i] == 1 && flag == 1)
                begin
                    if(temp_FinalFloor == currFloor) temp_FinalFloor = i;
                    temp_NextFloor = i;
                    temp_NextStopDirection = DOWN_DIRECTION;
                end
            end
            flag = 1;
            for(i = 4; i >= 0; i = i-1)
            begin
                if(i <= currFloor) flag = 0;
                if(Floors[i] == 1 && flag == 1)
                begin
                    if(temp_FinalFloor == currFloor) temp_FinalFloor = i;
                    temp_NextFloor = i;
                    temp_NextStopDirection = UP_DIRECTION;
                end 
            end


            if(temp_FinalFloor == currFloor)
            begin
                flag2 = 0;
                flag = 1;
                for(i = 0; i<5; i = i+1)
                begin
                    if(i >= currFloor) flag = 0;
                    if(flag == 1 && (i<4 && DirectionUp[i] == 1) || (i>0 && DirectionDown[i-1] == 1)) 
                    begin
                        temp_NextFloor = i;
                        temp_FinalFloor = i;
                        if(i != currFloor) temp_NextStopDirection = DOWN_DIRECTION;
                        flag2 = 1;
                    end
                end
                flag = 0;
                flag3 = 0;
                for(i = 0; i <5; i = i+1)
                begin
                    if(i> currFloor) flag = 1;
                    if(flag == 1 && (i<4 && DirectionUp[i] == 1) || (i>0 && DirectionDown[i-1] == 1) && flag3 == 0) 
                    begin
                        if(!flag2 || (i-currFloor) < (currFloor - temp_NextFloor)) 
                        begin
                            temp_NextFloor = i;
                            temp_FinalFloor = i;
                            temp_NextStopDirection = UP_DIRECTION;
                            flag3 = 1;
                        end
                    end
                end
            end
        end



        if(temp_NextStopDirection == UP_DIRECTION && (temp_FinalFloor == 4 || (temp_FinalFloor<4 && (DirectionUp[temp_FinalFloor] == 1 || Floors[temp_FinalFloor] == 1))))
        begin
            flag = 0;
            for(i = 0; i<5; i = i+1)
            begin
                if(i == currFloor) flag = 1;
                if(flag == 1 && ((DirectionUp[i] == 1) || (Floors[i] == 1)))
                begin
                    temp_NextFloor = i;
                    flag = 0;
                end
                if(i == temp_FinalFloor) flag = 0;

            end
        end


        if(temp_NextStopDirection == DOWN_DIRECTION && (temp_FinalFloor==0 || (temp_FinalFloor>0 && (DirectionDown[temp_FinalFloor-1] == 1 || Floors[FinalFloor] == 1))))
        begin
            flag = 0;
            for(i = 4; i >= 0; i = i-1)
            begin
                if(i == currFloor) flag = 1;
                if(flag == 1 && ((DirectionDown[i-1] == 1) || (Floors[i] == 1)))
                begin
                    temp_NextFloor = i;
                    flag = 0;
                end
                if(i == temp_FinalFloor) flag = 0;
            end
        end
    end

    else
    begin
        temp_FinalFloor = 0; temp_NextFloor = 0; temp_NextStopDirection = 0;
    end

end

endmodule




module fsm(
    input  [3:0] DirectionUp, DirectionDown,
    input  [4:0] Floors, //[fl5, fl4, fl3, fl2, fl1, fl0]  request for Floors 5, 4, 3, 2, 1, ground respectively.  
    input clk,reset, // clock
    output reg [1:0] NextStopDirection, //The lift will move in up/down direction in next clock; 10 means up, 01 means down and 00 implies it will stay in the current Floors and 11 is invalid. 
    output reg [2:0] NextFloor // next stop of the lift
    
);

parameter UP_DIRECTION = 2'b10;
parameter DOWN_DIRECTION = 2'b01;
parameter REST = 2'b00;


reg [3:0] pressed_DirecUp, pressed_DirecDown;
reg[4:0] pressed_Floors;

wire [1:0] temp_NextStopDirection;
wire [2:0] temp_NextFloor, temp_FinalFloor;

reg [2:0] currFloor;
reg [2:0] FinalFloor;
reg [2:0] clk_counter;

reg [4:0] cState=0, nState=0;

always @(posedge clk)
begin
    pressed_DirecDown = pressed_DirecDown | DirectionDown;
    pressed_DirecUp = pressed_DirecUp | DirectionUp;
    pressed_Floors = pressed_Floors | Floors;
end

always @(posedge clk)
begin
    if(reset) 
    begin
        cState = 0; clk_counter = 0; 
        pressed_Floors = 0; pressed_DirecDown = 0; pressed_DirecUp = 0; 
    end
    else cState = nState;
end

always @(temp_FinalFloor, temp_NextFloor, temp_NextStopDirection)
begin
    NextFloor <= temp_NextFloor;
    FinalFloor <= temp_FinalFloor;
    NextStopDirection <= temp_NextStopDirection;
end


floor_decider fd(NextStopDirection, NextFloor, FinalFloor, currFloor, pressed_DirecUp, pressed_DirecDown, pressed_Floors, temp_NextStopDirection, temp_NextFloor, temp_FinalFloor, clk, reset);


always @(posedge clk)
begin
    if(cState == 1 ||cState == 2 ||cState == 4 || cState == 5 ||cState == 7 ||cState == 8 ||cState == 10 ||cState == 11)
    clk_counter = clk_counter + 1;
    else clk_counter = 0;
    if(clk_counter == 4) clk_counter = 0;
end 

always @(cState, clk_counter, FinalFloor, NextFloor, pressed_DirecDown, pressed_DirecUp, pressed_Floors)
begin
    case (cState)
        0: 
            begin
               currFloor = 0;
               pressed_DirecUp[0] = 0;
               pressed_Floors[0] = 0;   
               if(NextStopDirection == UP_DIRECTION) nState = 1;
               else nState = 0;
            end
        1: 
            begin
                currFloor = 0;
                if(clk_counter == 3)
                begin
                    currFloor = 1;
                    if(NextFloor == 1) nState = 3;
                    else nState = 4;
                end
                else 
                begin
                    nState = 1;                    
                end
            end
        2:
            begin
                currFloor = 1;
                if(clk_counter == 3)
                begin
                    currFloor = 0;
                    nState = 0;
                end
                else 
                begin
                    nState = 2;
                end
            end
        3: 
            begin
                    
               currFloor = 1; 
               pressed_DirecDown[0] = 0;
               pressed_DirecUp[1] = 0;
               pressed_Floors[1] = 0;
               if(FinalFloor == currFloor) NextStopDirection = REST;
               if(NextStopDirection == UP_DIRECTION) nState = 4;
               else if(NextStopDirection == DOWN_DIRECTION) nState = 2;
               else nState = 3;
            end
        4: 
            begin
                currFloor = 1;
                if(clk_counter == 3)
                begin
                    currFloor = 2;
                    if(NextFloor == 2) nState = 6;
                    else nState = 7;
                end
                else 
                begin
                    nState = 4;                    
                    
                end
            end
        5: 
            begin
                currFloor = 2;
                if(clk_counter == 3)
                begin
                    currFloor = 1;
                    if(NextFloor == 1) nState = 3;
                    else nState = 2;
                end
                else 
                begin
                    nState = 5;
                    
                end
            end
        6: 
            begin
               currFloor = 2; 
               pressed_DirecDown[1] = 0;
               pressed_DirecUp[2] = 0;
               pressed_Floors[2] = 0;
               if(NextStopDirection == UP_DIRECTION) nState = 7;
               else if(NextStopDirection == DOWN_DIRECTION) nState = 5;
               else nState = 6;
            end
        7: 
            begin
                currFloor = 2;
                if(clk_counter == 3)
                begin
                    currFloor = 3;
                    if(NextFloor == 3) nState = 9;
                    else nState = 10;
                end
                else 
                begin
                    nState = 7;                    
                    
                end
            end
        8: 
            begin
                currFloor = 3;
                if(clk_counter == 3)
                begin
                    currFloor = 2;
                    if(NextFloor == 2) nState = 6;
                    else nState = 5;
                end
                else 
                begin
                    nState = 8;
                    
                end
            end
        9: 
            begin
               currFloor = 3; 
               pressed_DirecDown[2] = 0;
               pressed_DirecUp[3] = 0;
               pressed_Floors[3] = 0;
               if(NextStopDirection == UP_DIRECTION) nState = 10;
               else if(NextStopDirection == DOWN_DIRECTION) nState = 8;
               else nState = 9;
            end
        10: 
            begin
                currFloor = 3;
                if(clk_counter == 3)
                begin
                    currFloor = 4;
                    nState = 12;
                end
                else 
                begin
                    nState = 10;                    
                    
                end
            end
        11: 
            begin
                currFloor = 4;
                if(clk_counter == 3)
                begin
                    currFloor = 3;
                    if(NextFloor == 3) nState = 9;
                    else nState = 8;
                end
                else 
                begin
                    nState = 11;
                    
                end
            end
        12: 
            begin
               currFloor = 4; 
               pressed_DirecDown[3] = 0;
               pressed_Floors[4] = 0;
               if(NextStopDirection == DOWN_DIRECTION) nState = 11;
               else nState = 12;
            end
        
    endcase
        
end

endmodule



module liftdisplay(
    input [3:0] DirectionUp, DirectionDown,
    input  [4:0] Floors, //[fl5, fl4, fl3, fl2, fl1, fl0]  request for Floors 5, 4, 3, 2, 1, ground respectively.  
    input clk,reset, // clock
    output [1:0] NextStopDirection, //The lift will move in up/down direction in next clock; 10 means up, 01 means down and 00 implies it will stay in the current Floors and 11 is invalid. 
    output [2:0] NextFloor // next stop of the lift
    );
    
   fsm ctl(DirectionUp, DirectionDown, Floors, clk, reset, NextStopDirection, NextFloor);


endmodule
