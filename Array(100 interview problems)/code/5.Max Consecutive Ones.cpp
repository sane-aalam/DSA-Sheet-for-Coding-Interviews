

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int currentCountOnes = 0;
         int maximumCountOnes = 0;

         for(int index = 0; index < nums.size(); index++){
             if(nums[index] == 1){
                currentCountOnes = currentCountOnes + 1;
                if(maximumCountOnes < currentCountOnes){
                    maximumCountOnes = currentCountOnes;
                }
             }else if(nums[index] == 0){
                currentCountOnes = 0;
             }
         }
         // return number of consectutive one'1 int the array 
         return maximumCountOnes;
    }
};