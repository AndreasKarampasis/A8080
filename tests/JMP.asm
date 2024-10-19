    JMP FORWARD      ; Jump forward to the FORWARD label

BACKWARD:
    MVI A, 01H      ; Load 0x01 into register A (can be used for debugging)
    HLT             ; Halt the processor

FORWARD:
    MVI A, 02H      ; Load 0x02 into register A (can be used for debugging)
    JMP BACKWARD    ; Jump backward to the BACKWARD label
