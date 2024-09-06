#include <chrono>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

/*
  Please read the README.md file fully.

  Submission:  Along with a link to ths repl, remember to copy and fill out this
  google spreadsheet with your results:

  https://docs.google.com/spreadsheets/d/1gGLdji0SbLiGeoUvvcCdixevRXZ5XWg2hDedQvOxumA/edit?usp=sharing 

  Search for "TODO" below to determine where you will develop your code

*/

using namespace std; // select as standard library for main (CAVEAT: never use this in .h files or large projects!)

long swapCount = 0;					// used to keep track of swaps
long copyCount = 0;					// used to keep track of copies (like for insertion sort)
long compareCount = 0;				// used to keep track of compares
chrono::duration<double> time_span; // used to keep track of elapsed time

//
// myCompare ( written for you - you must use this instead of ==, >, < etc. ) 
// Compare two integer values (considered "1 comparison" for each call to this function)
// return -1, 0, or 1 to indicate if a is < ==, or > b
//
int myCompare(int a, int b) {
	compareCount++;
	if (a > b) 
		return 1; // a is greater
	if (a < b)
		return -1; // a is smaller
	return 0; // they must be equal
}

//
// arrSwap()  ( written for you - you must use this function any time you need to swap two array values. ) 
// swap the array value a[i] with the array value a[j] and increment counter
// assume that the array actually does have an i and j position
// (there is no return value to this function)

void arrSwap(int arr[], int i, int j) {  
  swapCount++; // increment the count of the number of swaps we have made
  int temp = arr[i];  // swap the i-th and j-th values in array a[]
  arr[i] = arr[j];
  arr[j] = temp;
}

void myCopy(int arr[], int i, int j) {  
  copyCount++; // increment the count of the number of copies we have made
  arr[j] = arr[i];  // copy the i-th value in array arr[] to position j
}

//
// PRINT Values (written for you)
// print the values of the array of a[ ] of size N, prefixed with the string message msg
//

void printValues(const char *msg, int a[], int N) {
	cout << msg << endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << ", ";
	cout << endl;
}

//
// PRINT STATS
// print statistics about the sort that was just performed
// this function assumes that the global variables swapCount, compareCount, and
// time_span have been altered during sorting.
//

void printStats(int N) {
	cout << "\nPrint Stats" << endl;
	cout << "--------------------------------------" << endl;
	cout << "For value N = " << N << endl;
	cout << "Total Swaps = " << swapCount << endl;
	cout << "Total Compares = " << compareCount << endl;
	cout << "Time Duration " << fixed << setprecision(10) << time_span.count()
		 << " seconds." << endl;
	cout << "Log(n) = " << log2(N) << "(for reference)" << endl;
	cout << "nLog(n) = " << N * log2(N) << "(for reference)" << endl;
	cout << "N^2 = " << (N) * (N) << "(for reference)" << endl;

// reset the counters, assuming we will be running anothertest after this function call
  compareCount = 0; 
	swapCount = 0;
}

//
// mySort()
// sort the values in the array a[ ] of size N in ascending order
//

void mySort(int a[], int N) {
  
	chrono::steady_clock::time_point start_time = chrono::steady_clock::now(); // start time )(please do not remove)

  
	// TODO Write your sort function here (you may write and call your own function FROM HERE, if you prefer)
  // NOTE: Be sure to use the myCompare( ) any time you compare two elements from the array a[]
  // NOTE: Be sure to use  arrSwap( ) any time you need to swap two array elements from a[]
  // NOTE: Be sure to use myCopy() any time you copy (or shift) and element to the right or left from a[]
  //       typically you will either swap, or copy, but rarely do both.

  

	chrono::steady_clock::time_point end_time = chrono::steady_clock::now(); // end time(please do not remove)

	time_span = chrono::duration_cast<chrono::duration<double>> (end_time - start_time); // duration (please do not remove)
} // end of mySort() function

//
// isSortedAscending() - called after sorting to verify results
// Determine if the elements of array a[ ] of size N are sorted in ascending order
//

bool isSortedAscending(int a[], int N) {
  
	for (int i = 0; i < N - 1; i++) {
    
		if (a[i] > a[i + 1]) // the order of these 2 are inverted, so the array is not ascending
			return false;
	}

	return true; // if we got this afar, the array must be sorted in ascending order
} // end isSortedAscending()



int main() {
	cout << "HW1:  mySort() \n";

	ofstream myFile("data.csv"); // open a data file to store our output data
	myFile << "N, Category, Count" << endl; // write "header" data the file

	for (int pwr = 1; pwr < 21; pwr++) { // power loop to grow N by doubling: 2, 4, 8, 16

		long N = pow(2, pwr); // size of array, 2 raised to a power

		int a[N]; // define array of N items

		for (int i = 0; i < N; i++) {
			a[i] = rand() % N + 1; // generate random values in the range of 1
								   // to N, inclusive, with duplicates
		}

		if (N < 100)
			printValues("Initial Values: ", a, N); // for small values of N, print the results to help debug

		mySort(a, N); // sort array a containing N values

		if (N < 100)
			printValues("\nSorted Values: ", a, N); // for small values of N, print the results to help debug

    // now we write helpful information to the data file.
    // note that this data file can be loaded directly into 
		myFile << N << ", compares, " << compareCount << endl; // number of comparisons for this value of N, from myCompare()
		myFile << N << ", swaps, " << swapCount << endl;  // number of swaps for this value of N, from arrSwap()
    myFile << N << ", copies, " << copyCount << endl; // number of copies for this value of N, from myCopy()
		myFile << N << ", (LOGARITHMIC), " << log2(N) << endl;  // example curve data showing a logarithmic curve for this value of N
		myFile << N << ", (LINEARITHMIC), " << N * log2(N) << endl; // example curve data showing a linearithmic curve for this value of N
		myFile << N << ", (QUADRATIC)________________________, " << N * N  << endl; // example curve data showing a quadratic curve for this value of N
    myFile << N << ", (CUBIC)________________________, " << N * N * N << endl; // example curve data showing a cubic curve for this value of N

		printStats(N); // now we print these values also the console area

		if (!isSortedAscending(a, N)) {
			cout << "****  ERROR: mySort() failed - the array of size " << N << " is not in ascending "
					"order *****"
				 << endl << endl;
		}

	} // end power loop to grow N by doubling: 2, 4, 8, 16

	myFile.close(); // close a data file to store out output data
	cout << "DONE" << endl;
  
} // end main()