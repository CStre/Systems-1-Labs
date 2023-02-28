	.orig x3000
	JSR FINDLAST
	HALT

FINDLAST
	ST R0, SR0
	ST R1, SR1
TOP
	LDR R1, R0, #0
	BRZ END
	ADD R0, R0, #1
	BRNZP TOP
END
	ADD R0, R0, #-1
	LD R1, SR1
	RET
	.blkw 100 ;Change this value when testing between 50 and 150.
STR1 	.stringz ""
SR0	.fill #0 
SR1 	.fill #0
