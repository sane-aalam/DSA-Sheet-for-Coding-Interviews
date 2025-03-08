
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
             
            // 1 <= nums.length <= 105
            // There is no need to start with INT_MIN,reason is number is always start with 1 < 105 
             int maxConsecutiveOnes = 0;
             int currConsecutiveOnes = 0;
    
             for(int currindex = 0; currindex < nums.size(); currindex++){
                 if(nums[currindex] == 1){
                    currConsecutiveOnes++;
                    maxConsecutiveOnes = max(currConsecutiveOnes,maxConsecutiveOnes);
                 }else{
                    // whenever break the chain of consecutive 1's then we have to re-start the process of counting the consecutive 1's 
                    currConsecutiveOnes = 0;
                 }
             }
             return  maxConsecutiveOnes;
        }
    };