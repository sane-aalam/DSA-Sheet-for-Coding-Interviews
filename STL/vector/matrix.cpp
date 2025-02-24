#include <iostream>
#include <vector>
using namespace std;

int main() {

  vector<vector<int>> matrix;
  vector<int> v1 = {1, 2};
  vector<int> v2 = {4, 5};
  vector<int> v3 = {7, 8};

  /*
  1 2 
  4 5 
  7 8
  */

  // push 2-Matrix all 1-d array 
  matrix.push_back(v1);
  matrix.push_back(v2);
  matrix.push_back(v3);

  // traversal the matrix
  for (int row = 0; row < matrix.size(); row++) {
    for (int col = 0; col < matrix[row].size(); col++) {
      int cellElement = matrix[row][col];
      cout << cellElement << " ";
    }
  }
  cout << endl;

  // search element into matrix 
  int target = 5;
  for(int row = 0; row < matrix.size(); row++){
    for(int col = 0; col < matrix[0].size(); col++){
       int currentElement = matrix[row][col];
      if(currentElement == target){
         cout << "present element" << endl;
      }
    }
  }

  cout << "matrix element using index ->" << matrix[0][0] << endl;
  cout << "matrix element using index ->" << matrix[0][1] << endl;

  if(matrix[0][0] == matrix[0][1]){
    cout << "not equal" << endl;
  }

  return 0;
}
