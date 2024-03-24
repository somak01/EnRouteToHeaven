#Purpose: calculate the factorial of a given number
#	example 4! = 4 * 3 * 2 * 1

#The program shows how to call a function recursively

.section .data # Empty since we have no global variables


.section .text

.globl _start
.globl factorial

_start:
	pushl $4 #The factorial takes 1 argmunet the number we want the 
		 #factorial of, So that gets pushed onto the stack
	call factorial #run the factorial function
	addl $4, %esp
	movl %eax, %ebx #because %eax will have to hold the system call
	movl $1, %eax
	int $0x80

#the actual implementation of factorial
.type factorial, @function
factorial:
	pushl %ebp #THis is just regular function behaviour
	movl %esp, %ebp
	movl 8(%ebp), %eax
	
	cmpl $1, %eax #checking whether we're at the base case
	je end_factorial #base case indicates that we are done :)

	decl %eax #so we decrement %eax which holds the parameter
	pushl %eax # and then push it onto the stack, as the parameter of our
		   # next call of the factorial function
	call factorial #call the function again
	movl 8(%ebp), %ebx #move the newly appended parameter to the %ebx reg

	imull %ebx, %eax #and multiply it with the value held in %eax(which
			 #overtime gets multiplied with every value)

end_factorial:
	movl %ebp, %esp
	popl %ebp
	ret

