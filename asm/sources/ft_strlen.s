
	global _ft_strlen
	section .text

_ft_strlen:
	cmp			rdi, 0
	je			exit
	xor			rcx, rcx
	not			rcx
	cld
	xor			rax, rax
	repnz		scasb
	not			rcx
	dec			rcx
	mov			rax, rcx
	ret

exit:
	xor			rax, rax
	ret