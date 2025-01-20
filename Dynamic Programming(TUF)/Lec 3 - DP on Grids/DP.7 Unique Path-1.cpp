
// Unique Path 
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

#include <bits/stdc++.h>
using namespace std;

// How to write recurrence relation?
// Step-1 Express everything in terms of index(row,column)
// Step-2 Explore all paths
// Step-3 Sumup all paths 

// 1. Recursion 
class Solution {
private:
   int solve(int i, int j){
       if(i == 0 && j == 0){
          return 1;
       }

       if(i < 0 or j < 0){
          return 0;
       }

       int up = solve(i-1,j);
       int left = solve(i,j-1);
       return up + left;
   }
public:
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};

// 2. Memorization

class Solution {
private:
   int TotalNumberWays(int i, int j,vector<vector<int>> & dp){

       if(i == 0 && j == 0){
          return 1;
       }

       if(i < 0 or j < 0){
          return 0;
       }

       // reduce the overlapping the subproblem
       if(dp[i][j] != -1){
          return dp[i][j];
       }

       int up = TotalNumberWays(i-1,j,dp);
       int left = TotalNumberWays(i,j-1,dp);
       int totalWays = up + left;
       return dp[i][j] = totalWays;
   }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        int result =  TotalNumberWays(m-1,n-1,dp);
        return result;
    }
};


// 3. Tablulation 
//  - declare the dp[n+1][m+1]
//  - declare the base condition
//  - according to parameter changable,write down loops, put the recurrence relations

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
      
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                // base case (included)
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }else{
                    // moments to move the matrix 
                    int left = 0;
                    int up = 0;
                    if(i > 0){
                        left = dp[i-1][j];
                    }
                    if(j > 0){
                        up = dp[i][j-1];
                    }
                    dp[i][j] = left + up;
                }
            }
        }
        // robot can take to reach the bottom-right corner.
        return dp[m-1][n-1];
    }
};

// 4. space optimazation


// inorder to calcuale the current result, we need only previous row of matrix
// do you really need matrix, answer is NO
// you can use vector List, to contain the result
// maintain the current result, vector for future calls 
// Dry run (clearly understand)
// reduce the space complexity 0(m*n) to 0(n) (FAST)


class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) { 
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }

         // simple recursive code template copy paste hai
            int up = 0;
            int left = 0;
        
        // go to left direction of matrix
        // go to up direction of matrix 
        // sumup all calls 
            if (i > 0)
                up = prev[j];

            if (j > 0)
                left = temp[j - 1];

            temp[j] = up + left;
        }
        prev = temp;
     }
     return prev[n-1]; 
    }
};