#Purpose to check where %ebp and %esp originally point 



.section .text
.globl _start
_start:
	pushl $2
	movl $1, %eax
	movl (%ebp), %ebx
	int $0x80
