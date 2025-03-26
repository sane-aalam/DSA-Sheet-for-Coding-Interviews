#include <bits/stdc++.h>
using namespace std;

// modificaiton of binary search algo-
// will continue search left,right side
// until reached target value 

class Solution {
    private:
       int FindfirstPosition(vector<int> & nums,int target){
           int start = 0;
           int end = nums.size() - 1;
           int mid = start + (end-start)/2;
           int findFirstIndex = -1;
           
           while(start <= end){
             if(nums[mid] == target){
                 findFirstIndex = mid;
                 end = mid - 1;
             }else if(nums[mid] < target){
                start = mid + 1;
             }else{
                end = mid -1 ;
             }
             // update the middle index 
             mid = start + (end-start)/2;
           }
           return findFirstIndex;
       }
       int FindLastPosition(vector<int> & nums,int target){
         int start = 0;
           int end = nums.size() - 1;
           int mid = start + (end-start)/2;
           int findLastIndex = -1;
           
           while(start <= end){
             if(nums[mid] == target){
                 findLastIndex = mid;
                 start = mid + 1;
             }else if(nums[mid] < target){
                start = mid + 1;
             }else{
                end = mid -1 ;
             }
             // update the middle index 
             mid = start + (end-start)/2;
           }
           return findLastIndex;
       }
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
             int startingIndex = FindfirstPosition(nums,target);
             int endingIndex = FindLastPosition(nums,target);
             return {startingIndex, endingIndex};
        }
    };