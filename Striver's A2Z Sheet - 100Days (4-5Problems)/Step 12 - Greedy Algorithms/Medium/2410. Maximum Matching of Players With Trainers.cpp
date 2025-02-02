

// 2410. Maximum Matching of Players With Trainers
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
         int n = players.size();
        int m = trainers.size();

        // sort the array both::
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int left = 0;
        int right = 0;
        while(left < n && right < m){
             if(players[left] <= trainers[right]){
                left++;
             }
             right++;
        }
        return left;
    }
};