#Hopefully a working factorial function


.section .data
.section .text

.globl _start
.globl factorial 

_start:
	pushl $4	#pushing the only parameter to the stack
	call factorial
	addl $4, %esp 	#moving the stack pointer above the parameter
	movl %eax, %ebx	#moving the return value from eax to ebx

	movl $1, %eax	#moving 1 into eax to call the exit system call
	int $0x80

.type factorial, @function
factorial:
	pushl %ebp 	#these couple lines are just standard function stuff
	movl %esp, %ebp

	movl 8(%ebp), %eax
	cmpl $1, %eax
	je end_factorial
	decl %eax
	pushl %eax
	call factorial
	movl 8(%ebp), %ebx

	imull %ebx, %eax

end_factorial:
	movl %ebp, %esp
	popl %ebp
	ret
