.section .rodata 
.note0: 
	.string "%ld\n" 
	.text 
	.globl main 
add:
 
	push %rbp 
	movq %rsp , %rbp 
	subq $8 , %rsp 
L6:
	 
	movq 16(%rbp) , %rax 
	movq 24(%rbp) , %rcx 
	addq %rcx , %rax 
	movq %rax , -8(%rbp) 
	movq -8(%rbp) , %rcx 
	movq %rcx , %r8 
	addq $8 , %rsp 
	pop %rbp 
	ret 
main:
 
	push %rbp 
	movq %rsp , %rbp 
	subq $16 , %rsp 
	movq $2 , %rax 
	pushq %rax 
	movq $1 , %rax 
	pushq %rax 
	call add 
	addq $16 , %rsp 
	movq %r8 , -8(%rbp) 
	movq -8(%rbp) , %rcx 
	movq %rcx , -16(%rbp) 
	movq -16(%rbp) , %rax 
	pushq %rax 
	movq 16(%rbp) , %rsi 
	lea .note0(%rip) , %rax 
	movq %rax , %rdi 
	xor %rax , %rax 
	call printf@plt 
	addq $8 , %rsp 
	addq $16 , %rsp 
	pop %rbp 
	ret 
	call main 
	addq $0 , %rsp 
		mov $60 , %rax 
		xor %rdi , %rdi 
		syscall 
format:
	.ascii "%ld\n" 
