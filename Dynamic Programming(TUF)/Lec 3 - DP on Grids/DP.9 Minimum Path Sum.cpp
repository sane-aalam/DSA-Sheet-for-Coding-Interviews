
#include <bits/stdc++.h>
using namespace std;

// 1. express everything into the terms of indexes
// 2. explore all paths 
// 3. find minimum path sum.

class Solution {
private:
    int FindMinimumPathSum(int i, int j, vector<vector<int>> & grid){
         if(i == 0 && j == 0){
            return grid[0][0];
         }

         if(i < 0 || j < 0){
            return 100000;
         }

         int left = grid[i][j] + FindMinimumPathSum(i,j-1,grid);
         int up =  grid[i][j] + FindMinimumPathSum(i-1,j,grid);
         int MINIMUM_PATH = min(left,up);
         return MINIMUM_PATH;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();

         int minimumPathSum = FindMinimumPathSum(n-1,m-1,grid);
         // return minimum path sum 
         return minimumPathSum;
    }
};


// 2. memorization

class Solution {
private:
    int FindMinimumPathSum(int i, int j, vector<vector<int>> & grid,vector<vector<int>> & dp){
         if(i == 0 && j == 0){
            return grid[0][0];
         }

         if(i < 0 || j < 0){
            return 100000;
         }

        // reducing the overlapping subproblems
         if(dp[i][j] != -1){
            return dp[i][j];
         }

         int left = grid[i][j] + FindMinimumPathSum(i,j-1,grid,dp);
         int up =  grid[i][j] + FindMinimumPathSum(i-1,j,grid,dp);
         int MINIMUM_PATH = min(left,up);
         return dp[i][j] =  MINIMUM_PATH;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();

         vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
         int minimumPathSum = FindMinimumPathSum(n-1,m-1,grid,dp);
         // return minimum path sum 
         return minimumPathSum;
    }
};

// 3. table 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

// declare the matrix dp[n][m].
// according to changable variable we have to write for looping
// copy the recurrence relation of matrix 
        int dp[n+1][m+1];
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                 if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                 }else{
                     int left = grid[i][j];
                     int up = grid[i][j];

                     if(i > 0){
                        up += dp[i-1][j];
                     }else{
                        up += 1e9;
                     }

                     if(j > 0){
                        left += dp[i][j-1];
                     }else{
                        left += 1e9;
                     }
                      
                     dp[i][j] = min(left,up);
                 }
            }
        }
        return dp[n-1][m-1];
    }
};