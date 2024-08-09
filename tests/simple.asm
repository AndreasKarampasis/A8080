; This is a simple Intel 8080 program

START:          ; Label definition
    MVI A, 0x00 ; Load immediate value 0x00 into register A
    MVI B, 0x01 ; Load immediate value 0x01 into register B
    ADD B       ; Add the value of register B to register A
    JNZ START   ; Jump to START if the result is not zero
    HLT         ; Halt the processor
