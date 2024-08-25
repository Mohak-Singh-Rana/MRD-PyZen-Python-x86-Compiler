.section .rodata 
.note0: 
	.string "%ld\n" 
	.text 
	.globl main 
L1:
	 
foo:
 
L2:
	 
L3:
	 
	pushq %rbp 
	movq %rsp , %rbp 
	subq $8 , %rsp 
L4:
	 
L5:
	 
L6:
	 
	movq 16(%rbp) , %r11 
	movq $1 , %r12 
	movq %rbp , %r13 
	subq $8 , %r13 
	addq %r12 , %r11 
	movq %r11 , 0(%r13) 
L7:
	 
	movq -8(%rbp) , %r12 
	movq %r12 , %r8 
	addq $8 , %rsp 
	popq %rbp 
	ret 
L8:
	 
L9:
	 
L10:
	 
L11:
	 
main:
 
L12:
	 
L13:
	 
	pushq %rbp 
	movq %rsp , %rbp 
	subq $40 , %rsp 
L14:
	 
L15:
	 
	movq $48 , %rdi 
	call malloc 
L16:
	 
	movq %rax , -8(%rbp) 
	movq $5 , %r12 
	movq %r12 , 0(%rax) 
	movq $1 , %r12 
	movq %r12 , 8(%rax) 
	movq $2 , %r12 
	movq %r12 , 16(%rax) 
	movq $3 , %r12 
	movq %r12 , 24(%rax) 
	movq $4 , %r12 
	movq %r12 , 32(%rax) 
	movq $5 , %r12 
	movq %r12 , 40(%rax) 
L17:
	 
	movq -8(%rbp) , %r12 
	movq 0(%r12) , %r8 
L18:
	 
	movq %r8 , 0(%rbp) 
L19:
	 
	movq 0(%rbp) , %r12 
	movq %r12 , %rsi 
	lea .note0(%rip) , %rax 
	movq %rax , %rdi 
	xor %rax , %rax 
	call printf@plt 
L20:
	 
	movq $48 , %rdi 
	call malloc 
L21:
	 
L22:
	 
	movq %rax , 0(%rbp) 
	movq $104 , %r12 
	movq %r12 , 0(%rax) 
	movq $101 , %r12 
	movq %r12 , 8(%rax) 
	movq $108 , %r12 
	movq %r12 , 16(%rax) 
	movq $108 , %r12 
	movq %r12 , 24(%rax) 
	movq $111 , %r12 
	movq %r12 , 32(%rax) 
L23:
	 
	movq -16(%rbp) , %r12 
	movq %r12 , %rsi 
	lea .note0(%rip) , %rax 
	movq %rax , %rdi 
	xor %rax , %rax 
	call printf@plt 
L24:
	 
L25:
	 
	movq %rbp , %r13 
	subq $24 , %r13 
	movq $5 , %r12 
	movq %r12 , 0(%r13) 
L26:
	 
L27:
	 
	movq -24(%rbp) , %r11 
	pushq %r11 
L28:
	 
	call foo 
L29:
	 
	addq $8 , %rsp 
L30:
	 
	movq %r8 , -32(%rbp) 
L31:
	 
L32:
	 
	movq %rbp , %r13 
	subq $40 , %r13 
	movq -32(%rbp) , %r12 
	movq %r12 , 0(%r13) 
L33:
	 
	movq -40(%rbp) , %r12 
	movq %r12 , %rsi 
	lea .note0(%rip) , %rax 
	movq %rax , %rdi 
	xor %rax , %rax 
	call printf@plt 
L34:
	 
L35:
	 
L36:
	 
	movq $0 , %r12 
	movq %r12 , %r8 
	addq $40 , %rsp 
	popq %rbp 
	ret 
L37:
	 
L38:
	 
L39:
	 
L40:
	 
	addq $0 , %rsp 
L41:
	 
L42:
	 
		mov $60 , %rax 
		movq $0 , %rdi 
		syscall 
format:
	.ascii "%ld\n" 
