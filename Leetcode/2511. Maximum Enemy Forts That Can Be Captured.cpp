

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int captureForts(vector<int>& forts) {
            int left = 0;
            int right = 0;
            int maxCapture = 0;
            
            while(right < forts.size()){
                
                if(forts[right] == 1 || forts[right] == -1){
    
                    if( (forts[left] == 1 && forts[right] == -1) || (forts[left] == -1 && forts[right] == 1) ){
                        int diff = right - left + 1;
                        maxCapture = max(maxCapture, diff);
                    } 
                    left = right;
                }
                    
                right++;
            }
            return maxCapture;
        }
    };