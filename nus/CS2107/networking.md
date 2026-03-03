## Network Security
Assumption: Some attacker among intermediate roles

Advantages of network layers: Modularity, Abstraction, Isolation  
Layers: Application, Transport (datagram), Network (packet), Link (frame), Physical

### Types of Attacks
#### Transport (DNS Spoof, DoS on DNS)
* Root DNS, Top level domain (TLD), authoritative
* DNS Spoofing: Reply to QID
* DoS on DNS: Solution is more servers
* Solutions
    * Integrity: DNSSEC (Signed response)
    * Confidentiality: DoH, DoT, DoQ (HTTPS (443), TLS (853), QUIC(784))

#### Link (ARP Poisoning)
* Happens cuz stateless, no auth, broadcast
* Solution: Static ARP entries/ Prevent single MAC multiple MAC with firewall

#### Application (DoS/ DDoS)
Reflection Attack (ICMP/ Smurf): Pizza ordering with ICMP PING on victim IP
* Amplification Attack (UDP, NTP): Request vs Response size diff (amplification factor)
* Solution
    * Routers do not broadcast
    * Prevent IP Spoofing (Not easy), Remove amplifiers (Distributed), Blocking (Collateral)

### Security Protocol
#### TLS/SSL
Application-Transport

#### Internet Protocol Security (IPSec)
Network Layer
* Authentication Header (AH) no encryption, only integrity/ auth of IP address
* Encapsulating Security Payload (ESP): Also confidentiality, although src/dest IP still visible in transport mode

#### WiFi Protected Access (WPA2)
Link-Physical

#### Virtual Private Network (VPN)
Tunnel mode of ESP (Network Layer)
* Revealed src/dest: VPN client and server
