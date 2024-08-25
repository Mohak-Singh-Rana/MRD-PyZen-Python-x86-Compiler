.section .rodata 
.note0: 
	.string "%ld\n" 
	.text 
	.globl main 
L1:
	 
A.__init__: 
L2:
	 
L3:
	 
	pushq %rbp 
	movq %rsp , %rbp 
	subq $0 , %rsp 
L4:
	 
L5:
	 
L6:
	 
L7:
	 
	movq 16(%rbp) , %r12 
	movq %r12 , %rdi 
	call puts 
L8:
	 
	movq 24(%rbp) , %r12 
	movq %r12 , %rdi 
	call puts 
L9:
	 
L10:
	 
	movq %r15 , %r13 
	addq $0 , %r13 
	movq 24(%rbp) , %r12 
	movq %r12 , 0(%r13) 
L11:
	 
L12:
	 
	movq %r15 , %r13 
	addq $8 , %r13 
	movq 16(%rbp) , %r12 
	movq %r12 , 0(%r13) 
L13:
	 
L14:
	 
L15:
	 
	movq $0 , %r12 
	movq %r12 , %r8 
	addq $0 , %rsp 
	popq %rbp 
	ret 
L16:
	 
L17:
	 
main: 
L18:
	 
L19:
	 
	pushq %rbp 
	movq %rsp , %rbp 
	subq $24 , %rsp 
L20:
	 
L21:
	 
	movq $48 , %rdi 
	call malloc 
L22:
	 
L23:
	 
	lea string1(%rip) , %r12 
	movq %r12 , -8(%rbp) 
.section .data 
string1: .string "Hello" 
.section .text 
L24:
	 
	lea string2(%rip) , %r12 
	movq %r12 , -8(%rbp) 
.section .data 
string2: .string "mine" 
.section .text 
L25:
	 
	movq $16 , %rdi 
	call malloc 
	movq %rax , -16(%rbp) 
L26:
	 
L27:
	 
	lea string3(%rip) , %r11 
	pushq %r11 
.section .data 
string3: .string "hdsu" 
.section .text 
L28:
	 
	movq -8(%rbp) , %r11 
	pushq %r11 
L29:
	 
	movq -16(%rbp) , %r15 
	call A.__init__ 
L30:
	 
	addq $16 , %rsp 
L31:
	 
	movq -16(%rbp) , %r15 
	movq 0(%r15) , %r12 
	movq %r12 , %rdi 
	call puts 
L32:
	 
	movq -16(%rbp) , %r15 
	movq 8(%r15) , %r12 
	movq %r12 , %rdi 
	call puts 
L33:
	 
L34:
	 
L35:
	 
	movq $0 , %r12 
	movq %r12 , %r8 
	addq $24 , %rsp 
	popq %rbp 
	ret 
L36:
	 
L37:
	 
L38:
	 
L39:
	 
	addq $0 , %rsp 
L40:
	 
L41:
	 
		mov $60 , %rax 
		movq $0 , %rdi 
		syscall 
format:
	.ascii "%ld\n" 
