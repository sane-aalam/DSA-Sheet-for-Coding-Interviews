
// 7 min to solve this problems
// think about only 1 rotation,then you need to think about 2 rotation, then you need to think about k....
// best way to solve this problem, think smaller problem

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void reverseMethod(vector<int> & arr, int start, int end){
        // swapping elements method
         while(start<end){
           int temp = arr[start];
           arr[start] = arr[end];
           arr[end] = temp;
           start++;
           end--;
       }
    } 
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        // revere the complete array
        // reverse the 0-k 
        // reverse the k-n 
        reverseMethod(nums,0,n -1); // entire array reverse 
        reverseMethod(nums,0,k-1);  
        reverseMethod(nums,k,n - 1);
    }
};