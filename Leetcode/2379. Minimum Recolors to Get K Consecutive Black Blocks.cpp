



// Bruthforce - max consectuive ones (easy leetcode) failed old pattern
// Optimization 
// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// When i read this problem clear, understand pattern
// Trying to hit the window size of K = [this is sliding window pattern] 
// solution - Try to get the minimum whiteballs to every window size 
// Hindi solution
// - har ek winodw size k me, we have to check out the how many numbers of whiteballs present 
// Input: blocks = "WBBWWBBWBW", k = 7
// here K size winodw , number of whiteball present of 3 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size();
    
            int left = 0;
            int right = 0;
            int minimumOperation = INT_MAX;
            int whiteballCount = 0;
    
            while(right < n ){
                // do your work
                if(blocks[right] == 'W'){
                    whiteballCount++;
                }
    
                // hit the window size of K.
                if(right - left + 1 == k){
                    minimumOperation = min(minimumOperation,whiteballCount);
                      // undo your work, left side you need to decrement the count of whiteballs, 
                      // reason : you have to consider the NEW-WINDOW SIZE OF K
                    if(blocks[left] == 'W'){
                        whiteballCount--;
                    } 
                    left++;
                }
    
                right++;
            }
            return minimumOperation;
        }
    };