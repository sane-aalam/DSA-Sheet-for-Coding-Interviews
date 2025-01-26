
#include <bits/stdc++.h>
using namespace std;

// Note- Whenever you see matrix is not sorted, then you need to think about, you can no't apply greedy(appraoch).
// Then you need to think matrix, recursion
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// # Recursion
// 1. express everything in terms of index
// 2. explore all paths
// 3. find minimum path


class Solution { 
private:
   int helper(int i, int j, vector<vector<int>> & triangle,int n){

        // base case
        if(i == n - 1){
            return triangle[i][j]; 
        }

        if(i < 0 || j < 0){
            return 0;
        }

        // explore all paths
        // we have two option [current cell] - [downcell] or [downright-cell] move(we can do).

        int downDOWN = triangle[i][j] +  helper(i+1,j,triangle,n);
        int downRIGHT = triangle[i][j] + helper(i+1,j+1,triangle,n);
        return min(downDOWN,downRIGHT);
   }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // size of matrix in row-wise
        // size of matrix in col-wise
         int n = triangle.size();
         int m = triangle[0].size();
         int result = helper(0,0,triangle,n);
         return result;
    }
};

// 2. memorization

class Solution { 
private:
   int helper(int i, int j, vector<vector<int>> & triangle,int n,vector<vector<int>> & dp){

        // base case
        if(i == n - 1){
            return triangle[i][j]; 
        }

        if(i < 0 || j < 0){
            return 0;
        }

        // memo
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // explore all paths
        // we have two option [current cell] - [downcell] or [downright-cell] move(we can do).
        int downDOWN = triangle[i][j] +  helper(i+1,j,triangle,n,dp);
        int downRIGHT = triangle[i][j] + helper(i+1,j+1,triangle,n,dp);
        return dp[i][j] =  min(downDOWN,downRIGHT);
   }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // size of matrix in row-wise
        // size of matrix in col-wise
         int n = triangle.size();
         int m = triangle[0].size();

         // declare 2d matrix using vector.
         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
         int result = helper(0,0,triangle,n,dp);
         return result;
    }
};