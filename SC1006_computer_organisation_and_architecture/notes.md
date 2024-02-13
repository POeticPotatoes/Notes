Overall Instruction Format
Inst. Type field
Condition Field
Shift/Rotate instructions
Branch Instructions
Load/Store Instructions
Fixed vs Variable Length instruction

## Instruction Format

Prefixes
* 000/001: Arithmetic/Logic
* 101: Branch

### Arithmetic

Base with immediate bit shift
|Condition|Prefix|Instruction|S|Rs1|Rd|Shift Size|shft|R|Rs2|
|-|-|-|-|-|-|-|-|-|-|
|31-28|3bit|24-21|1bit|19-16|15-12|11-7|6-5|1bit|3-0|

Base with index register bit shift
|Condition|Prefix|Instruction|S|Rs1|Rd|Rshift|0|shft|R|Rs2|
|-|-|-|-|-|-|-|-|-|-|-
|31-28|3bit|24-21|1bit|19-16|15-12|11-8|1bit|6-5|1bit|3-0|

Immediate
|Condition|Prefix|Instruction|S|Rs1|Rd|#rot|8-bit immediate|
|-|-|-|-|-|-|-|-
|31-28|3bit|24-21|1bit|19-16|15-12|11-8|immediate|

* R: Index register (1) or immediate
    * shft: Left(00), Right(01), ASR(10) (For signed), ROR/RRX(11) (Rotate right w/wo carry)
> Shift size is up to 31 (5b), and Rshift is up to 15 (4b)  
> For logic comparison and MOV, MOVN, Rs1 is NULL
> Shift/Rotate instructions are encoded as MOV

|Code|Instruction|Meaning|
|-|-|-
|0000|AND| Bitwise &|
|0001|EOR| Bitwise ^|
|0010|SUB| Subtract|
|0011|RSB| Reverse Subtract||
|0100|ADD| Add|
|0101|ADC| Add with carry|
|0110|SBC| Subtract with carry|
|0111|RSC| Reverse Subtract w carry|
|1000|TST| Bitwise &|
|1001|TEQ| Bitwise ^|
|1010|CMP| Subtraction|
|1011|CMN| Addition|
|1100|ORR| Bitwise \||
|1101|MOV||
|1110|BIC| (Bit Clear) Bitwise & with complement of Rs2
|1111|MVN| Bitwise !|

