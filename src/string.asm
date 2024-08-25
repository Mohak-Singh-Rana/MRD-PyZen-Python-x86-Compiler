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
	 
	movq $24 , %rdi 
	call malloc 
L6:
	 
L7:
	 
	movq %rax , 0(%rbp) 
	movq $51 , %r12 
	movq %r12 , 0(%rax) 
	movq $48 , %r12 
	movq %r12 , 8(%rax) 
.section .data 
string1: .string "30\n" 
.section .text 
L8:
	 
	movq $24 , %rdi 
	call malloc 
L9:
	 
L10:
	 
	movq %rax , 0(%rbp) 
	movq $52 , %r12 
	movq %r12 , 0(%rax) 
	movq $48 , %r12 
	movq %r12 , 8(%rax) 
.section .data 
string2: .string "40\n" 
.section .text 
L11:
	 
L12:
	 
L13:
	 
	movq $0 , %r12 
	movq %r12 , %r8 
	addq $0 , %rsp 
	popq %rbp 
	ret 
L14:
	 
L15:
	 
A.add: 
L16:
	 
L17:
	 
	pushq %rbp 
	movq %rsp , %rbp 
	subq $0 , %rsp 
L18:
	 
L19:
	 
L20:
	 
L21:
	 
L22:
	 
	movq 16(%rbp) , %r12 
	movq %r12 , %rsi 
	lea .note0(%rip) , %rax 
	movq %rax , %rdi 
	xor %rax , %rax 
	call printf@plt 
L23:
	 
	movq 24(%rbp) , %r12 
	movq %r12 , %rsi 
	lea .note0(%rip) , %rax 
	movq %rax , %rdi 
	xor %rax , %rax 
	call printf@plt 
L24:
	 
	movq 32(%rbp) , %r12 
	movq %r12 , %rsi 
	lea .note0(%rip) , %rax 
	movq %rax , %rdi 
	xor %rax , %rax 
	call printf@plt 
L25:
	 
	movq 16(%rbp) , %r12 
	movq %r12 , %r8 
	addq $0 , %rsp 
	popq %rbp 
	ret 
L26:
	 
L27:
	 
L28:
	 
L29:
	 
B.__init__: 
L30:
	 
L31:
	 
	pushq %rbp 
	movq %rsp , %rbp 
	subq $0 , %rsp 
L32:
	 
L33:
	 
L34:
	 
L35:
	 
L36:
	 
L37:
	 
	movq %r15 , %r13 
	addq $16 , %r13 
	movq 24(%rbp) , %r12 
	movq %r12 , 0(%r13) 
L38:
	 
	mov $1 , %rax 
	mov $1 , %rdi 
	lea string2(%rip) , %rsi 
	mov $3 , %rdx 
	syscall 
L39:
	 
L40:
	 
	movq %r15 , %r13 
	addq $24 , %r13 
	movq 16(%rbp) , %r12 
	movq %r12 , 0(%r13) 
L41:
	 
	mov $1 , %rax 
	mov $1 , %rdi 
	lea string1(%rip) , %rsi 
	mov $3 , %rdx 
	syscall 
L42:
	 
L43:
	 
	movq %r15 , %r13 
	addq $32 , %r13 
	movq 32(%rbp) , %r12 
	movq %r12 , 0(%r13) 
L44:
	 
L45:
	 
L46:
	 
	movq $0 , %r12 
	movq %r12 , %r8 
	addq $0 , %rsp 
	popq %rbp 
	ret 
L47:
	 
L48:
	 
main: 
L49:
	 
L50:
	 
	pushq %rbp 
	movq %rsp , %rbp 
	subq $16 , %rsp 
L51:
	 
L52:
	 
	movq $40 , %rdi 
	call malloc 
	movq %rax , -8(%rbp) 
L53:
	 
L54:
	 
	pushq %r11 
.section .data 
string3: .string "10\n" 
.section .text 
L55:
	 
	pushq %r11 
.section .data 
string4: .string "20\n" 
.section .text 
L56:
	 
	pushq %r11 
.section .data 
string5: .string "69\n" 
.section .text 
L57:
	 
	movq -8(%rbp) , %r15 
	call B.__init__ 
L58:
	 
	addq $24 , %rsp 
L59:
	 
	movq -8(%rbp) , %r15 
	movq 16(%r15) , %r12 
	movq %r12 , %rsi 
	lea .note0(%rip) , %rax 
	movq %rax , %rdi 
	xor %rax , %rax 
	call printf@plt 
L60:
	 
L61:
	 
L62:
	 
	movq $0 , %r12 
	movq %r12 , %r8 
	addq $16 , %rsp 
	popq %rbp 
	ret 
L63:
	 
L64:
	 
L65:
	 
L66:
	 
	addq $0 , %rsp 
L67:
	 
L68:
	 
		mov $60 , %rax 
		movq $0 , %rdi 
		syscall 
format:
	.ascii "%ld\n" 
