
// #1. Recursion 
// 1. express everything in terms of indexes
// 2. explore all paths, we have two paths
//  solve(index) = solve(index+1) or solve(index+2)
// 3. You can either start from the step with index 0, or the step with index 1.
// 4. result1 = solve(0)
// 5. result2 = solve(1);

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int index, vector<int> & cost, int n){
         if(index == n-1){
            return cost[index];
         }

         if(index > n-1){
            return 0;
         }

         int oneJump = cost[index] + helper(index+1,cost,n);
         int twoJump = cost[index] + helper(index+2, cost, n);
         int minimumJump = min(oneJump,twoJump);
         return minimumJump;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
         int startWithZeroIndex = helper(0,cost,n);
         int startWithOneIndex = helper(1,cost,n);
         int minimumCost =  min(startWithOneIndex,startWithZeroIndex); 
         return minimumCost;
    }
};

// 2. memorization 

class Solution {
private:
    int dp[1001];
    int helper(int index, vector<int> & cost, int n){
         if(index == n-1){
            return cost[index];
         }

         if(index > n-1){
            return 0;
         }

         // memo
         if(dp[index] != -1){
            return dp[index];
         }

         int oneJump = cost[index] + helper(index+1,cost,n);
         int twoJump = cost[index] + helper(index+2, cost, n);
         int minimumJump = min(oneJump,twoJump);
         return dp[index] =  minimumJump;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
         memset(dp,-1,sizeof(dp));

         int startWithZeroIndex = helper(0,cost,n);
         int startWithOneIndex = helper(1,cost,n);

        // declare the memorization matrix using -1 
        // {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} = dp[1-array]
         
         int minimumCost =  min(startWithOneIndex,startWithZeroIndex); 
         return minimumCost;
    }
};