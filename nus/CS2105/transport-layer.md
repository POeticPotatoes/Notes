# Transport Layer (TCP & UDP)
* Resides on end-hosts
* Process to process communication

Protocols:
* Sender: breaks into segments, passed to network layer
* Receiver: reassembles segments, passed to app layer
* Packet switches (routers): only check dest. IP

### Datagram/ Segments
* $H_t$ Source and dest port (TCP)
* Each IP datagram contains 1 **transport layer segment**
    * $H_n$ source and dest IP addresses

datagram (IP) | segment (TCP) | message
-|-|-
$H_n$|$H_t$|msg

#### Reliability
Network layer is "best-effort" and "unreliable"

Issues
* Corrupted (Error)
* Dropped (Loss)
* Re-ordered
* Delayed

#### RDT Model
More complex on incrementing level of unreliability

* RDT 2.0: Bit Errors
    * Checksum
    * ACK & NACK
* RDT 2.1: ACK/ NACK corruption
    * Sequence number on send (1/0)
    * RDT 2.2: NAK-free, ACK has last received number
* RDT 3.0: Loss/ Delay (Stop & Wait)
    * Timeout -> Retransmit
    * Double ACK -> ignore
    * Problem: Utilization is low
    * $U_{sender} = \frac{d_{trans}}{d_{trans} + RTT}$
* Pipelining
    * $\frac{n\times d_{trans}}{d_{trans}+RTT}$
    * Number of sequence numbers must be increased
    * Buffer at sender/ receiver
* Go-Back-N
    * Up to N unACKed packets
    * k-bit sequence number
    * Sliding window (once first element ACKed send new end)
    * Timer for oldest unACKed
    * timout(n): retransmit n and subsequent
* Selective Repeat:
    * all packets MUST be ACKed
    * timer for each unACKed packet
    * only resend unACKed
    * packets received out of window are ignored

- |Go-Back-N|Selective Repeat
-|-|-
#unACKed | N | N
ACK | cumulative | selective
out-of-order | discarded | buffered
timer | oldest| each
retransmit | all | one

## UDP 
Specifications in RFC768 - Request for Comments by IETF
* Adds port number
* Adds checksum
* Used by streamers (loss tolerant, rate sensitive)

Steps (transport layer)
1. Socket with local port #
2. Sending/ creating datagram, specify IP address and port #
3. Receiving segment, check port in segment, direct to socket

UDP header
1-16|17-32
-|-
source port | dest port
length|checksum

CRC: 1's complement of sum of 16 bit integers from segment

#### Benefits
* No connection setup
* No connection state
* Tiny header
* No congestion control (can spam)

## TCP
* Reliable in-order byte stream
* TCP socket identified by (srcIPAddr, srcPort, destIPAddr, destPort)
* Receiver directs segment to appropriate socket
* Full duplex
    * Sending and receiving can be combined

> Official specs don't specify out of order handling

> Maximum Segment Size (MSS): derived from link-layer's maximum transmission unit (MTU)


#### Header
* Src port, dest port
* sequence number, **counted in bytes**
* acknowledgement number, **next byte expected**
* offset (size of header in bits / 32)
* ACK flag (valid bit)
* SYN flag
* FIN flag
* Receive window
* Checksum
* Options (if offset > 5)

> Seq num between client and server can be diff, ie seq and ack are for different streams in same packet 

#### Algorithm (Baby)
Sender
1. create TCP segment with nextSeqNum
2. Start timer
3. pass segment to IP
4. nextSeqNum += length(data)

* if timeout, retransmit unacked segment and restart timer
* if ack with num y, set offset sendBase = y
    * if some segments still unACKed, start timer
    * Fast Retransmission: if happens 3 times, resend immediately

Receiver
* if in order
    * if already acked
        * wait 500ms for next segment
        * send ACK if no segment
    * else send cumulative ACK immediately
* if out of order (gap created), send duplicate ACK of expected immediately
* if fills gap, send cumulative ACK immediately
    
> Retransmission Time Out (RTO) value depends on estimated RTT, should be larger  

#### Connection Establishment
3 way handshake
* Client: choose initial seq #x, sends TCP SYN
* Server: choose initial seq #y, sends TCP SYN/ACK
* Client: send ACK

#### Connection Closing
* Send with FIN bit
* Can still receive (only sending connection closed),  must still send ACK

Issues
* SYN flooding by spamming SYN
* SYN/ACK flooding (sabotage some dude by using his return address)

Estimated Moving Average (EWMA): 
* $RTT_\epsilon = (1-\alpha) * RTT_\epsilon + \alpha * RTT_s$  
    * $\alpha$ typically 1/8
* $RTT_{dev} = (1-\beta) * RTT_{dev} + B * |RTT_s - RTT_\epsilon|$
    * $\beta usually 1/4$
* $RTO = RTT\epsilon + 4*RTT_{dev}$
