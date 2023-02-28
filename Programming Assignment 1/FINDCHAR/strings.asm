	.orig x3000
	JSR FINDCHAR
	HALT

FINDCHAR
	ST R0, SR_0
	ST R1, SR_1
	ST R2, SR_2
	ST R3, SR_3
	ADD R3, R1, #0
	NOT R0, R0
	ADD R0, R0, #1
TOP
	LDR R2, R1, #0 ; Load the register with value from memory
	BRZ NONE
	ADD R2, R2, R0
	BRZ END	
	ADD R1, R1, #1
	BRNZP TOP

NONE
	LD R0, SR0
	BRNZP AEND

END
	NOT R3, R3
	ADD R3, R3, R1
	ADD R0, R3, #1
	
	
AEND
	LD R1, SR_1
	LD R2, SR_2
	LD R3, SR_3
	RET
	
SR0 	.fill #-1
SR_0	.fill #0
SR_1	.fill #0
SR_2	.fill #0
SR_3	.fill #0	
