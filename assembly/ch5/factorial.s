#Purpose is still recitation, after a week hiatus from assembly




.section .data

.section .text

.equ SYSEXIT, 1
.equ SYSINTERRUPT, 0x80


.globl _start
.globl factorial

_start:
	pushl $4
	call factorial
	addl $4, %esp
	movl %eax, %ebx
	movl $SYSEXIT, %eax
	int $SYSINTERRUPT


.type factorial, @function
factorial:
	pushl %ebp
	movl %esp, %ebp
	movl 8(%ebp), %eax
	cmpl $1, %eax
	je end_func
	decl %eax
	pushl %eax
	call factorial
	movl 8(%ebp), %ebx
	imull %ebx, %eax			
end_func:
	movl %ebp, %esp
	popl %ebp
	ret

