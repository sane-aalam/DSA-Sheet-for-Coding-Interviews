// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// A happy string is a string that:
// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


#include<bits/stdc++.h>
using namespace std;

// Try all possible ways

class Solution {
    private:
       void solve(int n, string curr,vector<string> & result){
            // Base Condition
            // When you have create string which size equal to N.
            if(curr.size() == n){
                result.push_back(curr);
                return;
            }
    
            //* RECURSION + BACKTRACKING(GOOD PROBLEM)
            // do your work
            // on the basis of last char,we have to understand,insert the NewChar('a,b,c) or NOT
            // explore all possible ways
            // undo your work
            for(char ch = 'a'; ch <= 'c'; ch++){
                // curr-empty nahi hai
                // curr.back char (a) = (a) which means no need to insert it
                if(!curr.empty() && curr.back() == ch){
                    continue;
                }
                curr.push_back(ch);
                // explore it
                solve(n,curr,result); 
                // undo your work
                curr.pop_back();
            }
       }
    public:
        string getHappyString(int n, int k) {
        // creation of curr lexicographical string
            string curr = "";
        // Store all possible Lexicographical String of All Happy Strings of Length n
            vector<string> result;
        // Recursive function
            solve(n,curr,result);
            
        // Return the kth string of this list or return an empty string 
            if(result.size() < k){
                return "";
            }
            return result[k-1];
        }
    };