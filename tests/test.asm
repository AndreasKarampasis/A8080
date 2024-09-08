HERE:   MVI C, 0    ; Load the C register with 0
THERE:  DB  34      ; Create a one byte data constant
LOOP:   ADD E       ; Add contents of E register to the accumulator
        RLC         ; Rotate the accumulator left
