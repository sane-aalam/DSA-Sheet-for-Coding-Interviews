

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countPrimes(int n) {
    
            if(n <= 1) 
               return false;
            // Seive algorithm to get prime primes
            // Sieve of Eratosthenes
            vector<int> containerPrime(n+1,true);
            containerPrime[0] = false;
            containerPrime[1] = false;
    
            for(int i = 2; i * i < n; i++){
                if(containerPrime[i] == true){
                    for(long long int j = i * i; j<n; j+=i){
                        containerPrime[j] = false;
                    }
                }
            }
    
            int count = 0;
            for(int i = 0; i<n; i++){
                if(containerPrime[i] == true){
                    count++;
                }
            }
            return count;
        }
    };