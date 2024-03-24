#fuck this fucking shit


.section .data

.section .text
.globl _start
.globl fibo
_start:
	pushl $4
	call fibo
	addl $4,%esp
	movl %eax, %ebx

	movl $1, %eax
	int $0x80


.type fibo, @function
fibo:
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp	
	
	movl 8(%ebp), %ecx
	movl $1, %eax
	movl $1, %ebx
loop_start:
	cmpl $2, %ecx
	je end_fibo
	movl %eax, -4(%ebp)
	addl %ebx, %eax
	movl -4(%ebp), %ebx
	decl %ecx
	jmp loop_start
end_fibo:
	movl %ebp, %esp
	popl %ebp
	ret
