#Purpose: simulate the addition of 2 positive integers whom value added together isn't greater than 256


.section .data

.section .text
.globl _start
_start:
	pushl $25
	pushl $32
	call addition
	movl %eax, %ebx
	addl $8, %esp

	movl $1, %eax
	int $0x80


.type addition, @function

addition:
	
	push %ebp
	movl %esp, %ebp
	
	movl 12(%ebp),%ecx
	movl 8(%ebp),%eax

	addl %ecx, %eax

	movl %ebp, %esp
	popl %ebp
	ret
