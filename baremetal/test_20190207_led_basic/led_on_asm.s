/*turn on the led:gpf4*/

/*configure the GPF4 to be output port*set 0x56000050 to be 0x100**********/


.text
.global _start



_start:
	ldr r1, =0x56000050
	mov r0, #0x100 /*ldr r0, =0x100*/
	str r0, [r1]

/*set GPF4 to HIGHset 0x10 to 0x56000054*/

	ldr r1, =0x56000054
	ldr r0, =0x0 /*mov r0 #0*/
	str r0, [r1]
_halt:
	b _halt

