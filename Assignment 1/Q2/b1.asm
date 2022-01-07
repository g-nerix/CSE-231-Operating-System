EXTERN c

section .text
	global b1

b1:	
	push rbp 
	
	mov  rbp, rsp
	pop rax
	mov rax, c 
	
	push rax
	ret
	
	;to exit code
	mov rax, 60
	mov rdi, 0
	syscall