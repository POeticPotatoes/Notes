import sys
import zlib

filename = sys.argv[1]
with open(filename, "rb") as f:
    bytes = f.read()
checksum = zlib.crc32(bytes)

print(checksum)
