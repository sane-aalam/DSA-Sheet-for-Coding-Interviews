#include <bits/stdc++.h>
using namespace std;


/**
 * You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
 * An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
 * Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 */

class Solution {
private:
    int totalNubmerWays(int i , int j , vector<vector<int>> & obstacleGrid){

        // base case
        // When you came into the matrix[0][0], which you have got one possible ways
         if(i == 0 && j == 0){
            return 1;
         }

         if(i < 0 || j < 0){
            return 0;
         }

        // blocked to path to reached (0,0)
        // return 0, this is not correct paths
         if(obstacleGrid[i][j] == 1){
            return 0;
         }


         int left = totalNubmerWays(i,j-1,obstacleGrid);
         int up = totalNubmerWays(i-1,j,obstacleGrid);
         int currentWays = left + up;
         return currentWays;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int reuslt = totalNubmerWays(n-1,m-1,obstacleGrid);
        return reuslt;
    }
};

// 2. memorization

class Solution {
private:
    int totalNubmerWays(int i , int j , vector<vector<int>> & obstacleGrid, vector<vector<int>> & dp){

        // base case
        // When you came into the matrix[0][0], which you have got one possible ways
         if(i == 0 && j == 0){
            return 1;
         }

         if(i < 0 || j < 0){
            return 0;
         }

        // blocked to path to reached (0,0)
        // return 0, this is not correct paths
         if(obstacleGrid[i][j] == 1){
            return 0;
         }

         if(dp[i][j] != -1){
            return dp[i][j];
         }

         int left = totalNubmerWays(i,j-1,obstacleGrid,dp);
         int up = totalNubmerWays(i-1,j,obstacleGrid,dp);
         int currentWays = left + up;
        return  dp[i][j] = currentWays;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

      // edge case- matrix[0][0] is blocked you can't reached the matrix (0,0);
      // which means you can move robots
      // directly return zero(not possible)
        if(obstacleGrid[0][0] == 1){
            return 0;
        }

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int reuslt = totalNubmerWays(n-1,m-1,obstacleGrid,dp);
        return reuslt;
    }
};


// 3. Table 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int  n = obstacleGrid.size();
         int m = obstacleGrid[0].size();

         if(obstacleGrid[0][0] == 1){
            return 0;
         }

         int dp[n+1][m+1];

        // create the dp matrix using changable variable
        // copy the recurrence relation, fill the matrix using 2, loops
        // number of loops depends on the changable varaible 
         for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                 if(i == 0 && j == 0){
                    dp[i][j] = 1;
                 }else if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                 }else{
                     int left = 0;
                     int up = 0;
                     if(i > 0){
                        up = dp[i-1][j];
                     }
                     if(j > 0){
                        left = dp[i][j-1];
                     }
                     dp[i][j] = up + left;
                 }
            }
         }
         return dp[n-1][m-1];
    }
};


// 4. space optimization 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        // edge case of matrix blocked 
         if(obstacleGrid[0][0] == 1){
            return 0;
         }

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

    // - no need to use entire the matrix 
    // - you just need to use 1-D array to reduce the space complexity
    // - make it easy, clean code 
        vector<int> prev(n,0);

         for(int i = 0; i<n; i++){
            vector<int> temp(n,0);
            for(int j = 0; j<m; j++){
                 if(i == 0 && j == 0){
                   temp[j] = 1;
                 }else if(obstacleGrid[i][j] == 1){
                   temp[j] = 0;
                 }else{
                     int left = 0;
                     int up = 0;
                     if(i > 0){
                        up = prev[j];
                     }
                     if(j > 0){
                        left = temp[j-1];
                     }
                    temp[j] = up + left;
                 }
                 prev = temp;
            }
         }
         return prev[n-1];
    }
};


