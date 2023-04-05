## Volatile
* Dynamic Ram
    - Must be periodically refreshed
    - Destroyed on read
    - 1-3 Transistors (Small)
    - Slower and more power
    - **Basic DRAM is obsolete**,  people use **Synchronous DRAM (SDRAM)** now, with a clock signal & **pipeline architecture** which allows faster overlapping operations (DDR3, DDR4)  

Design: Transistor (when enabled) allows charge transfer
*  Static Ram
    - Can be maintained with power supply
    - Kept on read
    - 4-6 Transistors (Large)
    - Fast and less power
    - Accessed via word & bit lines  
    - Input Lines:
        * Address
        * CS_ (Chip select)
        * OE_ (Output enable)
        * Data  

Design: 2 cyclic not gates (M1-4), and 2 selects (M5-6)  

## Non Volatile
### EPROM (Erasable Programmable Read-Only Memory)
Standard: EEPROM (Electronically EPROM) using MOSFET
* MOSFET (Metal Oxide Semiconductor Field Effect Transistor)
    *  Erased state: No electrons in floating gate (No inhibitor, hence current flows and logic is 1)
    *  Programmed state (Programmed with high current): Electrons in floating gate (Inhibit flow of electrons and hence logic is 0)
    *  Programming can only change 1->0 hence programming operation:
        * Erase all (Set to 1) in a block
        * Program individual bits to 0
### Flash
* Similar FGT as EEPROM
* Can be erased in larger blocks
* Faster speed for write operations
* Less cost than EEPROM
* NOR Flash:
    * Any of the word line > Vt(Prog), Bit line is 0
    * XIP, Random Access (Hence more pins to specify exact location)
    * Requires special commands to write
    * Random word/byte programming, but erasure is block-level (64-256KB)
    * Can be used as RAM or Storage
* NAND Flash
    * All word lines > Vt(Prog), Bit line is 0
    * No XIP, data must be 1 page at a time
    * Commands must be issued to open a page, followed by more bytes
    * Single Bus to carry Address/Data
    * Lower Cost Per Bit, used for storage memory
