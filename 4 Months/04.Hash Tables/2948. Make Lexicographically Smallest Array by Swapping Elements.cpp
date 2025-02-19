
// 1. lexicographically a < b < c
// 2. lexicographical order we need to need to sprate the group
// note - countinous element difference always would be same 5,6,7 difference will be .
// 3. create the group on the basic of nums[i] - nums[i-1] > limit(which we need new group)
// 4. group me element store karna hoga, need MAP to store the elemnts
// 5. finally on the basic of nums[i], we need take out the element into the map data stucture to get the final answer 

// Queue + Map + Groups(countinous elements)
// Kya is group me belong karta hai ya nahi 
// agar krta hai, to sahi same group me aa ja
// otherwise tu appna new group bana (groupNumber++)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
         int n = nums.size();
         vector<int> arr = nums;
         // sort the array
         sort(arr.begin(),arr.end());
         unordered_map<int,int> mapping;
         // need to do countinous element mapping 1,2,3,4,5,6

        int groupNumber = 0;
        // to create different group using countious elements 
        vector<queue<int>> groupList;
        groupList.push_back(queue<int>());

        // need to push first element of sorted array for start the process (creation of groups)
        groupList[groupNumber].push(arr[0]);
        // set the element into the map at groupNumber this.
        mapping[arr[0]] = groupNumber;

        for(int i = 1; i<n; i++){
            // if abs differenece will be greater then limit, which means we need a new group 
            int diff = abs(arr[i] - arr[i-1]);
            if(diff > limit){
                groupNumber++;
                 groupList.push_back(queue<int>());
            }

            // else same me add kar do
            // need to push first element of sorted array for start the process (creation of groups)
            // set the element into the map at groupNumber this.
                mapping[arr[i]] = groupNumber;
                groupList[groupNumber].push(arr[i]);
        }  

        // result : 
        // get out the element into lexicographically smaller (order), first take smallest element then pop it.
        vector<int> result;
        for(int i = 0; i<n; i++){
            int element = nums[i];
            int group = mapping[element];
            // take the front element of group list
            result.push_back(groupList[group].front());
            // pop it 
            groupList[group].pop();
        }

        // return : 
        return result;
    }
};