## Learning Objectives:  
* Explain how time value of money works and why it is important in Finance
* Calculate the present value (PV) and future value (FV) of:
    * A lump sum
    * Annuity
    * Uneven cash flow stream
    * Perpetuity (only PV)
* Differentiate between annuity due and ordinary annuity
* Explain the differences between nominal, periodic, and effective interest rates
* Understand how to compare alternative investments with different compounding periods
* Understand loan amortisation and calculate the relevant outputs (e.g. payments, principal outstanding)

## Time Value of Money
**Time value of money** is the idea that <ins> money available today is worth more than the same amount in the future</ins>, because you can invest the money, eg:
* Depositing the money in a bank to earn interest
* Investing in stocks and bonds to earn returns from investment

It is used heavily in finance for purposes such as 
* Valuing stocks and bonds
* Planning retirement
* Making corporate decisions regarding investing in new plants and equipment
* Setting up loan payment schedules

### Amortization of Loans
**Future Value (FV)** of a loan is the value of a **current asset** with **principal value (PV)** at a future date based on an **assumed rate of growth or interest (I/Y)**. With $N$ as the number of steps:

$FV_N=PV(1+I)^N$

$I = (\frac{FV_N}{PV})^\frac{1}{N}-1$

Finding the **FV** of a cash flow or series of cash flows is called **compounding**.

Finding the **PV** of a cash flow or series of cash flows is called **discounting**.

### Ordinary Annuity and Annuity Due

**Annuity** is a series of **equal** cash flows at **fixed intervals** for a specified number of periods.

**Ordinary Annuity** means that cash flows occur at the **end of the period**.   
(First payment at $t=1$, last payment at $t=n$)

**Annuity Due** means that cash flows occur at the **beginning of the period**.  
(First payment at $t=0$, last payment at $t=n-1$)

$FV=\frac{PMT}{I}[(1+I)^N-1]$  

FV with PV included:  

$FV = \{[(..\{[(PV + PMT_1)\times(1+I) + PMT_2]\times(1+I)\}+..)]\}$  
$FV =PV(1+I)^n + \frac{PMT}{I}[(1+I)^N-1]$  
$\therefore FV = FV_{PMT} + FV_{PV}$

In the case of **Annuity Due**, FV experiences an additional round of interest ($\times(1+I)$)

In the case of **Annuity Due**, FV experiences an additional round of interest ($\times(1+I)$)

$PV=\frac{PMT}{I}[1-\frac{1}{(1+I)^N}]$

<<<<<<< Updated upstream
Outstanding loan can be calculated **by discounting outstanding future payments**. This can be used when calculating **principal balance** for the following month.
In the case of **Annuity Due**, PV experiences one more round of interest ($\times(1+I)$)
=======
In the case of **Annuity Due**, PV experiences one more round of interest ($\times(1+I)$)

**Perpetual Annuity** is an annuity that lasts forever ($n\rightarrow\infin$)

#### Constructing an Amortisation Table
|YEAR|BEG BAL|PMT|INT|PRIN|END BAL|
|-|-|-|-|-|-|
|1|$1000|$402|$100|$302|$698|
|2|698|402|70|332|366|
|3|366|402|36|366|0|
|TOTAL|-|$1206|$206|$1000|-|

**END BAL** = BEG BAL - PMT  
**PRIN** (principal paid) = PMT - INT

## Types of Interest Rates
**Nominal Rate** $I_{NOM}$ aka. **Quoted/Stated Rate**:  
An **annual rate** that ignores **compounding effects**.Often stated in contracts. **Compounding periods** must also be given. <ins> NOT used in calculations</ins> or shown on timelines.

**Periodic Rate** $I_{PER}$:  
Amount of interest charged each period, eg. monthly or quarterly. Used in calculations and shown on timelines.
- $I_{PER} = I_{NOM}/M$ where $M$ is the number of **compounding periods** per year.

**Effective Annual Rate**:  
The **annual rate** of interest actually being earned, **accounting for compounding**. Used to compare returns on investments with different payments per year.
- $EFF\% = (1 + I_{NOM}/M)^M-1$

This is the question of the week.
After going through the lesson, you will be able to answer such questions.
You are saving for retirement. You plan to retire when you reach 65 years old. To live comfortably during retirement, you plan to withdraw money from your savings account - $48,000 each year. Suppose today is your 25th birthday, and you decide, starting today and continuing on every year up to your 64th birthday, that you will put the same amount into a savings account.
>>>>>>> Stashed changes

**Perpetual Annuity** is an annuity that lasts forever ($n\rightarrow\infin$)

#### Constructing an Amortisation Table
|YEAR|BEG BAL|PMT|INT|PRIN|END BAL|
|-|-|-|-|-|-|
|1|$1000|$402|$100|$302|$698|
|2|698|402|70|332|366|
|3|366|402|36|366|0|
|TOTAL|-|$1206|$206|$1000|-|

**END BAL** = BEG BAL - PMT  
**PRIN** (principal paid) = PMT - INT

## Types of Interest Rates
**Nominal Rate** $I_{NOM}$ aka. **Quoted/Stated Rate**:  
An **annual rate** that ignores **compounding effects**.Often stated in contracts. **Compounding periods** must also be given. <ins> NOT used in calculations</ins> or shown on timelines.

**Periodic Rate** $I_{PER}$:  
Amount of interest charged each period, eg. monthly or quarterly. Used in calculations and shown on timelines.
- $I_{PER} = I_{NOM}/M$ where $M$ is the number of **compounding periods** per year.

**Effective Annual Rate**:  
The **annual rate** of interest actually being earned, **accounting for compounding**. Used to compare returns on investments with different payments per year.
- $EFF\% = (1 + I_{NOM}/M)^M-1$

Presentation notes
* demonstrate subbing in of values
* timeline interest should be shown once
* provide conceptual explanations
* show <ins>all cash flows even on final year </ins>
* timeline should show year and not age
* calculations and calculator inputs on same slide
* timeline lines are not arrows
* use fractions in calculation instead of rounding
* use subscripts when required
