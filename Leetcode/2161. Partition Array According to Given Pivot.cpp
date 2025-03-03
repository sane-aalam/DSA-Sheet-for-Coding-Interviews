

#include <bits/stdc++.h>
using namespace std;

// BruthForce (came into my-mind)
// Time complexity: - (O(n)), as we traverse the array only once.
// Space complexity:- (O(n)), since we use an additional array of size (n).
// We are running 3 for loop (3-pass solutions)


class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
             vector<int> lessArray;
             vector<int> greaterArray;
             vector<int> pivotArray;
             int sizeArray = nums.size();
    
             for(int currindex = 0; currindex < sizeArray; currindex++){
                 int currElement = nums[currindex];
                 if(currElement < pivot){
                    lessArray.push_back(currElement);
                 }else if(currElement > pivot){
                    greaterArray.push_back(currElement);
                 }else{
                    pivotArray.push_back(currElement);
                 }
             }
    
             // let's rearrangement the array elements 
             // The relative order of the elements less than pivot and the elements greater than pivot is maintained.
    
             for(auto equal : pivotArray){
                lessArray.push_back(equal);
             }
    
             for(auto great : greaterArray){
                lessArray.push_back(great);
             }
    
             // return ans
             return lessArray;
        }
    };

// 1 Pass Solution – Optimized Approach! || Beats 100% 🚀
// Two pointer algorithm 
// [start,end] fill array result

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
             int n = nums.size();
    
            // fill entire array using pivot element
            // Every element less than pivot appears before every element greater than pivot.
            // on the basic of conditon, you need to insert element [STARTING_POSITON]
            // On the basic of conditon, you need to insert element [ENDING_POSITION]
             vector<int> result(n,pivot);
    
             int start = 0;
             int end = n - 1;
             for(int index = 0; index < n; index++){
                int endindex = n-1-index;
                // insert start 
                if(nums[index] < pivot)
                    result[start++] = nums[index];
                    
                // insert end 
                if(nums[endindex] > pivot){
                    result[end--] = nums[endindex];
                }
             }
             return result;
        }
    };