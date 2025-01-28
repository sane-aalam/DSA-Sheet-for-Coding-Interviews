#include <bits/stdc++.h>
using namespace std;

/**
 * Algorithm of problem -
 * 1. consider first element as largest element into the array
 * 2. Go entire the array, search the element
 * 3. currentElement of array is greater than largestElement,
 * 4. Then we need to update the LargestElement of Array.
 * 5. Time complexity of problem statement - 0(N)
 * 6. Space Compleixty of problem statement - 0(1)
 */

class Solution {
  public:
    int largest(vector<int> &arr) {

        int largestElement = arr[0];
        for(int currentindex = 0; currentindex < arr.size(); currentindex++){
            if(arr[currentindex] > largestElement){
                largestElement = arr[currentindex];
            }
        }
        
        return largestElement;
    }
};