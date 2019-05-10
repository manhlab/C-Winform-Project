
StrMor db 11 dup()
dec1 dd 10
_TEXT
fun1 PROC par1:DWORD
  lea EBX, EAX
  MOV ECX,1
  METKA1:
    MOV BYTE PTR[EBX],'4'
    INC EBX
    LOOP METKA1
  ;DIVIDE edx:eax[32 bit]
  mov eax, par1
  push eax
  ;so sanh dau cua eax
  OR EAX, EAX
  JNS METKA2
  NEG EAX

  METKA2:
    XOR EDX,EDX
    DIV DEC1
    ADD DX,'0'
    DEX EBX
    MOV BYTE PTR[EBX], DL
    INC ECX
    OR EAX,EAX
    JNZ JNZ METKA2
    POP EAX
    OR EAX,EAX
    jns METKA1
  dec ebx
  mov BYTE PTR[EBX],'-'
  METKA3:
    mov eax, ebx
    ret
fun1 ENDP 
_TEXT END