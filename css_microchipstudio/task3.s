; In this case we sort an array in ascending order, delete strings 3 and 4 to sort array in descending order

ldi r16, (1 << 6)  ; Load the bitmask into a temporary register r16
or r0, r16         ; Set the 7th bit of r0

; Store numbers in registers r1-r10
ldi r18, 20
ldi r19, 20
ldi r20, 20
ldi r21, 20
ldi r22, 20
ldi r23, 20
ldi r24, 20
ldi r25, 20
ldi r26, 20
ldi r27, 20

; Check if the 7th bit of R0 is set or cleared
sbrs r0, 6  ; Skip the next instruction if bit 7 of R0 is set
rjmp cv_is_clear ; If bit is not set, jump to cv_is_clear

; If CV=1 (bit is set), sort in ascending order
rjmp sort_ascending

cv_is_clear: ; If CV=0 (bit is not set), sort in descending order
rjmp sort_descending

; Ascending sorting
sort_descending:

.def temp = r28 ; Temporary register for swapping

    loop_descending:
	ldi r29, 9 ; Loop counter
    ; Get the first number in the pair
    mov temp, r18
    cp temp, r19 ; Compare with the next number
    brsh no_swap ; If first is >= second, don't swap
    ; Swap
    mov r18, r19
    mov r19, temp




    no_swap:
    mov temp, r19
    cp temp, r20 ; Compare with the next number
    brsh no_swap0 ; If first is >= second, don't swap
    ; Swap
    mov r19, r20
    mov r20, temp

	no_swap0:
	    ; Get the first number in the pair
    mov temp, r20
    cp temp, r21 ; Compare with the next number
    brsh no_swap1 ; If first is >= second, don't swap
    ; Swap
    mov r20, r21
    mov r21, temp

	no_swap1:
	    ; Get the first number in the pair
    mov temp, r21
    cp temp, r22 ; Compare with the next number
    brsh no_swap2 ; If first is >= second, don't swap
    ; Swap
    mov r21, r22
    mov r22, temp

	no_swap2:
	    ; Get the first number in the pair
    mov temp, r22
    cp temp, r23 ; Compare with the next number
    brsh no_swap3 ; If first is >= second, don't swap
    ; Swap
    mov r22, r23
    mov r23, temp

	no_swap3:
	    ; Get the first number in the pair
    mov temp, r23
    cp temp, r24 ; Compare with the next number
    brsh no_swap4 ; If first is >= second, don't swap
    ; Swap 
    mov r23, r24
    mov r24, temp

	no_swap4:
	    ; Get the first number in the pair
    mov temp, r24
    cp temp, r25 ; Compare with the next number
    brsh no_swap5 ; If first is >= second, don't swap
    ; Swap
    mov r24, r25
    mov r25, temp

	no_swap5:
		    ; Get the first number in the pair
    mov temp, r25
    cp temp, r26 ; Compare with the next number
    brsh no_swap6 ; If first is >= second, don't swap
    ; Swap
    mov r25, r26
    mov r26, temp

	no_swap6:
		    ; Get the first number in the pair
    mov temp, r26

    cp temp, r27 ; Compare with the next number
    brsh no_swap7 ; If first is >= second, don't swap
    ; Swap
    mov r26, r27
    mov r27, temp

	no_swap7:

	dec r29
	brne loop_descending
; Sorting complete

rjmp end_sort

; Ascending order
sort_ascending:

    loop_ascending:
	ldi r29, 9 ; Loop counter
    ; Get the first number in the pair
    mov temp, r18
    cp temp, r19 ; Compare with the next number
    brlo no_swap8 ; If first is < second, don't swap
    ; Swap
    mov r18, r19
    mov r19, temp

    no_swap8:
    mov temp, r19
    cp temp, r20 ; Compare with the next number
    brlo no_swap9 ; If first is < second, don't swap
    ; Swap
    mov r19, r20
    mov r20, temp

	no_swap9:
	    ; Get the first number in the pair
    mov temp, r20
    cp temp, r21 ; Compare with the next number
    brlo no_swap10 ; If first is < second, don't swap
    ; Swap
    mov r20, r21
    mov r21, temp

	no_swap10:
	    ; Get the first number in the pair
    mov temp, r21
    cp temp, r22 ; Compare with the next number
    brlo no_swap11 ; If first is < second, don't swap
    ; Swap
    mov r21, r22
    mov r22, temp






	no_swap11:
	    ; Get the first number in the pair
    mov temp, r22
    cp temp, r23 ; Compare with the next number
    brlo no_swap12 ; If first is < second, don't swap
    ; Swap
    mov r22, r23
    mov r23, temp

	no_swap12:
	    ; Get the first number in the pair
    mov temp, r23
    cp temp, r24 ; Compare with the next number
    brlo no_swap13 ; If first is < second, don't swap
    ; Swap 
    mov r23, r24
    mov r24, temp

	no_swap13:
	    ; Get the first number in the pair
    mov temp, r24
    cp temp, r25 ; Compare with the next number
    brlo no_swap14 ; If first is < second, don't swap
    ; Swap
    mov r24, r25
    mov r25, temp

	no_swap14:
		    ; Get the first number in the pair
    mov temp, r25
    cp temp, r26 ; Compare with the next number
    brlo no_swap15 ; If first is < second, don't swap
    ; Swap
    mov r25, r26
    mov r26, temp

	no_swap15:
		    ; Get the first number in the pair
    mov temp, r26
    cp temp, r27 ; Compare with the next number
    brlo no_swap16 ; If first is < second, don't swap
    ; Swap
    mov r26, r27
    mov r27, temp

	no_swap16:

	dec r29
	brne loop_ascending

; Sorting complete

rjmp end_sort

end_sort:
; End of sorting
nop ; End of program
