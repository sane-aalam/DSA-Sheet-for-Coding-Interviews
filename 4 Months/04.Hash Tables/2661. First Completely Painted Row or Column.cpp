#include <bits/stdc++.h>
using namespace std;

// TAG : HASHMAP [element:index]

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

// 1. store the array element into map
// 2. go the matrix,row-wise,col-wise, which was last the current-column,current-row of matrix 
// 3. pick the smallest-index of the array
// 4. who is best index fully painted into matrix 

// creation of unordered_MAP
// search an element of 0(1) complexity
        unordered_map<int,int> mpp;

        for(int i = 0; i<arr.size(); i++){
            int element = arr[i];
            int index = i;
            mpp[element] = index;
        }
        
        int smallestIndex = INT_MAX;

// row-wise of matrix traversal 
// all row which one is best 
        for(int row = 0; row<m; row++){
            int LastIndex = INT_MIN;
            for(int col = 0; col<n; col++){
                int val = mat[row][col];
                int index = mpp[val];
                LastIndex = max(LastIndex,index);
            }
            smallestIndex = min(smallestIndex,LastIndex);
        }

// column-wisw of matrix traversal 
// all column which one is best 
         for(int col = 0; col<n; col++){
            int LastIndex = INT_MIN;
            for(int row = 0; row<m; row++){
                int val = mat[row][col];
                int index = mpp[val];
                LastIndex = max(LastIndex,index);
            }
            smallestIndex = min(smallestIndex,LastIndex);
        }

// both of row-column, which one is best 
// return smallestIndex;
        return smallestIndex;
    }
};