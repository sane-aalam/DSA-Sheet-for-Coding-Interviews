#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2){

        // base case:
        // if both even => everything will be zero
        // don't do anythings return 0 directly
        if (nums1.size() % 2 == 0 && nums2.size() % 2 == 0){
            return 0;
        }

        // approach : 
        int FirstXorArray = nums1[0];
        for(int i = 1; i < nums1.size(); i++){
            FirstXorArray = FirstXorArray ^ nums1[i];
        }

        int secondXorArray = nums2[0];
        for(int i = 1; i < nums2.size(); i++){
            secondXorArray = secondXorArray ^ nums2[i];
        }

        if(nums1.size() % 2 == 1 && nums2.size() % 2 == 1){
            return FirstXorArray ^ secondXorArray;
        }

        if(nums1.size() % 2 == 1){
            return secondXorArray;
        }else{
            return FirstXorArray;
        }
    }
};