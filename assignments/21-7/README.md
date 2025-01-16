# Assignment 7: Binary Search Tree

## Program Description
Implement a Binary Search Tree data structure in C++ or Java. Your BST will store integers. Your bst should implement the following public functions:
- search(key)
- insert(key)
- delete(key)
- min
- max
- predecessor(key)
- successor(key)
- inorder traversal
- preorder traversal
- postorder traversal

You should also implement as many helper and private functions as needed. You may assume that the key values are unique, and don't make any other assuptions about the values. For convenience, you may perform output operations in the public tree functions, or you can design an efficient mechanism to do all of the output outside of the tree for a bit of extra credit.


## Input
Create a main program that reads a "session trace" from STDIN and sends output to STDOUT. The input will contain (at most) one operation per line. Apply, in order, each of the operations to an object of your bst class. Ignore any comments in the input. A comment begins with a pound sign ("#") and continues to the end of the line. A line may contain an operation and a comment.

## Output
Each of the following functions should generate output (one per line):
- The search function should output "key found." or "key not found."
- Insert should output "inserted key."
- Delete should remove an object with the given key value from the tree and output "deleted key." or "delete key - not found." depending on the result.
- Min and Max should output "min is key." or "max is key." or "tree empty."
- Predecessor should output "key predecessor is key." or "no predecessor for key." or "key not in tree." Successor should function similarly.
- The three traversal functions should output "inorder traversal: " (or "postorder traversal: " or "preorder traversal: ") followed by a space separated list of elements starting on the next line.

## What you turn in
Put all of the source code files (.cpp, .h, makefile if approprite, .java, etc.) but no executeables, binaries, compiler, or data files (omit .o, "a.out" , .class files etc.) in a folder named as shown above in the home directory of your account on pengo. Please don't include any sub-folders.
