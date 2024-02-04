# Assignment 1: Review and Linked List

## Program Description
Using C++ or Java, create a doubly linked list data structure that stores strings. At a minimum, you must have a `List` class that contains the list functionality (including an insert function) and a linking object ("link node") class. For convenience, you may include the data in the link node objects, or you may use a separate, third, (possibly generic) data class or generic (template) data type. You may use an inner class for the `LinkNode` and/or include the `LinkNode` class with the `List` class file if you wish. Your list must have functions to both insert and remove (and return) values from both the front and end of the list. You may use code that you have written previously as a starting point for this assignment. You may not use somebody else's code as a starting point for your assignment. You must code the list yourself — use of a "standard container" (such as an STL class, Vector, or ArrayList) is not permitted for this assignment.

Using composition (with your `List` class,) define a `Stack` class that has `push` and `pop` functions, as well as an `isEmpty` function.

(Each of your classes may have any additional functionality that you deem necessary)

Write a `main` function that will read an unspecified number (until EOF) of input strings (each string may include whitespace and is terminated with a newline) from STDIN. `push` each string into your `Stack`. After you have read all of the input, `pop` each string from your `Stack`, printing it to STDOUT (one per line). Your program should have no other output.

## What you turn in
Put all of the source code files (.cpp, .h, makefile if C++, .java, etc.) but no sub directories, executables, compiled, or data files (omit .o, "a.out" , .class files etc.) in a directory named as shown above in the home directory of your account on pengo. C++ projects must build properly with a "make" command, Java projects must compile correctly with a "javac *.java" command.