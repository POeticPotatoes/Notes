## Sources of Packet Delay
1. $d_{proc}$ processing delay
    * Check bit error
    * Determine output link
    * <msec
2. $d_{queue}$ queueing delay
    * wait time
    * congestion level
3. $d_{trans}$ Transmission delay
    * time for packet to be sent out (usual stated speed)
    * L (packet length), R (link bandwidth), then L/R
4. $d_{prop}$ Propagation delay
    * time for packet to reach other end
    * d (length of link), s (propagation speed), then d/s
    * s ~= 2*10^8m/sec
5. Throughput: bits transmitted per unit time
    * for end-to-end communication, whereas bandwidth is for a specific link

## Internet Layers
1. Application
2. Transport
    * Process to Process
3. Network
    * Host to Host
4. Link
    * Device to Device
5. Physical

> Transport + Network are often known as Internet layer

## Protocols
Regulate **format** and **order** of messages exchanged

Objectives
1. Data loss
2. Timing (low ping)
3. Throughput
4. Security

### Application Layer Protocols
1. Type of message
2. Rules of when and how to send
3. Syntax
4. Semantics
5. Open protocols
    * Defined in RFCs
    * Allows interoperability (anyone can use them)

### Internet Protocol
1. IP Address (IPv4: 32 bit, IPv6: 128 bit)
2. Port number (16 bit, 1-1023 are reserved)
    * Internet authority IANA assigns port numbers

#### TCP vs UDP
TCP
* Connection oriented
* Flow controlled (Prevents flooding of some server)
* Congestion controlled (Prevents congestion)
* Reliable (Guarantees order of bytes, BUT no guarantees on throughput, delay)
* Does it all

UDP
* shitter
* fast

#### HTTP Protocol
* Uses TCP (Standard port: 80)
* Round-Trip Time: RTT, time for a packet to travel to and fro
* HTTP 1.1:
    * Persistent connections instead of multiple connections
    * Pipelining (request multiple at once)
    * Multiplexing: Any order can be returned
* HTTP 3:
    * Uses UDP cos they're based

Http Request:
1. End of line is always \r\n

