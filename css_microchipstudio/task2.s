; Subtract r2 from r1 and store the result in r3
mov r4, r2    ; Load r2 into accumulator (r4)
sub r4, r1    ; Subtract r1 from accumulator (r4)
mov r3, r4    ; Move result to r3

; Check if the result is negative and set r4 accordingly
tst r3       ; Test for negative result by checking r3
brpl is_positive	 
inc r4      ; If negative, set r4 to 1
rjmp end_check
is_positive:
clr r4         ; If positive or zero, set r4 to 0
end_check:

; Based on r4, swap the numbers if necessary
tst r4         ; Test r4 value
breq no_swap  ; If r4 is zero, no need to swap
; Swap values
mov r5, r1   ; Move r1 to temporary storage, which is r5 in this case
mov r1, r2      ; Move r2 to r1
mov r2, r5   ; Move r5 to r2
no_swap:

; End of program 
nop           ; No operation, effectively halts the CPU