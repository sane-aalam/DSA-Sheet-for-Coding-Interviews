
// Problem Name - 169. Majority Element
// Understand Problem statement -
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Number which appear more than n/2 times.

// Appraoch-1 : Brute Force Approach
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {

        // your code here
        int n = arr.size();
        int resultElement;

        for (int i = 0; i < n; i++){
            int pickElement = arr[i];
            int count = 0;
            // Count the nubmer of times, which element came more than n/2 times
            for (int j = 0; j < n; j++){
                int currentElement = arr[j];
                if (pickElement == currentElement)
                {
                    count++;
                }
            }

            if (count > n / 2){
                resultElement = pickElement;
            }
        }
        return resultElement;
    }
};

// Approach-2: Sorting Approach
// By sorting the array, the majority element must be at the position n/2, provided a zero-based index.
// You can take DryRun.

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        // your code here
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// Appraoch-3 : Hash Map Approach
// We are trying to find out,which element have more fequency,which is greater than n/2 times
// So Can we store the frequency of elements
// Need to store FREQENCY - map (data strucutre)
// Map (map,unordered_map,ordered_map)

// Which one is fast? (question asked in interviews)
// 1.unordered_map -
// This is the go-to for most cases. It provides O(1) average-case lookup, insertion, and deletion, making it the fastest option when you don't need ordered keys.
// 2. MAP:
// If you need your keys to be sorted, std::map offers O(log n) operations, which is still quite fast for many situations.

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        // your code here
        unordered_map<int, int> mapContianer;

        // store freqency of each element
        // 2 -> 3 times
        // 1 -> 2 times
        // 4 -> 5 times
        for (int index = 0; index < nums.size(); index++){
            mapContianer[nums[index]]++;
        }

        int majorityElement = -1;
        for (auto &it : mapContianer) {
            int element = it.first;
            int freq = it.second;

            // Which element have more frequency update the element
            if (freq > nums.size() / 2){
                majorityElement = element;
                break;
            }
        }
        return majorityElement;
    }
};

// Appraoch-4 : Boyer-Moore Voting Algorithm
    // inorder to reduce the space complexity of the code
    // we can use "MORE VOTING ALGORITHM"
    // 1. declare the firstCandidate,With count = 1
    // 2. if you got same vote,Then incease the count
    // 3. if you not got same vote,Then decease the count 
    // 4. repeat the process 

class Solution {
public:
    int majorityElement(vector<int>& nums) {

         int arraySize = nums.size();
         int majorityElementCandidate = 0;
         int count = 0;

         for(int index = 0; index < arraySize; index++){
           // assign new candidate using vote-1 
           // if next candidate is equal count++ otherwise count--
             if(count == 0){
                count = 1;
                majorityElementCandidate = nums[index];
             }else if(majorityElementCandidate == nums[index]){
                count++;
             }else{
                count--;
             }
         }

         int majorityElementNumberTimes = 0;

         for(int index = 0; index < arraySize; index++){
             if(nums[index] == majorityElementCandidate){
                majorityElementNumberTimes ++;
             }
         }      

         // The majority element is the element that appears more than ⌊n / 2⌋ times.
         if(majorityElementNumberTimes > arraySize/2)
            return majorityElementCandidate;
    
         return -1;
    }
};

