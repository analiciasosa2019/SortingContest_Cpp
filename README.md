# SortingContest_Cpp
A project that generates and then sorts a set of 1,000,000 numbers

Contains the following programs: 
###_generate.cpp_
o Purpose: generate a file called numbers.dat
o Description: The numbers.dat file will have COUNT random numbers between MIN and MAX
o Usage: generate COUNT MIN MAX
o Example: generate 1000000 100000 999999
o This program accepts command 3 command line arguments as shown above
o If there are not 3 command line arguments, the program fails
###_mysort.cpp_
o Purpose: sort numbers from numbers.dat, output to stdout (standard out)
o Description: Uses bubble sort or some other O(n-squared) function on an array of integers
o It will accept up to 1 million numbers from the input file, but will run successfully with less
o It accepts 2 command line arguments which is the input file and the output file name

The **prog3** folder contains version 1 of the project. Version 1 implements a highly-inefficient O(n^2) algorithm and takes roughly an hour to sort 1,000,000 numbers. 

The **prog4** folder contains version 2 of the project. Version 2 implements the same O(n^2) sorting algorithm but uses 8 pthreads and a merging algorithm to significantly improve sorting time. 

The **prog5** folder contains version 3 of the project. Version 3 implements quicksort and uses 16 threads to sort the numbers. It runs quicker than the built-in linus sort command. 
