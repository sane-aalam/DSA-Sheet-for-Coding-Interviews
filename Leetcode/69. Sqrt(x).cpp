
#include <bits/stdc++.h>
using namespace std;

// :: Requirement gathering techniques
// Binary Search [1 to 8]
// Sorted order - try to used apply binary search on answer 

// runtime error: signed integer overflow: 1073697799 * 1073697799 cannot be represented in type 'int'

class Solution {
    public:
        int mySqrt(int x) {
    
             long long int start = 0;
             long long int end = x;
             int target = x;
             long long int mid = start + (end-start)/2;
             
             int result = -1;
             while(start <= end){
                 if(mid * mid == target){
                    return mid;
                 }else if(mid * mid < target){
                    result = mid;
                    start = mid + 1;
                 }else{
                    end = mid - 1;
                 }
                 mid = start + (end-start)/2;
             }
             return result;
        }
    };