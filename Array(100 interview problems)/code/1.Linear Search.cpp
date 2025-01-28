#include <bits/stdc++.h>
using namespace std;

/**
 * Algorithm of problem -
 *  Time complexity of problem statement - 0(N)
 *  Space Compleixty of problem statement - 0(1)
 */

class Solution {
  public:
    int LinearSearch(vector<int> &arr) {
        int target = 11;
        // traversal of array using for loop
        for(int currentindex = 0; currentindex < arr.size(); currentindex++){
            if(arr[currentindex] == target){
                return currentindex;
            }
        }
        
        return -1;
    }
};