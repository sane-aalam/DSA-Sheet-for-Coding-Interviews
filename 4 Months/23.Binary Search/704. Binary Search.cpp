
#include <bits/stdc++.h>
using namespace std;

// TC - 0(logN)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int startIndex = 0;
        int endIndex = nums.size() - 1;
        // calculate the middle index!
        int mid = startIndex + (endIndex - startIndex)/2;
        while(startIndex <= endIndex){
              if(nums[mid] == target){
                 return mid;
              }else if(nums[mid] < target){
                 startIndex = mid + 1;
              }else{
                 endIndex = mid - 1;
              }
              mid = startIndex + (endIndex - startIndex)/2;
        }
        return -1;
    }
};