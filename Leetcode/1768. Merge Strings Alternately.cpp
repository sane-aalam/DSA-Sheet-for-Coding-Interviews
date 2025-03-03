

// Brain-open
// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, 
// starting with word1. If a string is longer than the other, 
// append the additional letters onto the end of the merged string.
// Return the merged string.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            int n = word1.size();
            int m = word2.size();
    
            int maxsize = max(n,m);
            string result = "";
        
        // the merged string will be merged as so:
            for(int i = 0; i<maxsize; i++){
                if(i < n){
                    result.push_back(word1[i]);
                }
                if(i < m){
                    result.push_back(word2[i]);
                }
            }
            return result;
        }
    };