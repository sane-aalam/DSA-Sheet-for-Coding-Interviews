
#include <bits/stdc++.h>
using namespace std;

// We have to search index, in which locaiton we can insert the element.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         int start = 0;
         int end = nums.size() - 1;
         int mid = -1;
         while(start <= end){
            // calculate the middle index of array 
            mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
         }
         return start;
    }
};