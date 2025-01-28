

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int firstLargestElement = -1;
        int secondLargestElement = -1;
        int N = arr.size();

        for(int currentIndex = 0; currentIndex < N; currentIndex++){
            int currentElement = arr[currentIndex];
            if(currentElement > firstLargestElement){
                secondLargestElement = firstLargestElement;
                firstLargestElement = currentElement;
            // current number is smaller to firstElement
            // but greater than secondNumber, which means we have to update number
            }else if(currentElement < firstLargestElement && currentElement > secondLargestElement){
                secondLargestElement = currentElement;
            }
        }
        return secondLargestElement;
    }
};