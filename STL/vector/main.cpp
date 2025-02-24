#include <iostream>
#include <vector>
using namespace std;

// Vectors are like arrays, but they can grow and shrink in size
// Vectors are declared like this:
// vector<type> name;
// type is the type of the elements in the vector
// Why we need vector, if we have alredy array, array is not dynamic, it is static
// Vectors are dynamic, they can grow and shrink in size
// Vectors help to solve many Leetcode problems

// # need to master (basic) always helps to solve complex problems
// # vector with integer
// # vector with char
// # vector with string
// # vector with vector (2-matrix)

int main() {
  // all power is within you, you can do anything you want, and everything you want.
  //#- vector with integer
  vector<int> container;
  container.push_back(1);
  container.push_back(2);
  container.push_back(3);
  container.push_back(4);
  container.push_back(5);

  // size and capacity of the vector
  cout << container.size() << endl;
  cout << container.capacity() << endl;
  
  cout << "first element -> " << container[0] << endl;
  cout << "second element -> " << container[1] << endl;
  cout << "thrid element -> " << container[2] << endl;
  cout << "fourth element -> " << container[3] << endl;
  cout << "fifth element -> " << container[4] << endl;

  // pop the element into vector 
  // remove all element into the vector 
  container.pop_back();
  container.pop_back();
  container.pop_back();
  container.pop_back();
  container.pop_back();

  cout << "current size of vector -> " << container.size() << endl;
  cout << "current capacity of vector -> " << container.capacity() << endl;
  cout << "current first element -> " << container[0] << endl;

  cout << endl;
  // insert new elements 
  container.push_back(112);
  container.push_back(123);
  container.push_back(19191);
  container.push_back(19191);
  container.push_back(101011);

  int current_size = container.size();
  for(int currIndex = 0; currIndex < current_size; currIndex++){
    cout << container[currIndex] <<  " ";
  }
  cout << endl;

  cout << "front element of vector -> " << container.front() << endl;
  cout << "back element of vector -> " << container.back() << endl;

  cout << endl;
  container.clear(); // clear all elements with null
  cout << "update size of container ->" << container.size() << endl;

  return 0;
} 



