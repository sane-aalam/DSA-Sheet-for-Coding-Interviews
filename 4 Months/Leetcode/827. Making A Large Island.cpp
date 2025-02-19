

// The focus should always be on progress, not perfection.
// Step-1 you know to how to traversal matrix using DFS
// Step-2 After reading problem, same to same 
// NUMBER OF ISLANDS - count the maximum of island problems

// Apporach to solved this problem
// - You are allowed to change at most one 0 to be 1
// - Get maximum island, When you are tying to assign 0-1 (replacement)
// - Then you need to understand the maximum components which one have 1's
// - So keep track, will pre-processing the grid using NUMBER
// - assign color to each componets get sum 
// - 1 + A(color) se count the componets + B + C 

// make of last example-3 of problem all statement - all 1's 


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
   int valid(int row, int col,vector<vector<int>>& grid ){
       return 
       (row < 0 || col < 0 || row >= grid.size()  || col >= grid[0].size())? 0: grid[row][col];
   }
   int dfs(int row, int col, int color, vector<vector<int>>& grid){
     
     // base case
     if(valid(row,col,grid) != 1){
        return 0;
     }

    // assign the color to each components using NEW-COLOR
     grid[row][col] = color;

     // An island is a 4-directionally connected group of 1s.
     // we have to move up-down, left,right direction into grid using recursive leaf of faith
     // we have to add condition, our indexes(row,col) is not gonna to out the bounds 
       return  1 + dfs(row+1,col,color,grid) 
                + dfs(row-1,col,color,grid) 
                + dfs(row,col+1,color,grid)
                + dfs(row,col-1,color,grid);
   }
public:
    int largestIsland(vector<vector<int>>& grid) {

        // Each Number store 
        // how many of 1's present (componts conting store for future making large island)
        // 1 - 4
        // 2 - 7
        // 3 - 6 
          vector<int> islands = {0,0};
        
          for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[row].size(); col++){
                if(grid[row][col] == 1){
                    // fill grid using differnt color 1,2,3,4,5..
                    // call DFS(for each components)
                    int counter = dfs(row,col,islands.size(),grid);
                    islands.push_back(counter);
                }
            }
          }

          // step-2 
          // replace the value 0 to 1.
          // get the maximum making large island using (islands) vector which have counting 

           int maxSize = 0;
           for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[row].size(); col++){
                //  You are allowed to change at most one 0 to be 1.
                //  convert into 1
                // get maximum island
                 if(grid[row][col] == 0){
                    unordered_set<int> neighboringIslands = {
                         valid(row+1,col,grid),valid(row-1,col,grid),
                         valid(row,col+1,grid),valid(row,col-1,grid)
                    };
                    int newSize = 1;
                    for(int color : neighboringIslands){
                        newSize += islands[color];
                    }
                    maxSize = max(maxSize,newSize);
                 }
             }
           }
           
           // Example-3
           // Can't change any 0 to 1, only one island with area = 4.
           // Which means there is no 0's present into the matrix,then you need to return all 1's present into the matrix 
           // ternary operetor 
           cout << maxSize << endl;
           int allArea = grid.size() * grid[0].size();
           return maxSize == 0 ? allArea : maxSize;
    }
};






