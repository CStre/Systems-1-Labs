	.orig x3000
	NOT R2, R1
	ADD R2, R2, #1
	ADD R2, R2, R0
	BRN L1 		;Jump to L1 if R1 > R0
	BRNZP END
L1	ADD R2, R0, #0	;Move R0 to R2
	ADD R0, R1, #0	;Move R1 to R0
	ADD R1, R2, #0	;Move R2 to R1
	
END	HALT
