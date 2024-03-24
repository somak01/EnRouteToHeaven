#Purpose: is to demonstrate how functions work with a simply example
#	for the purpose of demonstration the addition function will use 
#	2 parameters, that will be added together and a local variable
#	which will hold the 2 values


#the data section will not contain anything
.section .data

.section .text
.globl _start
_start:
	pushl $5
	pushl $3
	call addition
	addl $8, %esp
	movl %eax, %ebx
	movl $1, %eax
	int $0x80


.type addition, @function
addition:
	pushl %ebp	#first push the base pointer %ebp onto the stack
	movl %esp, %ebp	#now move %ebp into %esp
	subl $4, %esp	#add 4 to esp to declare the one local variable
	movl 8(%ebp),%eax
	addl %eax, -4(%ebp)
	movl 12(%ebp), %eax
	addl %eax, -4(%ebp)
	movl -4(%ebp), %eax
	movl %ebp, %esp
	popl %ebp
	ret
