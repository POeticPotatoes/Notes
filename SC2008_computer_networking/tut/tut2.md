# Q2
a->b 20ms
b->c 5ms

100Kbps for 3000 bits -> 30ms

time for first acknowledgement to return -> 20+10+20 = 50

since **each frame is acknowledged individually** then after receiving ACK1 transmitter continues to transmit F3, F4, etc. (it assumes it will receive ACK3 eventually).

3000bits per 50ms

b->c propagation is 10ms

50ms-30ms -> 20ms for 3000 bits

3000b * (1000/20) = 150Kbps

# Q3
window size 10*25 = 250b

transmission time = 250b/100000 = 2.5ms

propagation = 15ms

2.5(0.8)/(1+30) = 2/31 = 6.45%

W = 31

0.031 * 100000 = 3100b

window size = 31*4 = 124

number of bits: ceil(log2(248)) = 8

