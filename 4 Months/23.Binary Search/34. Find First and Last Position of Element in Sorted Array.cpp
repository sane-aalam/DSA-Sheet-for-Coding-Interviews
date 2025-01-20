#include <bits/stdc++.h>
using namespace std;

// You must write an algorithm with O(log n) runtime complexity.
// Binary Search (sorted array)
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

class Solution {
private:
   // function to serach the first index of the sorted array 
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
         mid = start + (end-start)/2;
       }
       return findFirstIndex;
   }
   // function to search the last index of the sorted array 
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
         mid = start + (end-start)/2;
       }
       return findLastIndex;
   }
   // code start here..
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int startingIndex = FindfirstPosition(nums,target);
         int endingIndex = FindLastPosition(nums,target);
        //  return {startingIndex, endingIndex};
        vector<int> resultArray;
        resultArray.push_back(startingIndex);
        resultArray.push_back(endingIndex);
        // return the result array[-1,-1]
        return resultArray;   
    }
};