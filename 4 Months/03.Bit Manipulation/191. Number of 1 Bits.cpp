#include <bits/stdc++.h>
using namespace std;

// When you do n&1 == 1 Then which means current bit 1 hay
// we have to track counter to count the number of 1's bits 

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){
            if(n & 1 ){
                count ++;
            }
            n = n / 2;
        }
        return count;
    }
};