
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

       // NthNaturalNumber - totalSumOfArray 
       // will be result using 0(1) space complexity.
       int n = nums.size();
       int NthNaturalNumber = (n*(n+1))/2;
       int sumNthNumber = 0;

       for(int currindex = 0; currindex < nums.size(); currindex++){
         sumNthNumber += nums[currindex];
       }

       return NthNaturalNumber - sumNthNumber;
    }
};