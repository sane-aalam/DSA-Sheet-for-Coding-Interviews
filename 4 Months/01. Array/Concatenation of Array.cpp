
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // size of the array
        // we have to get out the size of the array 
        int n = nums.size();
        for(int i = 0; i<n; i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};