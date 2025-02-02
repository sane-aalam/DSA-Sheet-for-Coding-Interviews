
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills){

// Each customer will only buy one lemonade and pay with either a $5, $10, or $20 
// bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise
// simple implementation of if-else statement of code 
// time complexity of problem - 0(N)
// space compleixty of problem - 0(n)

 int fiveDollarNoteCount = 0;
        int tenDollarNoteCount = 0;
        int twentyDollarNoteCount = 0;

        int n = bills.size();

        for(int index = 0; index < n; index++){
            int customerPay = bills[index];
            if(customerPay == 5){
                fiveDollarNoteCount++;
            }else if(customerPay == 10){
                if(fiveDollarNoteCount == 0){
                    return false;
                }else{
                // you need to give back 5 dolloar note
                    tenDollarNoteCount++;
                    fiveDollarNoteCount--;
                }
            }else if(customerPay == 20){
                // you have tendollar note and fiveDolloar give
                // both it combination of both of note dolloar
                // give it one 5 dolloar
                // give it one 10 dolloar 
                if(fiveDollarNoteCount >= 1 && tenDollarNoteCount >= 1){
                    fiveDollarNoteCount--;
                    tenDollarNoteCount--;
                    twentyDollarNoteCount++;
                }else if(fiveDollarNoteCount >= 3){
                    // fiveDollarNoteCount--;
                    // fiveDollarNoteCount--;
                    // fiveDollarNoteCount--;
                    // you have to give back three 5 dolloar note
                    fiveDollarNoteCount -= 3;
                     twentyDollarNoteCount++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};