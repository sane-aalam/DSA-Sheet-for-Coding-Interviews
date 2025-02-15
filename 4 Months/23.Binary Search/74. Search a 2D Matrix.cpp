
#include <bits/stdc++.h>
using namespace std;

// ** Burthforce Approach
// - Traversal Simple Matrix Each Cell
// - matrix[row][col] == target(key) return true
// - otherwise not present target into the matrix 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n = matrix.size();
         int m = matrix[0].size();

         for(int row = 0; row < n; row ++){
            for(int col = 0; col < m; col++){
                // matrix element is equal to target value
                if(matrix[row][col] == target){
                    return true;
                }
            }
         }
         return false;
    }
};


// Binary Search Algorithm 
// Constraints:
// -104 <= matrix[i][j], target <= 104
// According to Lecture-1 DSA-one course
// I am able to identify,easy 0(n2) easy sumbitable into leetcode
// but You must write a solution in O(log(m * n)) time complexity.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
 
    int n = matrix.size();
    int m = matrix[0].size();

    int start = 0;
    int end = n * m - 1;

    int mid = start + (end - start)/2;

    while(start <= end){
        int rowIndex = mid / m;
        int colIndex = mid % m;
        if(matrix[rowIndex][colIndex] == target){
             return 1;
        }else if(matrix[rowIndex][colIndex] < target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return 0;
    }
};