
// :: Requirement gathering techniques
// X axis and Y axis in Graph: Definition
// In the context of a 10th-grade chapter on coordinate geometry, the x-axis and y-axis form the foundation of the Cartesian coordinate system, a system used to locate points on a plane
// rectangles[i] is in the form [startx, starty, endx, endy],
// MEANS - [STARTINGPOINT, ENDINGPOINT] -> [0,0] [1,5]
// Note that the rectangles do not overlap.
// Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such
// Each of the three resulting sections formed by the cuts contains at least one rectangle.
// Every rectangle belongs to exactly one section.
// Return true if such cuts can be made; otherwise, return false.

// HOW TO THINK - [solution]
// 1'ST - horizontal cut try kara, not possible to cut horizontal because Every rectangle belongs to exactly one section.
// REASON Why not possible to cut - There are overlapping 
// overlapping - MERGE ho skte hai 
// 2'ST - Vertical cut try kara

// We can make two horizontal or(ya) two vertical cuts that satisfy the conditions. Hence, output is true.
// We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.

// There are overlapping [after merging intervals]
// 56. Merge Intervals 
// X-size() >= 3 or y-size() >=3 (result ka)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
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
                // Note that the rectangles do not overlap
                if(intervals[i][0] < result.back()[1]){
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
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>> horizontal;
            vector<vector<int>> vertical;
    
            for(auto &it : rectangles){
                 int x1 = it[0];
                 int y1 = it[1];
                 int x2 = it[2];
                 int y2 = it[3];
    
                  horizontal.push_back({x1,x2});
                 vertical.push_back({y1,y2});
            }
    
            vector<vector<int>> result1 = merge(horizontal);
            if(result1.size() >= 3){
                return true;
            }
            
            vector<vector<int>> result2 = merge(vertical);
            
            // possilbe to cut 
            // if it is possible to make either two horizontal or two vertical cuts on the grid such that:
            return (result1.size() >= 3 || result2.size() >= 3);
        }
    };
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    