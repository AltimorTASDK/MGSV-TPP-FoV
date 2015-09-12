hook_decrypt proto
.code
hook_decrypt_wrap proc
	call hook_decrypt
	; Do the instructions at the end of the original function
	mov eax, 1
	add rsp, 48h
	ret
hook_decrypt_wrap endp
end