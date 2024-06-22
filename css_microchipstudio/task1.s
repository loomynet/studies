; Task 1: Load values into registers
ldi r16, 0x10    ; Load hexadecimal value 10 into r16 (since r10 cannot be used with ldi)
ldi r17, 128     ; Load decimal value 128 into r17 (since r11 cannot be used with ldi)

; Task 2: Add with carry
add r16, r17     ; Add r17 to r16
brcc no_carry    ; If no carry, skip the next instruction
inc r29          ; Increment r29 to indicate a carry occurred
no_carry:

; Task 3: Copy the result to r28 and r1
mov r28, r16     ; Copy the result to r28
mov r1, r16      ; Copy the result to r1

; Task 4: Subtract without carry
sub r28, r29     ; Subtract r29 from r28
mov r2, r28      ; Copy the result to r2

; Task 5: Set all bits of r16 to the value of r1
mov r16, r1      ; Copy r1 to r16, effectively setting all bits of r16 to the value of r1

; Task 6: Logical XOR operation
eor r16, r28     ; Perform XOR operation between r16 and r28
mov r3, r16      ; Copy the result to r3

; Task 7: Clear all registers except r1, r2, and r3
clr r16
clr r17
clr r29
clr r28

; End of program
