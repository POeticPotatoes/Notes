#!/usr/bin/env python2

import socket
import sys

port = int(sys.argv[0]);

address = ('localhost', port)
sock = socket.socket(socket.AF_INET,
                     socket.SOCK_DGRAM)
sock.bind(address)

while True:
    data, addr = sock.recvfrom(4096)
    print(f'{data} from {addr}')

    sock.sendto(data, addr)
