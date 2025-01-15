

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
         int n = A.size();
         // Hashmap,but vector works
         vector<int> freq(n+1,0);
         vector<int> c;

    // A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers 
    // we have to count the number of equal element both A,B have.
         int commonElement = 0;

         for(int i = 0; i<n; i++){

             freq[A[i]]++;
             if(freq[A[i]] == 2){
                commonElement++;
             }

             freq[B[i]]++;
             if(freq[B[i]] == 2){
                commonElement++;
             }
             // creation of the prefix common array
             c.push_back(commonElement);
         }

        //  Return the prefix common array,which have 
         return c;
    }
};