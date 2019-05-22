.586              ;Target processor.  Use instructions for Pentium class machines
.MODEL FLAT, stdcall    ;Use the flat memory model. Use C calling conventions
.STACK            ;Define a stack segment of 1KB (Not required for this example)
.DATA             ;Create a near data segment.  Local variables are declared after
strOutput db 10 dup (0)      
.CODE             ;Indicates the start of a code segment.

fun2 PROC num:DWORD
lea ebx, strOutput
push ebx
mov eax, num     ; number to be converted
push eax
or eax,eax
jns metka2
neg eax
metka2:
	mov ecx, 10 
	divide:
		xor edx, edx
		div ecx
		add dx, '0'
		dec ebx
		mov byte ptr [ebx],dl
		test eax, eax       ; EAX is 0?
		jnz divide          ; no, continue
pop eax
or eax,eax
jns metka3
dec ebx
mov byte PTR [ebx], '-'
metka3:

    mov eax,ebx
    pop ebx
   ret 
fun2 ENDP 
END 