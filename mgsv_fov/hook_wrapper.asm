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
	push rcx
	call hook_update_fov_lerp
	pop rcx
	ret
hook_update_fov_lerp_wrap endp

end