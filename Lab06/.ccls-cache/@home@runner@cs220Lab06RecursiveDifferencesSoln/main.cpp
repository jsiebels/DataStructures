#include <iostream>

/*

  Finish the recursive function:
  
  int recursiveDiffs( int arr[], int start, int end)

  Your function should call itself, dividing the inclusive start->end range in half, 
  until there are only 2 (or 1) members left in the range.

  Use the equation (start+end)/2 to produce a truncated integer result which represents the midpoint of the array.

  Include the midpoint of the array in the LEFT HAND side of your recursive calls
  
  Then, using a "bottom up" recursive strategy, return the difference between each successive pair of numbers, until a final single number is found and returned to main().

  In the examples below, note that each pair of parenthesis indicates a recursive call that divides the range in half
  Note also that in some cases, there will be only a single member left as the result of a divison. 
  In this special case, simply return the single value, since a difference cannot be taken.
  
  Example 1:
  int arr[4] = { 3, 6,   7, 5 }; 
  Your function should return ( (3-6)  -  (7-5) ) == -5 (final answer)
  
  Example 2:
  int arr[6] = { 3, 6, 7,   5, 3, 5 }; 
  Your function should return ( ( (3-6) - 7)   -   ( (5-3) - 5) ) == -4 (final answer)
  
  Example 3:
  int arr[ 7 ] = { 3, 6, 7, 5,    3, 5, 6 }; ;
  Your function should return  ( (3-6) - (7-5) ) - ( (3-5) - (6) ) == -2 (final answer)
  
  Example 4: 
  int arr[ 8 ] = { 3, 6, 7, 5,    3, 5, 6, 2 } ;
  Your function should return  ( (3-6) - (7-5) )   - ( ( (3-5) - (6-2) )  == 1 (final answer)

  Example 5:
  int arr[ 10 ] = { 3, 6, 7, 5, 3,   5, 6, 2, 9, 1 } ;
  Your function should return  ( ( (3-6) - (7-5) ) - 3 )  - (( (5-6) - (2-9) ) - 1 )  == -1 (final answer)

 

  */

using namespace std;

// arr[] is the input array of data
// your function should process from start to end, inclusive
int recursiveDiffs( int arr[], int start, int end){

  if (start == end ) return arr[start];
  
  if ( end-start == 2)
    return (arr[start]-arr[end]);

  int mid = (start+end)/2;

  return( recursiveDiffs( arr, start, mid) - recursiveDiffs( arr,mid+1, end)  );
}


int main() { 

  int N;
  cout << "how many numbers would you like to try? (8)";
  cin >> N;
  
  int arr[N];

  for (int i=0; i<N; i++) 
    arr[i] = rand()%10;

  cout << "here are your numbers: " << endl;
  for (auto item : arr) 
    cout << item << ", ";
  cout << endl;
  int answer = recursiveDiffs(arr, 0, N-1 );

  cout << "The final answer is " << answer << endl;
    

}