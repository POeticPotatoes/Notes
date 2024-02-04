# Computer Networking
## Definitions

A **protocol** is a set of rules governing communication between two parties/computers

Benefits of network services
* Sharing info
* Accessing remote info
* Communicating with others
* Sharing applications
* Sharing resources

## Common Networking Models
### Open Systems Interconnection (OSI), 7 layers
#### 1. Physical Layer (Infiniband Cable)
* Physical media transmitting bit stream
* Mechanical, electrical, functional, procedural characteristics to access physical media

#### 2. Data Link Layer (Packet Description)
* Provides reliable transfer of data
* Sends frames with necessary synchronisation, error control, flow control

#### 3. Network Layer (System Connection Description)
* Upper layers with independence from data transmission/ technologies for connection
* Routes packets

#### 4. Transport Layer (Packet Recovery)
* Provides reliable transfer of data
* End-to-end error recovery/ flow control

#### 5. Session Layer (Sessions)
* Control structure for communcation
* Establishes, manages connections

#### 6. Presentation Layer (Packet Interpretation)
* Separates application processes from data representation in network

#### 7. Application Layer (Application)
* Provides access to OSI environment to users

### TCP/IP, 5 layers

## Switching Techniques
### Circuit Switching
Dedicated channel between 2 communicating stations
* Time Division Multiplex: Time slot is allocated
* Frequency Division Multiplex: Bandwidth is allocated

Stages
1. Establishment
2. Transfer (Talk)
3. Disconnect

Cons
* Inefficient (idle time)
* Set up causes delay

Pros
* No delay during transfer
* Network is transparent to users (They do not see congestion flow control or other users)

### Packet Switching
* Share network resources
* Packet uses full bandwidth (when popped off queue)
* Resources used as needed

Cons
* Store and Forward: Every switch must receive full packet before transmission
* Resource demand can exceed amount available
* Congestion
