
/*
 Given an integer array height[] where height[i] represents the height of the i-th stair,
  a frog starts from the first stair and wants to reach the top. 
  From any stair i, the frog has two options:
   it can either jump to the (i+1)th stair or the (i+2)th stair. 
   The cost of a jump is the absolute difference in height between the two stairs. 
   Determine the minimum total cost required for the frog to reach the top.
 */

#include <bits/stdc++.h>
using namespace std;

// 1. Recursion 
// step-1. Express everything in terms of indexes
// step-2. Do all possible ways
// step-3. according to problem - (take minimum) (all possible ways)

class Solution {
  private:
    int solve(int index, vector<int> & height){
         if(index == 0){
             return 0;
         }
         
        int left = INT_MAX;
        int right = INT_MAX;
        
        // it can either jump to the (i+1)th stair or the (i+2)th stair.
        // The cost of a jump is the absolute difference in height between the two stairs.
        // To maintain the index is not gonna to out of bound
        if(index > 0)
           left = abs(height[index] - height[index-1]) + solve(index-1,height);
           
        if(index > 1) 
            right = abs(height[index] - height[index-2]) + solve(index-2,height);
        
        // Determine the minimum total cost required for the frog to reach the top.
        int minEngeryRequired = min(left,right);
        return minEngeryRequired;
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size() - 1;
        int index = n;
        int minimumCost  = solve(index,height);
        return minimumCost;
    }
};

// 2. Memorization 

class Solution {
  private:
    int solve(int index, vector<int> & height,vector<int> & dp){
         if(index == 0){
             return 0;
         }
         
         // memorization
         
         if(dp[index] != -1){
             return dp[index];
         }
         
        int left = INT_MAX;
        int right = INT_MAX;
        
        // it can either jump to the (i+1)th stair or the (i+2)th stair.
        // The cost of a jump is the absolute difference in height between the two stairs.
        if(index > 0)
           left = abs(height[index] - height[index-1]) + solve(index-1,height,dp);
           
        if(index > 1) 
            right = abs(height[index] - height[index-2]) + solve(index-2,height,dp);
        
        // Determine the minimum total cost required for the frog to reach the top.
        int minEngeryRequired = min(left,right);
        return dp[index] = minEngeryRequired;
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size() - 1;
        int index = n;
        vector<int> dp(n+1,-1);
        int minimumCost  = solve(index,height,dp);
        return minimumCost;
    }
};


// 3. Tabulation


class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1);
        dp[0] = 0;
        
        for(int index = 1; index < n; index++){
            int left = abs(height[index] - height[index-1]) + dp[index-1];
            int right = INT_MAX;
            if(index > 1) 
             right = abs(height[index] - height[index-2] ) + dp[index-2];
             
            dp[index] = min(left,right);
        }
        return dp[n-1];
    }
};

// 4. Space Optimization
// using prev1,prev2 to findout the current element(data)
// udpate the pointers 

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int prev1 = 0;
        int prev2 = 0;
        int curr = 0;
        
        for(int index = 1; index < n; index++){
            int left = abs(height[index] - height[index-1]) + prev1;
            int right = INT_MAX;
            if(index > 1) 
             right = abs(height[index] - height[index-2] ) + prev2;
             
            curr = min(left,right);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};