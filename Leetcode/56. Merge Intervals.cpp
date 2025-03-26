
#include <bits/stdc++.h>
using namespace std;


// :: clear dekh raha hai
// first interval push into the result matrix to compare the overlapping or NOT overlapping 

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            
            // sort the an array of intervals where intervals[i] = [starti, endi], 
            // sort on basic of start value
            sort(intervals.begin(),intervals.end());
    
            int N = intervals.size();
    
            vector<vector<int>> result;
            // first interval push into the result matrix to compare the overlapping or NOT overlapping 
            result.push_back(intervals[0]);
    
            for(int i = 1; i<N; i++){
                // intervals first element,zada hai, result ke last element,which means they are overlapping hai
                if(intervals[i][0] <= result.back()[1]){
                    /* 
                        result.back()[0] = min(result.back()[0],intervals[i][0]); 
                        this line is not needed as we have already sorted the the intervals 2D vector. 
    
                    */
                    result.back()[1] = max(result.back()[1],intervals[i][1]);
                }else{
                    result.push_back(intervals[i]);
                }
            }
            return result;
        }
    };