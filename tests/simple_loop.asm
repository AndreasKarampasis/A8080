; Program to fill memory with a constant value
LXI H, 3000H        ; Start address to fill
MVI B, 10H          ; Counter: fill 16 bytes
MVI A, 0FFH         ; The value to fill memory with

LOOP:  MOV M, A ; Move the value from A into the memory at HL
            INX H    ; Increment HL to point to the next memory location
            DCR B    ; Decrement counter
            JNZ LOOP ; If B != 0, repeat the loop

HLT                  ; Halt the program
