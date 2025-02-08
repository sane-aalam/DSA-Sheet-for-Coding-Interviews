
#include <bits/stdc++.h>
using namespace std;

//* basic solution

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         int n = nums.size();
         
         // Simple Appraoch to solve this :: -
         // this approach takes time 0(n2)
         // sapce complexity of algorithm to solve this problem 0(1)
         // time complexity of algorithm to solve this problem 0(n2);
         for(int currindex = 0; currindex < n; currindex++){
             int currElement = nums[currindex];
             for(int nextindex = currindex + 1; nextindex < n; nextindex++){
                 int nextElementEqual = nums[nextindex];
                 if(currElement == nextElementEqual){
                    return true;
                 }
             }
         }
         
         // When you have traversal the complete array
         // Then you need to return the result false;
         // there is not duplicate present into the array
         return false;
    }
};

//* hashmap solution

// Time Limit Exceeded 
// To reduce the complexity of algorithm, we need to use HASHMAP,
// 1. Store the frequency of each elements
// 2. If Any element frequency is more than 2
// 3. Which means Array contains duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         // create the unordered_map
         unordered_map<int,int> DuplicateChecker;

         for(int i = 0; i < nums.size(); i++){
            // current of the array, store into map (data structure)
            // store into map.
             int element = nums[i];
             DuplicateChecker[element]++;
             // at anycase, map have frequency of element is more than 1.
             // any value appears at least twice times into the array, have duplicate the array 
             if(DuplicateChecker[element] > 1){
                return true;
             }
         }
         return false;
    }
};

//* best solution 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      
        // 1 <= nums.length <= 105
        // i can understand, i need to sort the array
        // currentElement, prevElement they both are Equal, which means have duplicate the element
        sort(nums.begin(), nums.end());
        for(int currindex = 1; currindex < nums.size(); currindex++){
             int currElement = nums[currindex];
             int prevElement = nums[currindex-1];

             if(prevElement == currElement){
                return true;
             }
        }
        return false;
    } 
};

// Time complexity of algorithm - 0(nlogn) + 0(n)
// Space complexity of algorithm - 0(1)