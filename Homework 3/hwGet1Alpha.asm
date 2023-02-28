		.orig x3000
		LEA R0, PROMPT
		PUTS
		JSR GETALPHA ;Each call to GETALPHA gets one character
		JSR GETALPHA ;Callingit again gets a second character
		HALT
PROMPT	.stringz "Enter two letters: " ;Note there MUST be a space at the end
GETALPHA	ST R1, One
		ST R6, Six
		ST R7, Seven
GET		GETC
		ADD R1,R0, #-10
		BRZ END
		LD R1, NinFi
		ADD R6,R0,R1
		BRZ PRINT
		LD R1, SiFi
		ADD R6,R0,R1
		BRN GET
		LD R1, NinT
		ADD R6,R0,R1
		BRNZ PRINT
		LD R1, NinTS
		ADD R6,R0,R1
		BRN GET
		LD R1, OnTo
		ADD R6,R0,R1
		BRNZ PRINT	
		BRNZP GET
PRINT		OUT
END		LD R1, One
		LD R6, Six
		LD R7, Seven
		RET
One	.fill	0
Six	.fill	0
Seven	.fill	0
SiFi	.fill	-65
NinT	.fill -90
NinFi	.fill -95
NinTS	.fill -97
OnTo	.fill -122
