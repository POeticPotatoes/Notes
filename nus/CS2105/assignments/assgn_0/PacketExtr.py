import sys

buf = sys.stdin.buffer

def read_packet():
    cur = str(buf.read1(1), 'UTF-8')
    header = ''
    while cur != '' and cur in "Size: ":
        cur = str(buf.read1(1), 'UTF-8')
    while cur != 'B':
        header += cur 
        cur = str(buf.read1(1), 'UTF-8')
    size = int(header)
    data = b''
    for _ in range(size):
        data += buf.read1(1)
    sys.stdout.buffer.write(data)
    sys.stdout.buffer.flush()

while len(buf.peek(1)) != 0:
    read_packet()
