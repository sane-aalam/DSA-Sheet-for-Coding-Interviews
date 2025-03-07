
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
    
        // step-1 apply sieve algorithm to get all primse numbers
        // step-2 collect all primes numbers
        // step-3 : suppose there is no primses more than 2 return [-1,-1];
        // step-4 : Find the closest prime pair   
    
            int n = right;
            vector<int> containerPrime(n+1,true);
            containerPrime[0] = false;
            containerPrime[1] = false;
    
            for(int i = 2; i * i <= n; i++){
                if(containerPrime[i] == true){
                    for(long long int j = i * i; j<=n; j+=i){
                        containerPrime[j] = false;
                    }
                }
            }
    
            vector<int> prime;
            // :: get the all prime which range [left to right]
            for(int i = left; i<= right; i++){
                if(containerPrime[i] == true){
                   prime.push_back(i);
                }
            }
            
            if(prime.size() < 2){
                return {-1,-1};
            }
    
            // final step to solve this problems to get the minimum gap between number numbers
              int minGap = INT_MAX;
              int num1 = -1;
              int num2 = -1;
              for(int i = 1; i<prime.size(); i++){
                   int a = prime[i-1];
                   int b = prime[i];
                   int gap = b - a;
                   if(gap < minGap){
                       minGap = gap;
                       num1 = a;
                       num2 = b;
                   }
              }
              return {num1,num2};
    
        }
    };