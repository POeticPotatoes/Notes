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
2. Timing/ Rate Tolerance (low ping)
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
2. Port number (16 bit, 1-1023 are reserved, 65535 max)
    * Internet authority IANA assigns port numbers

#### TCP vs UDP
TCP (Transmission Control Protocol)
* Stream abstraction
    * Data sent as a stream
    * Connection must be first established
    * data is sent in continuous streams (abstracted from packets)
* Multiple Sockets
    * Default welcome/ listening socket
    * Forked sockets per connection
* Connection oriented
* Flow controlled (Prevents flooding of some server)
* Congestion controlled (Prevents congestion)
* Reliable (Guarantees order of bytes, BUT no guarantees on throughput, delay)
* Does it all

UDP (User Datagram Protocol)
* Datagram abstraction
    * Data set as datagrams (packets)
* Single socket
* Packet contains:
    * Recipient (dest ip, port)
    * Return (source ip, port)
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
1. method path version (Request Line) 
2. headers: Values
3. \r\n
4. body

Http Response:
1. version code description
2. headers: values
3. \r\n
4. body

Important Codes
Code | Meaning
-|-
200|OK
301| Moved Permanently
304| Not Modified
403| Forbidden
404| Not Found
500| Internal Server Error

### Addressing
DNS: Domain Name System
* Translates between hostname and ip address
* Relies on DNS Resource Record, Entry types: 
    * A(address), HostName, IP address 
    * NS(name server), Domain, Hostname of authoritative name server
    * CNAME(canonical name), alias, real name
    * MX(mail exchange), domain, name of mail server
* Contains TTL (Time to Live): refresh cooldown (revalidate)

DNS Servers
* Top-Level domain (TLD) servers:
    * responsible for .com, .org, etc.
    * and all countries
* Authoritative servers:
    * Organisation's own DNS servers
    * Provides authoritative hostname to IP mappings for named hosts (subdomains)
* Local DNS server (Default name server)
    * The ISP
* Done over UDP:53

> Iterative Querying Process: Host request > Local DNS requests root DNS > Local DNS requests TLD > Local DNS requests authoritative DNS > etcetc

> Recursive: hot potato

### Security Issues
* DNS Hijacking (MITM): Compromise name servers
* DNS Tunneling (VPN): Bypassing firewall
* DNS Poisoning/ Cache Poisoning

### Sockets (Ports)
* Abstraction interface between processes and transport layer protocols
    * Present in high-level programming languates
    * Conceptual mailbox
    * Uses API calls
* Sender IP address + Port is used to **locate** processes
* Usually stores hostname instead of numerical IP address

TCP & UDP Sockets
* TCP socket (stream socket)
* UDP socket (datagram socket)
