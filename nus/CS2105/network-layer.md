## Internet Protocol
* Single protocol for TCP/IP model network layer
* Forwarding: Determining next hop
* Routing: Determining shortest path

### IP Address, Forwarding Table (Data Plane)
* Globally unique (Assignable with Dynamic Host Config Protocol)
* 32 bit identifier for an **interface**
* Uses switching fabric (nanosecond timeframe)
* Hardware: Ternary content addressable memories (TCAMs), works in 1 clock cycle

Forwarding Table: Contains Destination/ Next Hop, Interface

### Routing (Control Plane)
**Automated way** of obtaining forwarding table
* Run by routing processor (millisecond timeframe)

Current Bellman Ford Protocol: Sends changes only, better than RIP

Internet: Optimised Intra-AS (Autonomous System) routing vs Policy-based Inter-AS between ASs with BGP

#### Link State Algorithms
Examples: OSPF
* Uses dijkstra's
* Complete knowledge
* Periodic broadcasts of link costs

#### Fragmentation
* Same ID, different offset, flag 1 until last one
