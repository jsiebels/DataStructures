#include <iostream>

/*

  Finish the recursive function:
  
  int recursiveDiffs( int arr[], int start, int end)

  Note that "start" and "end" are inclusive, so that an array with 8 values ranges from 0 through 7.

  Your function should call itself, dividing the inclusive start->end range in half, 
  until there are only 2 (or 1) members left in the range.

  Use the equation (start+end)/2 to produce a truncated integer result which represents the midpoint of the array. 
  Example: an array of size 8 will have its midpoint at (0 + 7 ) / 2 = 3 (truncated integer result of 3.5).  NOT 4!

  *** Include the midpoint of the array in the LEFT HAND side of your recursive calls ***
  
  Then, using a "bottom up" recursive strategy, return the difference between each successive pair of numbers, until a final single number is found and returned to main().

  In the examples below, note that each pair of parenthesis indicates a recursive call that divides the range in half
  Note also that in some cases, there will be only a single member left as the result of a divison. 
  In this special case, simply return the single value, since a difference cannot be taken.

  Test A: 
  int arr[ 8 ] = { 3, 6, 7, 5,    3, 5, 6, 2 } ;  // array midpoint is position 3
  Your function should return  ( ( (3-6) - (7-5) )   -  ( (3-5) - (6-2) ) )  == 1 (final answer)

  Test B:
  int arr[ 11 ] = { 3, 6, 7, 5, 3, 5,    6, 2, 9, 1, 4 } ;
  Your function should return  ( ( (3-6) - (7) ) - ( (5-3)- (5) )  - (( (6-2) - (9)) - (1-4)  ) ) == -5 (final answer)

  */

using namespace std;

// arr[] is the input array of data
// your function should process from start to end, inclusive
int recursiveDiffs( int arr[], int start, int end){
  int mid = (start + end) / 2;
  if(start == end){
    return arr[start];
  }

  int leftSide = recursiveDiffs(arr, start, mid);
  int rightSide = recursiveDiffs(arr, mid+1, end);
  
  return (leftSide - rightSide); // you will need to replace this
}


int main() { 

  int N;

  // Test A
  N = 8;
  int testA[ 8 ] = { 3, 6, 7, 5,    3, 5, 6, 2 } ;  // array midpoint is position 3
  cout << "\nTest A: here are your numbers: " << endl;
  for (auto item : testA)  cout << item << ", ";  cout << endl;
  cout << "Your Test B answer is " << recursiveDiffs(testA, 0, N-1 ) << endl;
  cout << "The correct answer should be 1" << endl;

  // Test B
  N = 11;
  int testB[  ] = { 3, 6, 7, 5, 3, 5,    6, 2, 9, 1, 4 } ;

  cout << "\nTest B: here are your numbers: " << endl;
  for (auto item : testB)  cout << item << ", ";  cout << endl;
  cout << "Your Test B answer is " << recursiveDiffs(testB, 0, N-1 ) << endl;
  cout << "The correct answer should be -5" << endl;
}