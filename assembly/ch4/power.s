#Purpose of the program is to demonstrate how functions work, with a simple function
#	the simple function will be the power function, with some limitations



.section .data

.section .text

.globl _start
_start:
	pushl $2
	pushl $5 #so these are the parameters of the function, 5 is the base 2 is the power
		 #it is pushed backward since the C calling convention defines it that way
		 #in  the function prototype would look something like this int power(int base, int power);


	call power #calling the function, this does a couple things, points the instruction pointer to the power function
		   #and pushes the return address into the stack

	movl %eax, %ebx
	addl $8, %esp #removing the two pushed variables from the stack
	#if the funciton would be called twice %eax should be pushed to the memory
	pushl %eax

	pushl $3
	pushl $4
	call power
	addl $8, %esp
	popl %ebx
	addl %eax, %ebx
	

	movl $1, %eax
	int $0x80 #these are just the regular expressions


.type power, @function

power: 

	#first thing to do is push the base pointer into the stack
	pushl %ebp
	#then set the base pointer to point to the current %esp, which is the old base pointer
	movl %esp, %ebp
	#Now we have to create space for the local variables, in this case there will only be one, so we have to subtract 4(1 word=4bytes)
	subl $4, %esp #now the structure of the stack is that %ebp point to the old base pointer, 1 word above that is the return address
		#2 word above that is the first parameter of the function, and 3 word above that is the second parameter
	#moving the power into a register like %ecx
	movl 12(%ebp), %ecx
	#moving the other parameter to the local variable
	movl 8(%ebp), %eax
	#and then %eax will be used as the intermediary register, it will hold the current value of the power so initially it will hold the first power of base
	movl %eax, -4(%ebp)

power_loop_start:
	cmpl $1, %ecx
	je end_loop
	
	imull -4(%ebp), %eax
	decl %ecx
	jmp power_loop_start


end_loop:
	movl %ebp, %esp
	popl %ebp
	ret
