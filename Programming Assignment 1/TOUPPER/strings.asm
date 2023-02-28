	.orig x3000
	JSR TOUPPER
	JSR TOUPPER ;Yes call it twice.
	PUTS
	HALT
;*************************SUBROUTINES*******************************

TOUPPER
	ST R1, LoD_1
	ST R2, LoD_2
	ST R3, LoD_3
	ST R4, LoD_4
	ADD R4, R0, #0
	LDR R2, R0, #0
MOOP 

	LD R1, DOWN 
	ADD R1, R1, R2 
	BRN GOOD

	LD R1, UP 
	ADD R1, R1, R2 
	BRP GOOD

	LD R1, CHAN 
	ADD R1, R1, R2
	STR R1, R0, #0

GOOD
	ADD R0, R0, #1
	LDR R2, R0, #0
	BRZ LEAVE
	BRNZP MOOP

LEAVE	
	LD R1, LoD_1
	LD R2, LoD_2
	LD R3, LoD_3
	ADD R0, R4, #0
	LD R4, LoD_4

	RET
	
LoD_1 .fill	#0
LoD_2 .fill	#0
LoD_3 .fill	#0
LoD_4 .fill	#0
DOWN	.fill	#-97
UP	.fill	#-122
CHAN	.fill	#-32


