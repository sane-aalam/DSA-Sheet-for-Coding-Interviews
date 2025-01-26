
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> resultMat = mat;
        
        queue<pair<int,pair<int,int>>> q;
        
        for(int row = 0; row < n; row ++){
            for(int col = 0; col < m; col++){
                if(mat[row][col] == 0 && vis[row][col] == 0){
                    q.push({0,{row,col}});
                    vis[row][col] = 1;
                }
            }
        }
        
        while(!q.empty()){
            int distance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            // store the result 2-D vector 
            resultMat[row][col] = distance;
            
            // Traversal the 4-direction into the matrix 
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};
            
            for(int directionMover = 0; directionMover < 4; directionMover++ ){
                int newrow = delrow[directionMover] + row;
                int newcol = delcol[directionMover] + col;
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m
                  && vis[newrow][newcol] == 0){
                    q.push({distance+1,{newrow,newcol}});
                    vis[newrow][newcol] = 1;
                }
            }
            
        }
        return resultMat;
    }
};




