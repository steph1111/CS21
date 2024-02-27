# Assignment 2: Quicksort

## Program Description
Implement quicksort using the Lomuto partitioning method with the median-of-three variant for selecting a pivot element (as described in class and in the textbook.) Use a constant to determine what minimum size (and above) array to apply the median-of-three technique, and determine a good value for this constant experimentally. Include a `readme.txt` file that describes your test cases and how you determined a good mo3 constant (this part of the assignment is worth 20 points. Use a Vector (C++) or an ArrayList (Java) to store your data. C++ implementations are not required to use classes for this assignment and Java programmers may use only static functions.

 
## Program testing 
The input to your program will an unspecified number of entries. Each entry is a non-negative integer containing nine (zero padded) digits ( this means that the integer may have leading zeros), one per line. Read your input from STDIN. Send the values, one per line, as they were input (all nine digits including leading zeroes, if any), sorted in ascending order, to STDOUT. The only output of your program is the numeric results. (i.e. don't output your name, assignment number, prompts etc.)


## Extra Credit (20 points):
Once your Lomuto partition method is coded, working, and tested thoroughly, add an alternate version of the partition method that use Hoare's partitioning scheme. (You will still be using the median of three technique.) Note that if you use Hoare's partition method, you may need different versions of your various (helper) functions. Thoroughly test the revised version of the program, and then re-test the original version of your program to make sure it still works. Your program should use the Lomuto partition method by default. Include a command line parameter ("-h") to select the Hoare partition method instead. Include analysis of this version of your algorithm (in a second text file readme_hoare.txt) One half of the extra credit is for the implementation and one half is for the additional analysis. You will score no extra credit if the Lomuto sorting method is not 

## Sample input/output
**Sample run:**
```sh
[steveh@pengo CS21]$ ./p3 < in > out
[steveh@pengo CS21]$ cat in
470359781
005221965
289392600
[steveh@pengo CS21]$ cat out
005221965
289392600
470359781
[steveh@pengo CS21]$ 
```

## What you turn in
Put all of the source code files (.cpp, .h, makefile if C++, .java, etc.) but no executeables, binaries, compiler, or data files (omit .o, "a.out" , .class files etc.) in a folder named as shown above in the home directory of your account on pengo. Please don't include any sub-folders.