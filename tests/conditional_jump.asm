; Program to compare two numbers
LXI H, 4000H         ; Load address 4000h into HL
MOV A, M             ; Load the value from memory address 4000h into A
INX H                ; Increment HL to point to the next memory address (4001h)
CMP M                ; Compare the value in A with the value at 4001h

JZ EQUAL             ; Jump to EQUAL if A == memory[4001h]
JC LESS              ; Jump to LESS if A < memory[4001h]
JMP GREATER          ; Jump to GREATER if A > memory[4001h]

EQUAL:  MVI A, 01H   ; Load 1 into A (indicating equality)
        JMP EXIT

LESS:   MVI A, 02H   ; Load 2 into A (indicating A < memory[4001h])
        JMP EXIT

GREATER: MVI A, 03H  ; Load 3 into A (indicating A > memory[4001h])

EXIT:    HLT          ; Halt the program
