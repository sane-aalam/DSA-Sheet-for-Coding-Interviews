

// contest failed - TLE
#include <bits/stdc++.h>
using namespace std;

class Solution { 
    public: 
        bool isvowel(char ch){ 
            return ch=='a' or  ch=='e' or ch=='i' or  ch=='o' or ch=='u'; 
        } 
        long long countOfSubstrings(string word, int k) { 
            int n=word.size(); 
            int count =0; 
            
            unordered_set<char>vowel; 
            int consonantsCount =0; 
            int i=0; 
            for(int j=0;j<n;j++){ 
                if(isvowel(word[j])){ 
                    vowel.insert(word[j]); 
                } 
                else{ 
                   consonantsCount ++;  
                } 
    
            // window size exeeds,then need to remove it both of them into window
                while(consonantsCount >k){ 
                    if(isvowel(word[i])){ 
                        vowel.erase(word[i]); 
                    } 
                    else{ 
                       consonantsCount--;  
                    } 
                    i++; 
                } 
                if(vowel.size() == 5 && consonantsCount==k){ 
                count ++; 
                } 
            } 
            return count ; 
        } 
    };