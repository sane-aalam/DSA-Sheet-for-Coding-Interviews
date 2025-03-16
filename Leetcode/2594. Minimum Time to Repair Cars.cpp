
// Summary to understand problem (100%) 💬
// You are given an integer array ranks representing the ranks of some mechanics
// A mechanic with a rank r can repair n cars in r * n2 minutes.
// You are also given an integer cars N = 10
// Return the minimum time taken to repair all the cars.
// All the mechanics can repair the cars simultaneously.

// Think clear - past problem which you have solve it 
// Bruthforce - i need to allocate all cars to all machanic, try to get minimum time reapir all the cars
// Optimization - (all maximum time to repair), WE_HAVE_TO_GET Minimize the time 


#include <bits/stdc++.h>
using namespace std;

class Solution {
    private: 
        bool isPossibleToRepairCars(vector<int> & ranks, long long time,int totalGivenCars){
    
            long long carRepair = 0;
            // time = r * n2 
            // n2 = time/r
            // n = sqr(time/r)
            for(int index = 0; index < ranks.size(); index++){
                 carRepair += sqrt((time)/ranks[index]);
            }
    
            if(carRepair >= 1LL*totalGivenCars){
                return true;
            }
            return false;
        }
    public:
        long long repairCars(vector<int>& ranks, int cars) {
    
          // start with minimum time taken to reapir cars 
          // end with maximum time taken to repair cars
           long long maxiElement = 0;
    
           for(int currindex = 0; currindex < ranks.size(); currindex++){
               if(maxiElement < ranks[currindex]){
                  maxiElement = ranks[currindex];
               }
           }
    
           long long start = 1;
           long long end = maxiElement * cars * cars;
           long long result = 0;
           long long mid = start + (end-start)/2;
    
           while(start <= end){
            // It is possible to Repair Cars or NOT.
            // If it is possible to repair,we need to minimize the time to repair cars.
              if(isPossibleToRepairCars(ranks,mid,cars) == true){
                 result = mid;
                 end = mid - 1;
              }else{
                 start = mid + 1;
              }
              // update the mid value
              mid = start + (end-start)/2;
           }
           return result;
        }
    };