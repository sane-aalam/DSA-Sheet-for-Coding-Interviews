

// 3190. Find Minimum Operations to Make All Elements Divisible by Three

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int count = 0;
         for(int i = 0; i<nums.size(); i++){
            // are not divisble by 3,
            // which means we need 1 operation
            if(nums[i] % 3 != 0){
                count++;
            }
         }
         return count;
    }
};
