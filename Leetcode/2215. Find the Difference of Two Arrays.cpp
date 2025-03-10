
#include <bits/stdc++.h>
using namespace std;

// creating our HASH-SET ::
// PUSH_ALL_ELEMENTS INTO BOTH OF ARRAY INTO BOTH HASH-SET
unordered_set<int> setNums1;
unordered_set<int> setNums2;

// for (auto it : nums1)
// {
//     setNums1.insert(it);
// }

// for (auto it : nums2)
// {
//     setNums2.insert(it);
// }

// 2215. Find the Difference of Two Arrays

// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2
// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// push all elements into the set

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2){
        // thinking - check kar lena ek duse present ya nahi
        // agar present nahi, then we need to store it

        // unordered_set<int> setNums1(nums1.begin(), nums1.end());
        // unordered_set<int> setNums2(nums2.begin(), nums2.end())

        // Initialize a vector of vectors to store the unique elements from each set
        // a list answer of size 2
        vector<vector<int>> resultUniqeElements(2);

        // checking first array element present into the second array
        for (auto num : setNums1){
            // not present into the array
            if (setNums2.count(num) == 0){
                resultUniqeElements[0].push_back(num);
            }
        }

        // checking second array element present into the first array
        for (auto num : setNums2){
            // not present into the array
            // setnum1(SET), current_Number hay, uska counter 0,which means this is unique value
            if (setNums1.count(num) == 0){
                resultUniqeElements[1].push_back(num);
            }
        }

        // return result
        return resultUniqeElements;
    }
};