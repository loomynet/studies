; Load the control value into r16 (For example, 0)
ldi r16, 0 ; 'X' register, control variable

; Initialize array values in registers
ldi r20, 1 
ldi r21, 2 
ldi r22, 3 
ldi r23, 4 
ldi r24, 5 
ldi r25, 6 
ldi r26, 7
ldi r27, 8 
ldi r28, 9 
ldi r29, 10

; Initialize sum to 0
clr r18  ; Sum register

; Depending on r16, jump to the corresponding routine
cpi r16, 0
breq TOTAL_SUM ; Jump if r16 is equal 0
cpi r16, 1
breq FIRST_FIVE_SUM ; Jump if r 16 is equal to 1
cpi r16, 2
breq LAST_FIVE_SUM ; Jump if r 16 is equal to 3
rjmp END_PROGRAM ; If r16 is any other value, halt







; TOTAL_SUM routine
TOTAL_SUM:
	add r18, r20
	add r18, r21
	add r18, r22
	add r18, r23
	add r18, r24
	add r18, r25
	add r18, r26
	add r18, r27
	add r18, r28
	add r18, r29
    rjmp END_PROGRAM ; Jump to end

; FIRST_FIVE_SUM routine
FIRST_FIVE_SUM:
	add r18, r20
	add r18, r21
	add r18, r22
	add r18, r23
	add r18, r24
    rjmp END_PROGRAM ; Jump to end

; LAST_FIVE_SUM routine
LAST_FIVE_SUM:
	add r18, r25
	add r18, r26
	add r18, r27
	add r18, r28
	add r18, r29
    rjmp END_PROGRAM ; Jump to end

; End of program
END_PROGRAM:
    nop             ; No operation (halt)
