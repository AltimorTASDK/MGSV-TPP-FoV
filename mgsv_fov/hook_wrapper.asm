hook_decrypt proto
hook_update_fov_lerp proto

.code

hook_decrypt_wrap proc
	call hook_decrypt
	; Do the instructions at the end of the original function
	mov eax, 1
	add rsp, 48h
	ret
hook_decrypt_wrap endp

hook_update_fov_lerp_wrap proc
	push rcx				  ; 1 byte
	call hook_update_fov_lerp ; 5 bytes
	pop rcx					  ; 1 byte

	; for the instructions we overwrote with our trampoline
	; MUST match patch size!
	; make sure trampoline size lies on instruction boundary in original code
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	; will be overwritten with our return address
	; instruction start + 2 bytes for address
	mov rax, 1234567890ABCDEFh
	jmp rax
hook_update_fov_lerp_wrap endp

end