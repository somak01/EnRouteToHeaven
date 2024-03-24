#The purpose of the program is to return the square of its 
#input parameter
#SO it will have 1 parameter which is a fairly small integer


.section .data

.section .text

.globl _start
.globl square
_start: 
	pushl $0 #The parameter of the function
	call square #Calling to the function
	addl $4, %esp#Moving the stack pointer upwards
	movl %eax, %ebx
	movl $1, %eax
	int $0x80


.type square, @function
square:
	pushl %ebp 		#Pushing the old base pointer to the stack
	movl %esp, %ebp		#Pointing the base pointer to the old basepointer

	movl 8(%ebp), %eax	#Moving our parameter into the eax register

	imull %eax, %eax	#Multiplying it with itself so we get the square

	movl %ebp, %esp
	popl %ebp
	ret
