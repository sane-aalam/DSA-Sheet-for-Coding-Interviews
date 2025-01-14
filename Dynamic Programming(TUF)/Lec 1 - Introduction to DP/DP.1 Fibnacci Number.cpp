
#include <bits/stdc++.h>
using namespace std;

//1. Recursion 
// TC - 0(2N)
// SC - 0(N)
class Solution {
public:
    int fib(int n) {
        // base case 
        if(n <= 1){
            return n;
        }
        
        int lastFibNumber = fib(n-1);
        int secondLastFibNumber = fib(n-2);
        // sum up all calls 
        int FibNumber =  lastFibNumber + secondLastFibNumber;
        return FibNumber;
    }
};  

// 2. Memorization
// TC - 0(n)
// SC - 0(n) + 0(n)

class Solution {
private:
    int solve(int index, vector<int> dp){
        if(index <= 1){
            return index;
        }

        // memo
        if(dp[index] != -1){
            return dp[index];
        }

        int lastNumber = solve(index-1,dp);
        int secondLastNumber = solve(index-2,dp);
        int FibNumber =  lastNumber + secondLastNumber;
        
        // store the recusive calls
        return dp[index] = FibNumber;
    }
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};  

// 3. Tabulation 
// TC - 0(n)
// SC - 0(n)

class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};  

// 4. Space Optimizatoin
// TC - 0(n)
// SC - 0(1)


class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        int prev2 = 0;
        int prev = 1;
        
        for(int i=2; i<=n; i++){
            int cur_i = prev2+ prev;
            // update pointers 
            prev2 = prev;
            prev= cur_i;
        }

        return prev;
    }
};  