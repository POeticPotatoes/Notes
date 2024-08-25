# Risk and Rates of Return

**Risk** in stock-investment is related to the uncertainty of investment return.

Most investors are **risk-averse** (NOT risk-adverse). They dislike risk and require higher rates of return to encourage them to hold **riskier securities**.

**Risk Premium** - the difference between the reutrn on a risky asset and a riskless asset. This serves as **compensation** for investors to hold riskier securities.


    Higher Risk -> Higher Rates of Return

<br>

> NOTE: Risk aversion does NOT mean that investors prefer lower-risk stocks to higher-risk stocks. They simply *require higher potential return* to attract them to invest in more risky stocks.

$Return=\frac{(Ending\ value - Amount\ Invested)}{Amount\ Invested}$ (Calculate the percent return)

**Investment Risk** is related to the probability of earning a return different from expected.
* Standalone risk
    * Risk of holding a single asset/security
* Portfolio risk
    * Risk of holding multiple assets/securities

## Probability Distributions
The **Standard Deviation** of all possible outcomes represents whether returns are likely to be close to the expected return.

Types of Assets/Securities:
* Independent of the economy
* Move with the economy (Positive economy)
* Counter-Cyclically with the economy (Negative correlation)

 ### Expected Return for Investment
$\hat{r} = \sum_{i=1}^{N}r_iP_i$ where:
* $r_i$ is the expected return at state $i$
* $P_i$ is the probability of achieving state $i$.
* $1-N$ are all possible states of the economy

### Standard Deviation for Investment
$\sigma=\sqrt{\sum_{i=1}^{N}(r_i-\hat r)^2P_i}$
> This makes sense. It's just the square-adjusted weighted absolute sum of all deviations.

### Coefficient of Variation (CV)
$CV=\frac{\sigma}{\hat r}$
* A **standardised measure of dispersion** about the expected value that shows risk per unit of return
* Useful when comparing investments with different expected returns.

## Sources of Risk

**Stand-alone Risk** can be decomposed into **diversifiable risk** and **market risk**

* Diversifiable risk - portion of a security's stand-alone risk that can be eliminated through proper diversification
    - Caused by idiosyncratic events of a company (eg. workers' strike)
* Market risk - portion of a security's stand-alone risk that cannot be eliminated through diversification. Measured by beta.
    - Caused by market-wide risk factors that affect all stocks (eg. recession)

Hence, a portfolio converges on market risk which is ~20%, and a portfolio more than 10 stocks experiences negligible reduction to risk.

## Capital Asset Pricing Model (CAPM) and Required Return
CAPM suggests that a stock's **required return** equals the risk-free return plus a risk premium that reflects the stock's risk after diversification.  

$r_i=r_{rf}+(r_m-r_{rf})b_i$
* beta $b_i$ is market risk (ie. the market portfolio is given a reference beta of 1)
    - It cannot be predicted for future stock-market movements
    - It can be estimated by running a **regression** of the security's past returns against past returns of the market: The gradient of the regression line would be beta.
    - Stocks with high standard deviations <ins>do not necessarily have high betas</ins>.
    - $\beta_i=\frac{\sigma_i}{\sigma_m}\rho_{im}, -1\leq\rho_{im}\leq 1$
        - $\sigma_i$ - deviation of stock
        - $\sigma_m$ - deviation of market
        - $\rho_{im}$ - correlation coefficient
* $(r_m-r_{rf})$ is Market Risk Premium - The additional return over the risk-free rate needed to compensate investors for assuming an average amount of risk.
    - Depends on the perceived risk of the stock market and the investors' **degree of risk aversion**
    - Most estimates suggest it ranges between 4% and 8% per year

> The relevant riskiness of a stock is its market risk as measured by beta

#### Cons
* Uses historical data
* Does not account for new information
* Does not take into account unsystematic risk
* Assumes many assumptions (Which do not hold true)
* Volaitlity of CAPM variables
    - Risk-free rate is quantified as return on short-term govt securities (which changes daily

#### Pros
* Ease of use
* Eliminates unsystematic risk (By assuming a diversified portfolio)
* Considers systematic risk

<hr>

## Comparing Expected and Required Returns
```c++
string compareStock(float expected, float required) {
    if (expected == required)
        return "fairly valued"; // It is ok to invest
    if (expected > required)
        return "undervalued"; // It is good to invest
    return "overvalued"; // It is not good to invest
}
```

* **Required returns** - Returns an investor requires given the riskiness of the stock and returns available on other investments
* **Expected returns** - Returns an investor who buys the stock expects to get in the future
    - Only buy when expected > required
    - **In equilibrium, expected and required returns are equal**
* **Realised returns** - Returns you actually get
    - Expected and required returns are **forward looking**, whereas realised returns are **historical**

## Security Market Line
Position depends on
* Expected inflation (Shifts SML parallelly upwards/downwards)
* Investors' risk aversion (Changes slope)

> This line is NOT the Regression Line, which is the *Market Risk Premium* where an axis is Beta vs the gradient as Beta

## Question of the Week
This is the question of the week.  
Instead of investing in bonds, you are considering investing in stocks. The information for three stocks, Stock A, B and C are given below. The returns on the three stocks are positively correlated, but they are not perfectly correlated (i.e., that means each of the correlation coefficient is between 0 and 1).


                                       
 
Portfolio ABC has one-third of its funds invested in each of the three stocks. The risk-free rate is 5.5%, and the market is in equilibrium.

a) What is the market risk premium (rM Ð rRF)?
b) What is the beta of Portfolio ABC?
c) What is the required return of Portfolio ABC?
d) Would you expect the standard deviation of Portfolio ABC to be less than 15%, equal to 15%, or greater than 15%? Why?
