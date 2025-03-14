#include <bits/stdc++.h>
using namespace std;

// solved 20 min this problem 

// Maximum Candies Allocated to K Children - Book Allocation [pattern] - Binary serach on anwser
// array candies + k number of children 
// Return the maximum number of candies each child can get.

// Point which help to solve this problem -
// each child gets the same number of candies
// Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

// 💬 | Chat
// start = 0;
// end = number os candies array [max candy]
// mid = start + end/2;
// Try all possible to allocate of NOT

class Solution {
    private:
       int PossibleToAllocate(vector<int>& candies, long long k, int divide){
             
            long long countAllocateNumber = 0;
    
            for(auto subPiles : candies){
                countAllocateNumber = countAllocateNumber + subPiles/divide;
            }
    
            if(countAllocateNumber >= k){
                return true;
            }
            return false;
       }
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            
         int maximumElement = INT_MIN;
         for(int currindex = 0; currindex < candies.size(); currindex++){
             if(maximumElement < candies[currindex]){
                maximumElement = candies[currindex];
             }
         }
    
         // Binary search on answer concpet
         int start = 1;
         int end = maximumElement;
         int mid = start + (end-start)/2;
    
         // by default - test case-2 according you are not able to allocate take 0.
         int result = 0;
         
         // It is possible to allocate or NOT
         while(start <= end){
            if(PossibleToAllocate(candies,k,mid) == true){
                result = mid;
                // we have to maximize the number
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end-start)/2;
         }
         return result;
        }
    };
    
    
    
    
    