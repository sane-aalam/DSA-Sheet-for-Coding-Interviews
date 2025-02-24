#include <iostream>
#include <vector>
using namespace std;

int main() {

  vector<char> CharacterVector;

  // push all char into the container(char) vector
  CharacterVector.push_back('a');
  CharacterVector.push_back('b');
  CharacterVector.push_back('c');
  CharacterVector.push_back('d');
  
  // pop all char element into the container(char) vector
  CharacterVector.pop_back();
  CharacterVector.pop_back();
  CharacterVector.pop_back();
  CharacterVector.pop_back();

  return 0;
} 
