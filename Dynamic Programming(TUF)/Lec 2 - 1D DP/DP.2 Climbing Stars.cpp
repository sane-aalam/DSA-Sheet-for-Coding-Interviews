
#include <bits/stdc++.h>
using namespace std;

// 1. Try to represent the problem in term of indexes
// 2. Do all the possible stuff
// 3. according to question - find max,min,total(sum up)

// 1. Recursion 

class Solution {
public:
    int climbStairs(int n) {
       if(n <= 1){
          return 1;
       }
       int firstJump = climbStairs(n-1);
       int secondJump = climbStairs(n-2);
       int totalJump = firstJump + secondJump;
       return totalJump;
    }
};


// 2. Memorization

class Solution {
private:
    int climbingStaircasCalled(int n, vector<int> & dp){
        if(n == 0 or n == 1) 
            return 1;
        
        if(dp[n] != -1) 
            return dp[n];
        
        int oneClimb = climbingStaircasCalled(n-1,dp);
        int twoClimb = climbingStaircasCalled(n-2,dp);
        int totalJumps = oneClimb + twoClimb;
        return dp[n] = totalJumps;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int result = climbingStaircasCalled(n,dp);
        return result;
    }
};


// 3. tabulation 
class Solution {
public:
    int climbStairs(int n) {
// step-1 recusive code
  // step-2 memorization of the recursive code
  // step-3 tabulation of the recursive code
        
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int index = 2; index<=n; index++){
            int first_calculation = dp[index-1];
            int second_calculation = dp[index-2];
            
            dp[index] = first_calculation + second_calculation;
        }  
        return dp[n];
    }
};

// 4. Space Optimization

class Solution {
public:
    int climbStairs(int n) {
        
       int prev2 = 1;
       int prev1 = 1;
        
        for(int index = 2; index<=n; index++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }  
        return prev1;
    }
};
