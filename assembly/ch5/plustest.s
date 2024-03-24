#Purpose: curiosity regarding how + and - works


.section .data


.equ LINUX_SYSCALL, 0x80
.section .text


.globl _start

_start:
	.equ Szar, 5+'a'
	movl $Szar, %ebx

	movl $1, %eax
	int $LINUX_SYSCALL
	
