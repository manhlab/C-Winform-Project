.686
.MODEL FLAT, stdcall
PUBLIC fun2
_DATA SEGMENT
StrMas db 11 dup(?);string argument
dec1 dd 10 ; decimal number
_DATA ENDS
_TEXT SEGMENT
fun2 PROC par1:dword
  lea ebx, StrMas ; get offset address
  mov ecx,11 ; loop back all string
metka1:
    mov byte ptr[ebx],' '
    inc ebx
    loop metka1
  
  mov eax, par1
  push eax
  ;so sanh dau cua eax
  or eax,eax
  jns metka2
  neg eax
metka2:
    xor edx,edx
    div dec1
    add dx,'0'
    dec ebx
    mov byte ptr[ebx], dl

    or eax,eax
    jnz metka2
    pop eax
    or eax,eax
    jns metka3
    dec ebx
    mov byte ptr[ebx],'-'
 metka3:
    mov eax,ebx
    ret
fun2 ENDP 
_TEXT ENDS
END