	.orig x3000
	NOT R2, R1
	ADD R2, R2, #1
L2	ADD R3, R2, R0
	BRP L1
	OUT
	ADD R0, R0, #1
	BRNZP L2
L1	HALT	

		