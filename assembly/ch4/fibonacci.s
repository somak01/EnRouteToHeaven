#Purpose: this is a program that aims to calculate fibonacci numbers
#	using recursion, will probably work like ass



.section .data

.section .text

.globl _start
.globl fibonacci

_start:
	pushl $5 #push the parameter into the stack
	call fibonacci #call the actual function
	addl $4, %esp  #move the stack pointer up so we will overwrite overtime
		       #the previous values in the stack
	movl %eax, %ebx#moving the result of the function into %ebx
	movl $1, %eax
	int $0x80

.type fibonacci, @function

fibonacci:
	
	pushl %ebp	#push the bsae pointer to the stack
	movl %esp, %ebp #copy the address in the stack pointer to the base poin 
			#ter
	%movl 8(%ebp), %eax #move the parameter to the eax register
	
	cmpl $2, %eax
	jle end_fibonacci
	
	decl %eax
	pushl %eax


end_fibonacci:
	movl %ebp, %esp
	popl %ebp
	ret
