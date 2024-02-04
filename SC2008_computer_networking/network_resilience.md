# Network Resilience

* A measure of **Network Fault Tolerance**
* Probability that the networks remains connected

Assumption: Probability of link breaks are independent

* Link Service Availability:

    $T_{avail} = ((T_{total\ time} - T_{downtime})/T_{total\ time})\times100$

    * $T_{total}$ counted as 24/7
    * $T_{downtime}$ time when link is unavailable  
    (link breaks, scheduled/unscheduled maintenance)

# Flow Control
Receiver is in control of the flow (Since it must acknowledge reception)

### Stop & Wait
Procedure
* Transmit frame
* ACK from destination (acknowledge) after receiving ENTIRE frame
* Source awaits ACK
* Destination can stop by not sending ACK

#### ARQ (Automatic Repeat Request)
* If faulty, discard OR NAK
* Timeout for transmission
* Retransmit on negative ack

### Sliding Window
* Multiple frames
* Agree on buffer
* Frames are numbered modulo $2^k$
* ACK contains number of next expected frame (eg. ACK 4)

#### Go-back-N ARQ
Frames are accepted in sequence

$U = \begin{cases}
    \frac{1-P}{1+2aP} &  W\geq2a+1\\\\
    \frac{W(1-P)}{(1+2a)(1-P+WP)} & W \lt 2a+1
\end{cases}$


Upon lost frame:
* Timeout, then send ACK with poll bit 1 (Destination replies RRi)
* Timeout, then resend frame + poll bit 1

ASSUMPTIONS (calculation)
* Tack and Tproc are negligible
* Frames are never completely lost (no timeout)
* ACK and NAK are never in error
* Frame is acknowledged immediately after reception
* Sender always has frames to send

#### Selective-reject ARQ
Only rejected frames are retransmitted

$U = \begin{cases}
    1-P & W\geq2a+1\\\\
    \frac{W(1-P)}{(1+2a)} & W\lt2a+1
\end{cases}$

* Receiver transmits SREJn on faulty n
* After receiving valid n, put back in proper order and passed to higher layer
* Minimises retransmission
* Buffer management is more complex
