
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int square, int currentsum, int num){
        if(square == 0){
            return currentsum == num;
        }
        // currentSum is greater than num
        // 96 > 36 which means not possible to the sum of the integer values of these substrings equals i.
        if(currentsum > num){
            return false;
        }

        // extaction of digit + recursion 
        // Try all possible to divide the number get the sum of the integer values which equal to i(num)
        return solve(square/ 10, currentsum + square % 10, num) || 
                solve(square/ 100, currentsum + square % 100, num) ||
                solve(square/ 1000, currentsum + square % 1000, num) ||
                solve(square/ 10000, currentsum + square % 10000, num);
    }
public:
    int punishmentNumber(int n) {
        int punishmentNum = 0;

        for(int num = 1; num <= n; num++){
            // creating the square value of each number 
            int squareNumber = num * num;
            if(solve(squareNumber,0,num) == true){
                punishmentNum += squareNumber;
            }
        }
        return punishmentNum;
    }
};