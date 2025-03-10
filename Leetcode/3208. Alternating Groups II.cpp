

#include<bits/stdc++.h>
using namespace std;

// K window)):
// Maintain two pointers: left and right, where right iterates over the array.
// If two consecutive elements are the same, reset left = right, breaking the alternating sequence.
// Whenever the window size reaches at least k, count it as a valid alternating group.

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            // update colors array, remove the cycle graphs 
            
            colors.insert(colors.end(), colors.begin(), colors.begin() + (k - 1));
            int count = 0;
            int left = 0;
    
            for(int right = 0; right < colors.size(); right++){
                if(right > 0 && colors[right] == colors[right-1]){
                    left = right;
                }
                // hit the window size 
                if(right - left + 1 >= k){
                    count++;
                }
            }
            return count;
        }
    };