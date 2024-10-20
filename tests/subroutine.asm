; Program to call a subroutine that increments a value in A
MVI A, 05H         ; Load 5 into A
CALL INCREMENT     ; Call the subroutine to increment A
HLT                ; Halt the program

INCREMENT:  INR A  ; Increment the value in A
            RET    ; Return from the subroutine
