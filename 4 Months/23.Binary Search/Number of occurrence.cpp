
#include <bits/stdc++.h>
using namespace std;

class Solution {
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
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first = FindfirstPosition(arr,target);
        int Last = FindLastPosition(arr,target);

        if(first == -1 && Last == -1){
            return 0;
        }
        int totalNumberTimes = Last - first + 1;
        return totalNumberTimes;
    }
};