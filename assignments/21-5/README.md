# Assignment 5: Hash Table

## Program Description
Implement a hash table class. Your hash table should resolve collisions by chaining and use the multiplication method to generate hash keys. You may use your own linked list code from a previous assignment or you can use a standard sequence container. Partial definitions for the hash table class and a generic data class are provided (C++ and Java versions). You may use them as a starting point if you wish. If you choose to design your own hash table class, you must provide comparable functionality. Your hash table must support a parameter to the constructor to determine table size. The default size should be `100`. For this exercise, set your hash table size to `178000`. Keys will normally be unique, but there is no guarantee of this. To deal with duplicates, your functions should match only the first match found. If you are coding in Java, you may not use the hashcode member function (from Object) unless you have overridden it with your own (appropriate) code. You may find it helpful to store the entire record as a string for easier output.
The starter code uses an abstract base class (C++) or Interface (Java) to allow for somewhat generic data type storage, but this is not required in your code. You may use another method of making your code somewhat generic, or you may "hard code" your hash table to work with a specific data type (i.e. int and string.)

```cpp
class hashTable{
public:
  hashTable(int=100); // build a table
  void insert(record *); // insert copy of record
  void delete(int); // delete a record
  // return pointer to a copy of found record, or 0
  record *search(int); 
private:
  // find return value: some type of index
  record *find(int); // helper search fn
  int hash(record *); // hash value for record
  int hash(int); // hash value for key  
  const int m; // size of table
  // array of m lists that hold records
  // other members as desired
};

// abstract base class for data
//   also overload operator= if necessary
//   and/or copy constructor, destructor 
// clone method invokes copy constructor
// to make a copy of the object
class record{
public:
  virtual int getID()=0; // or something similar 
  virtual record *clone()=0; // or something similar
  // anything else that you think is appropriate 
};
```

```java
public class hashTable{
  public hashTable(){ ... }
  public hashTable(int n){ ... }
  public void insert(Record rec){ ... }
  public void delete(int key){ ... }
  public Record search(int key){ ... }
  // find return value: some type of index
  private Record find(int key){ ... }
  private int hash(Record rec){ ... }
  private int hash(int key){ ... }
  ... int m;  
  // array of m lists that hold records
  // other members as desired
}

// abstract base class or interface for data 
public interface Record extends Cloneable{
  public Record clone(); // or something similar
  public int getID(); // or something similar
  // anything else that you think is appropriate
}
```

Create a "main program" that presents the user with a menu that allows the user to issue any of the following commands. You must use the noted integer value (with a newline) to select each option:
1. insert data from a file by entering the file name (merging with any entries already in the table) (prompt for the filename to load)
2. insert a new entry from the keyboard (prompt to enter record all on one line)
3. delete a record by key value (prompt for the key) and report results
4. search for a record by key value (prompt for the key) (if found, display entire record, otherwise indicate that the data was not found)
5. clear the entire hash table
6. save the entire hash table to disk (prompt for filename). Make sure that you use the same format specified for input (see below) so that your resulting file could be used as input in a subsequent session of your (or another) program.
7. quit

## Input
An ascii text file containing one nine digit integer (leading zeros are a possibility) followed by a space followed by additional unspecified information. Line length is guaranteed to be less than 256 characters. The id number is the key. Each record is on one line. The number of records is not specified. Do not modify the input file or make more than one pass through the file.

 
## Sample input/output
```sh
[steveh@pengo HashTable]$ ./p5 
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? 4
search for record - key? 123456789
Search not found: 123456789
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? 2
input new record:
123456789 this is a test
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? 4
search for record - key? 123456789
Found: 123456789 this is a test
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? 3
delete record - key? 123456789
Delete: 123456789 this is a test
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? 4
search for record - key? 123456789
Search not found: 123456789
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? 3
delete record - key? 123456789
Delete not found: 123456789
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? 1
read hash table - filename? foo
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? 6
write hash table - filename? foo2
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? 5
clearing hash table.
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? 7
[steveh@pengo HashTable]$ 
```

## What you turn in
Put all of the source code files (.cpp, .h, makefile if C++, .java, etc.) but no executables, compiled, or data files (omit .o, "a.out" , .class files etc.) in a folder named as shown above in the home directory of your account on pengo.