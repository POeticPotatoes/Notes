### Yang Iiyu A0309471A
# Task 1: Dynamic Programming (DP)
**1.**  
All tasks describe a problem involving some array of changing stock prices for a given stock over several days, and the objective is always to maximise stock price over the given time period using the provided operations. The tasks differ in type of operation:
1. For Task 1-1, only a single buy/ sell operation may be performed
2. For Task 1-2, buy/ sell operations may be performed multiple times, but at most 1 share may be held at any time.
3. For Task 1-3, at most 2 buy/ sell operations each may be done in total
4. For Task 1-4, at most k buy/ sell operations each may be performed.
5. For Task 1-5, at most k buy/ sell operations each may be performed, and short operations are possible.

**2.**  
|Task | dp( | i | , | k_left | , | state | , | can_ss | ) |
|-----|-----|---|---|--------|---|-------|---|--------|---|
|1-1  | dp( | 0 | , | 1      | , | 0     | , | false  |)
|1-2  | dp( | 0 | , | n      | , | 0     | , | false  |)
|1-3  | dp( | 0 | , | 2      | , | 0     | , | false  |)
|1-4  | dp( | 0 | , | k      | , | 0     | , | false  |)
|1-5  | dp( | 0 | , | k      | , | 0     | , | true   |)

Notes: 
* Observe that for 1-2, an optimal solution exists with not more than n transactions. This is because buying and selling a stock multiple times in the same day results in no profit at all, ie. only the final buy/ sell operation on any given day matters. This implies that any sequence of transactions over all n days may be reduced to $\leq n$ transactions, thus it is sufficient to allow n operations in total to find some optimal solution. **Of course, setting k_left to infinity would also work for a top-down solution, but not for a bottom-up solution**.

**3.**
```c++
class Solution {
private:
    vector<int> prices;
    vector<vector<vector<long long>>> memo;

    long long dp(int i, int k_left, int state, bool can_ss) {
        // If state is 2, then we forgot to buy after performing a short
        // Otherwise, we can simply return 0
        if (i >= prices.size() || !k_left) return state == 2 ? -LLONG_MAX : 0;

        if (memo[i][k_left][state] != -1) return memo[i][k_left][state];
        
        long long &result = memo[i][k_left][state];
        result = dp(i+1, k_left, state, can_ss);
        if (state == 0 && can_ss) result = max(result, prices[i] + dp(i+1, k_left, 2, can_ss));
        if (state == 0) result = max(result, dp(i+1, k_left, 1, can_ss) - prices[i]);
        if (state == 1) result = max(result, prices[i] + dp(i+1, k_left-1, 0, can_ss));
        if (state == 2) result = max(result, dp(i+1, k_left-1, 0, can_ss) - prices[i]);
        return result;
    }

public:
    long long maximumProfit(vector<int> &prices, int k) {
        (*this).prices = prices;
        memo.assign((int) prices.size(), vector(
            k+1, vector<long long>(3, -1))
        );
        return dp(0, k, 0, true);
    }
};
```

**4.**  
Task 1-2. This is because it creates a memo table of size n*n*3. Since the maximum value of n is $3\cdot 10^4$, this creates a table of size $2.7 \cdot 10^9$, which is over 10 gigabytes in size (since long long is 8 bytes). The simple solution is to observe that k_left is not required for Task 1-2 since we will never run out of operations. Thus we can simply remove the dimension and its logic from the code:

```c++
class Solution {
private:
    vector<int> prices;
    vector<vector<long long>> memo;

    long long dp(int i, int state, bool can_ss) {
        // If state is 2, then we forgot to buy after performing a short
        // Otherwise, we can simply return 0
        if (i >= prices.size()) return state == 2 ? -LLONG_MAX : 0;

        if (memo[i][state] != -1) return memo[i][state];
        
        long long &result = memo[i][state];
        result = dp(i+1, state, can_ss);
        if (state == 0 && can_ss) result = max(result, prices[i] + dp(i+1, 2, can_ss));
        if (state == 0) result = max(result, dp(i+1, 1, can_ss) - prices[i]);
        if (state == 1) result = max(result, prices[i] + dp(i+1, 0, can_ss));
        if (state == 2) result = max(result, dp(i+1, 0, can_ss) - prices[i]);
        return result;
    }

public:
    long long maxProfit(vector<int> &prices) {
        (*this).prices = prices;
        memo.assign((int) prices.size(), vector<long long>(3, -1));
        return dp(0, 0, false);
    }
};
```

**5.**  
The submissions page was down (returned 404), but my profile shows all 5 tasks in "Recent AC"
<br><img src="pa2-q1-ss.png" style="width:auto;display:block;margin:auto"><br> 

# Task 2: Greedy Algorithms
### **1a**  
Firstly, we observe that the y value of each point may be ignored: 
* There is no restriction on height for each rectangle, thus we can raise the height of each rectangle as much as we need.
* In other words, any point p must lie in a rectangle r (defined by its upper and lower corner) as long as $x_{r.lower}\leq x_p \leq x_{r.upper}$, since $y_{r.lower}\leq y_p\leq y_{r.upper}$ is always true: we can simply increase $y_{r.upper}$ otherwise. 
* Therefore we only consider the x value of each point in our discussion.

The simplified problem statement:  
Given an array of points on a 2d line, find the least number of ranges required such that each range is no larger than $w+1$, and each point is included in at least one range.

#### Optimal sub-structure for this task:  
* Firstly, we sort all points by increasing x values
* For any point $i$, define point $j$ as the first point that satisfies: $j>i, x_j-x_i\gt w$, ie. the first point that MUST lie within a different range (rectangle) from $i$
* We assert the following. if $MinRanges(k)$ describes the minimum number of ranges (rectangles) required to cover the points $p_k, p_{k+1},\ldots,p_n$, then:


$MinRanges(i) = 1 + MinRanges(j)$

Our base case is $MinRanges(n+1) = 0$, ie. if $j$ does not exist for some $k$ then $MinRanges(k) = 1$

**Proof of correctness**:
1. Observe that since $x_j - x_i \gt w,$ $p_i$ and $p_j$ must exist in separate ranges. However, any points between $p_i$ and $p_j$ are less than $w$ units away from $p_i$ (by definition), thus they may exist in the same range as $p_i$.
2. We prove the optimal sub-structure by contradiction:
    * Assume that some solution exists for $MinRanges(i)$ which is less than $1 + MinRanges(j)$
    * Either the additional range (1+) is not required, or there must be some other arrangement of the remaining $n-j+1$ points that requires fewer ranges than our solution.
        * The additional range is necessary due to our previous observation.
        * $MinRanges(j)$ is already optimal for $p_j, p_{j+1},\ldots,p_n$
        * Thus we have a contradiction and the sub-structure must be optimal

### 1b
Consider the following greedy choice:
* At each step, create a range (rectangle) starting from the leftmost uncovered point $p_i$, and extend its width as far right as possible (resulting in a range of $[x_i, x_i + w]$).
* All points with $x$-coordinates $\leq x_i + w$ will be covered by this range.
* Repeat these steps until all points are covered by some range

**Proof of greedy choice**  
Claim: This greedy choice results in a solution with optimal sub-structure. Proof by induction:
* Base case: An empty set of remaining points will require 0 ranges to cover, which is consistent with our optimal sub-structure: $MinRanges(n+1) = 0$
* Inductive Step: 
    * Observe that after each greedy choice, a single range has been used, and the leftmost uncovered point is the first point with $x$-coordinate $\gt x_i + w$, which is identical to $p_j$ in our previous discussion
    * We use exactly 1 range from $p_i$ to $p_{j-1}$, and apply  the greedy choice to $p_j, p_{j+1},\ldots,p_n$
    * Thus, assuming that the greedy choice is consistent with our optimal sub-structure for $p_j, p_{j+1},\ldots,p_n$, then the greedy choice is also consistent for $p_i, p_{i+1},\ldots,p_n$
* Therefore by induction we show that the greedy choice also results in optimal sub-structure.

### 1c
AC Code:
```c++
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {

        // Initialise values for the current right bound and answer
        int pos = -1;
        int ans = 0;

        // Sort the array by x value
        sort(points.begin(), points.end());

        for (vector<int> &p : points) {
            // Check if point lies within current right bound
            if (pos >= p[0]) continue;

            // Since point lies outside of right bound,
            // create a new range by updating ans and pos
            ans++;
            pos = p[0]+w;
        }

        return ans;
    }
};
```

Given $n$ points, the time complexity is $O(nlog(n))$: Although the greedy choice is performed in $O(n)$, the points must initially be sorted which requires $O(nlog(n))$ time. (`std::sort` always completes in $O(nlog(n))$ using a combination of quicksort and heapsort). Thus we have $O(nlog(n)) + O(n) \in O(nlog(n))$.

### 1d
Refer to 1c for AC code.

### 2a  
Firstly, observe the following:
* Order of nums in the array does not matter

Optimal sub-structure for this task:  
* Consider some multiset $A$ of positive numbers and some positive number $r$ that we wish to reduce the total sum by.
* Define the function $MinOps(A, r)$ as the minimum number of operations to reduce the total sum of $A$ by r
* Each operation involves:
    1. Pick some number $v\in A$
    2. Assign $A:= A\setminus \{v\}\cup \{v/2\}$
* Then we assert the following structure:

If an operation is performed on some number $x\in A$ in an optimal solution, then:

$MinOps(A, r) = 1 + MinOps(A\setminus \{x\}\cup \{x/2\}, r - x/2)$

Our base case is $MinOps(U, r) = 0$ for any multiset $U$ and any $r \leq 0$, since no more operations are required.

**Proof of correctness**:
1. Observe that the order of operations does not matter: Any number that is chosen will always reduce the sum by exactly half its value.
2. Proof of optimal sub-structure by contradiction:
    * Assume that some solution exists for $MinOps(A, r)$ which is less than $1 + MinOps(A\setminus \{x\}\cup \{x/2\}, r - x/2)$
    * Because the order of operations does not matter (and the sub-structure expression is a direct derivation of performing an operation on x), this means that no operation is ever performed on $x$ for any more optimal solution
    * This implies that no operation on $x$ ever exists in any optimal solution (contradiction)

Thus we prove by contradiction that our sub-structure is optimal.

### 2b
Consider the following greedy choice:
* At each step, pick the current largest element $x\in A$
* Halve x
* Repeat these steps until $sum_{i\in A}(i)$ is less than half of its original value

**Proof of greedy choice**  
Claim: This greedy choice results in a solution with optimal sub-structure. Exchange argument:
* Let $G$ denote the solution produced by the greedy algorithm and let $O$ be an optimal solution.
* Consider the first operation in G, which halves the largest element $g\in A$
* Suppose $O$'s first operation halves some element $o\in A$.
* Then comparing $g$ and $o$:
    * If $g = o$, then choosing $g$ is as good as $o$ (they are identical)
    * If $g\neq o$, then replacing $O$'s first operation by $G$'s gives at least as large an immediate reduction and does not increase the number of subsequent operations, because $o$ may still be chosen in subsequent steps (order does not matter).
* Therefore by exchange argument we show that the greedy choice also results in optimal sub-structure.

### 2c
AC Code:
```c++
class Solution {
public:
    int halveArray(vector<int>& nums) {

        // Use a heap to keep track of the largest element
        priority_queue<double> q;

        // This will store the remaining amount we have to reduce
        double sum = 0;

        // Add all numbers to the heap and update sum
        for (int i : nums) {
            sum += i;
            q.emplace(i);
        }

        // Initialise ans and sum
        sum /= 2;
        int ans = 0;

        while (sum > 0) {
            // Take the largest element and halve it
            double x = q.top();
            q.pop();
            q.emplace(x/2);

            // Update sum and ans
            sum -= x/2;
            ans++;
        }
        return ans;
    }
};
```

Given $n$ numbers, the time complexity is $O(nlog(n))$:
* Initialisation is in $O(nlog(n))$ as we iterate over the array once and perform a $log(n)$ `emplace()` (insert) operation with the heap.
* During the while loop, there are at most n operations performed in the worst case, because picking every number once each will halve the total value of the set.
* Each operation in the loop is performed in $O(log(n))$ due to the $log(n)$ `pop()` and `emplace()` operations on the heap (note that `top()` is $O(1)$).
* Therefore, we have a total time complexity of $O(nlog(n)) + O(nlog(n)) \in O(nlog(n))$.

### 2d
Refer to 2c for AC code.
