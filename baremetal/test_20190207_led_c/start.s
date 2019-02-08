.text
.global _start

_start:
	ldr r0, =0x53000000
	ldr r1, =0
	str r1, [r0]


	mov r1, #0
	ldr r0, [r1] 
	
	str r1, [r1]
	ldr r2, [r1]
	cmp r1, r2
	ldr sp, =0x40000000+4096

	moveq sp, #4096


	streq r0, [r1] /*recover*/

	bl main

_loop:
	b _loop



