# Goal
1. NOTE: main() is written for you... you should not need to change it.
   
2. Write a simple sorting function called mySort() that will sort a randomly generated collection of N integers from an array, into ascending order.  Note:  Random numbers will contain duplicates.  You may use any algorithm you prefer (published or otherwise) in your sorting function. Your grade is NOT dependent on the speed or memory requirements of your sorting algorithm.  Instead, your grade will be based on your ability to follow the instructions outlined below and to properly estimate the performance of your chosen algorithm in terms of N (the number of items you are sorting). Please note: you are not allowed to use <, >, or == when comparing values from your array (you must use myCompare(), which is provided for you in main.cpp.  You must also use arrSwap() or myCopy() when re-ordering values in the array.  Failure to use these functions will result in deductions from your score on this assignment.


3. Once your mySort() function is written, main() will progressively change the value of N in main() according the the google spreadsheet required values for N, and it will record three things for each value of N:  time, number of swaps (or COPIES!) , number of compares.  You will then record these 3 three values for each new value of N requested by your google spreadsheet (this is why your function will be called  many times for many values of N). Note that you can also load the data.csv file into a spreadsheet to review your data.  Note also that your choice of an algorithm may mean that your swap count is zero. But you must still record a "count" any time you copy (or shift) data from one position of an array to another, as we would see in the insertion sort when we "shift right". You can do this directly from inside your  mySort() function by incrementing the copyCount variable, or by calling the myCopy() function.


4. Finally, answer the 3 questions posed at the bottom of the google spreadsheet (and below, in this readme file).  Be sure to `record your answers in the google spread sheet` and to submit a publicly viewable google document link.  To avoid deduction in grade, verify that your google spreadsheet is "public" by trying to open it from an incognito browser.

5. You may find this site helpful for visulizing your curve data: https://www.csvplot.com   When you run your HW1 Program you should see a data.csv file created in your repl.  If you download the .csv file from your repl to your computer, and then upload that same .csv file into the link above, you can see your data, along side other typical curves for measuring algorithmic performance.  Use this tool to help you classify the performance of your algorithm

 

# Restrictions
- You may only use arrays to store the numbers that you need to sort. You may NOT use any C++ containers or library-based sorting functions.  You may only use functions that you write yourself and those provided for you in this "start" code sample for this assignment.
- You must use the compare() and arrSwap() (or myCopy) functions provided to ensure proper analaysis of your algorithm.  (This means you cannot use >, <, etc. symbols to compare, swap, or shift values in the array you are sorting.)
 

# Resources & Requirements
- Use main.cpp in this repl.it to start
- Use the google spreadsheet template to record your results (make a copy of it and submit a link to your copy along with your code) - see below for submission details.
<https://docs.google.com/spreadsheets/d/1gGLdji0SbLiGeoUvvcCdixevRXZ5XWg2hDedQvOxumA/edit?usp=sharing>

# Details
- Use the layout provided in main() to generate random numbers via an int array that will be passed to your mySort() function.
- Use the provided support functions compare(),  arrSwap() (or myCopy) to ensure that any comparisons or swaps (or shifts) between members of the array that you are sorting are properly counted via the static variables compareCount and swapCount (or copyCount)
- Ensure that your sorting function produces output that is sorted in ascending order.  The isSortedAscending()  function from main() will be called after your function returns to verify the ascending sort.
- Ensure that your sorting function calls the chrono library timing macros as shown in the stubbed out mySort() function at the link provided. (don’t change this code).
- You do NOT need to print out your pre-sorted and sorted array values for larger sample tests. (you may choose to do so for debugging purposes for smaller values of N).
- Note that the printStatistics() function from main() will be called when your function returns, to print out the number of swaps (or copies), compares, and seconds taken;  along with helpful comparative values so you can assess the performance of your sort based on its number of compares, swaps, and time taken.

- Your function will be tested with increasing values of N as shown in the table below.  You should not need to modify the main loop as you prefer to optimize the process of generating successive values for N.

 

# Submission
 

1) Submit a link to your repl via canvas

2) Submit your a link to  your google data sheet via canvas (fill out the sheet and return an ACCESSIBLE link to your copy of the document with your canvas submission.    

- Please use the google spreadsheet template per the link below (make a copy; don't worry you will not be able to change the original).

<https://docs.google.com/spreadsheets/d/1gGLdji0SbLiGeoUvvcCdixevRXZ5XWg2hDedQvOxumA/edit?usp=sharing>

- Your version of the spreadsheet will look a bit like this:

 
```
Value for N         #Compares         #Swaps          #Seconds

512                     ???            ???               ???

1024                    ???            ???               ???

2048                    ???            ???               ???

4096                    ???            ???               ???

8192                    ???            ???               ???

16384                   ???            ???               ???

32768                   ???            ???               ???

65536                   ???            ???               ???
```
 
 

# Three Questions:
These are the questions you need to answer in the google spreadsheet, based on your empirical obserbvations of the data you have recorded:

1. Your mySort() Performance Assessment based on growth of Comparisons? constant, linear, logarithmic, linearithmic, quadratic, or worse than quadratic?
2. Your mySort() Performance Assessment based on growth of Swaps (or copies)? constant, linear, logarithmic, linearithmic, quadratic, or worse than quadratic?
3. Based on your recorded timings in the table above, where N doubles for each successive sample, how many seconds would you estimate it would take for your function to sort N = pow(2, 20) = 1,048,576 random values (over 1M values)?  (Note that you will need to use your growth assessments from above to find this number.. your mySort() function will not be able to compute this answer!)
 
 

# - Scoring (out of 100 pts)
- 10 pts – you followed the instructions above for the construction and submission of your program and your public google spreadsheet
- 40 pts – your program correctly sorts the random array (isSortedAscending() returns true)
- 10 pts – your mySort() function calls compare(), and arrSwap() ( or myCopy) any time you need to compare or swap or shift two array values.
- 10 pts – you correctly reported #compares,  #swaps (or #copies), and time for all requested values of N based on your mySort() performance, via the table above.
- 10 pts – you provided a final performance assessment for your algorithm that correctly describes its comparison performance based on the choices given above (constant, linear, logarithmic, etc.)
- 10 pts – you provided a final performance assessment for your algorithm that correctly describes its swap (or Copy) performance based on the choices given above (constant, linear, logarithmic, etc.)
- 10 pts – you provided a final performance assessment for your algorithm that estimates its time performance in seconds for N == pow(2, 20).