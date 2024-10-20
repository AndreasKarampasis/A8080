; Program to add two numbers in memory and store the result
START:  LXI H, 2000H    ; Load memory address 2000h into HL
        MOV A, M         ; Move the value at memory address 2000h into A
        INX H            ; Increment HL to point to the next memory address (2001h)
        ADD M            ; Add the value at memory address 2001h to A
        INX H            ; Increment HL to point to the result storage location (2002h)
        MOV M, A         ; Store the result in memory address 2002h
        HLT              ; Halt the program
