#Purpose: again writing a power function for recitation


.section .data

.section .text

.globl _start
.globl power

_start:
	pushl $2
	pushl $5
	call power
	addl $8, %esp
	movl %eax, %ebx

	movl $1, %eax
	int $0x80


power:
	pushl %ebp
	movl %esp, %ebp
	movl 12(%ebp), %ebx
	movl 8(%ebp), %ecx
	movl $1, %eax	
	start_loop:
	cmpl $0, %ebx
	je end_power
	decl %ebx
	imull %ecx, %eax
	jmp start_loop
end_power:
	movl %ebp, %esp
	popl %ebp
	ret
