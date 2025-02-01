
// There are two different parties- 
// Even number
// odd number

// if(num & 1 == 0 ) - even number
// if(num & 1 == 1 ) - odd number

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<n-1; i++){
            int prevElement = nums[i];
            int currElement = nums[i+1];

            int firstEven = prevElement % 2;
            int secondEven = currElement % 2;

            // both are same party, which means is not special array return false;
            if(firstEven == secondEven){
                return false;
            }
        }
        return true;
    }
};