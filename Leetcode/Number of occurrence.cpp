// Number of occurrence

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int binarySerachFirstPosition(vector<int> & arr, int target){
         int start = 0;
         int end = arr.size() - 1;
         int mid = start + (end-start)/2;
         int result = -1;
         
         while(start <= end){
             if(arr[mid] == target){
                 result = mid;
                 end = mid - 1;
             }else if(arr[mid] < target){
                 start = mid + 1;
             }else{
                 end = mid - 1;
             }
             mid = start + (end-start)/2;
         }
         return result;
    }
    int binarySerachLastPosition(vector<int> & arr, int target){
         int start = 0;
         int end = arr.size() - 1;
         int mid = start + (end-start)/2;
         int result = -1;
         
         while(start <= end){
             if(arr[mid] == target){
                 result = mid;
                 start = mid + 1;
             }else if(arr[mid] < target){
                 start = mid + 1;
             }else{
                 end = mid - 1;
             }
             mid = start + (end-start)/2;
         }
         return result;
    }
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first = binarySerachFirstPosition(arr,target);
        int last =  binarySerachLastPosition(arr,target);
        
        if(first == -1 && last == -1){
            return 0;
        }
        return last - first + 1;
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}