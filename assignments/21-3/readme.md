# Median of three minimum size constant

## Median of three
The median of three (mo3) technique selects a good pivot for quicksort by finding the median of three elements. This eliminates the worse case `O(n)` time complexity of quicksort, which occurs when the array is already sorted.

```cpp
// Avoids selecting a bad pivot in the case of a sorted array
// by finding the median element index of the left most, 
// right most, and center element of the array.
int med_of_3(std::vector<int>& A, int p, int r) {
    int mid = A[p + ((r - p) / 2)], left = A[p], right = A[r];
    if ((left > mid) ^ (left > right)) return p;
    if ((right > mid) ^ (right > left)) return r;
    return p + ((r - p) / 2);
}
```

## Minimum size constant
Median of three is effective at choosing a good pivot when the array is already sorted, however finding this pivot is several extra steps for `partition()`. There is some minimum size of the array to partition for which the extra steps to find median of three is worth while.
```cpp
// From partition()
// `LIMIT` is the minimum size constant
if (r - p > LIMIT) {
    int med = med_of_3(A, p, r);
    swap(A, med, r);
}
```
## Test setup
To find the minimum size constant I created a file of one million **sorted** values using a simple python script. The file is sorted because this is where finding the median of three affects the time complexity the most.
```py
# Generate one million sorted integers and output them to `one_million_sorted.txt`
with open("one_million_sorted.txt", mode="w") as text_file:
    for i in range(1_000_000):
        print(i, file=text_file)
```
By running the program with the `time` command and input redirection from `one_million_sorted.txt`, changing the `LIMIT` each time, the optimal minimum size constant can be found.

For more precise automated testing, I also created a C++ program which tests `LIMIT` values 50 times each and finds the average times on a sorted vector.
```cpp
#include <iostream>
#include <vector>
#include <chrono>

int LIMIT = 0;

/**
 * Swaps two elements in a vector given indices
 * 
 * @param A Vector containing elements to sort
 * @param i, j Indexes of elements to swap
*/
void swap(std::vector<int>& A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


/**
 * Median of three helper for quicksort().
 * 
 * Avoids selecting a bad pivot by finding the median element index of 
 * of the left most, right most, and center element of the array.
 * 
 * @param A Vector containing elements to sort 
 * @param p Left index
 * @param r Right index 
 * @return Index of the median element in `A` of indexes `p`, `r` 
 *         and `p + ((r - p) / 2)` (the mid point)
*/
int med_of_3(std::vector<int>& A, int p, int r) {
    int mid = A[p + ((r - p) / 2)], left = A[p], right = A[r];
    if ((left > mid) ^ (left > right)) return p;
    if ((right > mid) ^ (right > left)) return r;
    return p + ((r - p) / 2);
}


/**
 * Lumuto partition helper for `quicksort()`
 * 
 * Rearranges the sub array  A[i...j] in place returning into two regions
 * A[i...k - 1] and  A[k + 1...j] where A[k] is the pivot such that
 * all elements in A[i...k - 1] are <= A[k] and all elements in 
 * A[k + 1...j] >= A[k]
 * 
 * @param A Vector containing elements to sort
 * @param p Left index
 * @param r Right index
 * @return Index on which the array is split such that elements to the 
 *         left of the index are less than the element at that index 
 *         and elements to the right are greater than the element at that index.
*/
int partition(std::vector<int>& A, int p, int r) {
    // Median of three calculation to select a good pivot 
    // for vectors larger than LIMIT
    if ((r - p) > LIMIT) {
        int med = med_of_3(A, p, r);
        swap(A, med, r);
    }

    int x = A[r];                   // Pivot element
    int i = p - 1;                  // Highest index on the low side
    for (int j = p; j < r; j++) {   // For every element besides the pivot
        if (A[j] < x) {             // If the element belongs on the low side
            i++;                    // Increment low position
            swap(A, i, j);          // Put that element on the low side
        }
    }
    swap(A, i + 1, r);      // Move the pivot to its new position

    // New pivot index aka where the array is split into high and low
    return i + 1;
}


/**
 * Sorts vector A in place in ascending order with quick sort algo
 * 
 * Time complexity:
 * Average case:                            O(nlgn) (small constants)
 * Worst case (already sorted array):       O(n^2)
 * Worser case (many duplicate elements):   Use hoare
 * 
 * @param A Vector containing elements to sort
 * @param p Left index
 * @param r Right index
*/
void quicksort(std::vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r); // Divide 
        quicksort(A, p, q - 1);     // Conquer (recursive call on lower array)
        quicksort(A, q + 1, r);     // Conquer (recursive call on upper array)
    }
}

int main() {
    int input;
    std::vector<int> numbers(1000000);
    int tests[10] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3};
    double time_taken;
    double sum = 0;

    // Add numbers to vector
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] = i;
    }
    // For each value in `tests`
    for (int i = 0; i < 10; i++) {
        LIMIT = tests[i]; // set new limit value
        std::cout << "LIMIT = " << tests[i] << ";\nTimes: ";
        sum = 0;

        for (int j = 0; j < 50; j++) {  // Run the test with the limit 10 times
            // Start and end time to run quicksort with the new limit
            auto start = std::chrono::high_resolution_clock::now();
            std::ios_base::sync_with_stdio(false);
            quicksort(numbers, 0, numbers.size() - 1);
            auto end = std::chrono::high_resolution_clock::now();

            // Total time taken
            time_taken = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;

            // Output times
            std::cout <<  time_taken << " " ;
            sum += time_taken;
        }
        std::cout << "\nAverage: " << sum / 50 << std::endl << std::endl;
    }

    return 0;
} 
```
And finally another version with a vector of random elements.

## Test data
### one_million_sorted.txt with time command
#### 1. Minimum size constant is 3
```cpp
const int LIMIT = 3;
```
```sh
❯ time ./p3 < one_million_sorted.txt > /dev/null
./p3 < one_million_sorted.txt > /dev/null  0.58s user 0.36s system 99% cpu 0.944 total
```

#### 2. Minimum size constant is 1000
```cpp
const int LIMIT = 1000;
```
```sh
❯ time ./p3 < one_million_sorted.txt > /dev/null
./p3 < one_million_sorted.txt > /dev/null  6.26s user 0.37s system 99% cpu 6.627 total
```

#### 3. Minimum size constant is 100
```cpp
const int LIMIT = 100;
```
```sh
❯ time ./p3 < one_million_sorted.txt > /dev/null
./p3 < one_million_sorted.txt > /dev/null  0.93s user 0.38s system 99% cpu 1.311 total
```

#### 4. Minimum size constant is 50
```cpp
const int LIMIT = 50;
```
```sh
❯ time ./p3 < one_million_sorted.txt > /dev/null
./p3 < one_million_sorted.txt > /dev/null  0.78s user 0.40s system 99% cpu 1.173 total
```

#### 5. Minimum size constant is 10
```cpp
const int LIMIT = 10;
```
```sh
❯ time ./p3 < one_million_sorted.txt > /dev/null
./p3 < one_million_sorted.txt > /dev/null  0.63s user 0.35s system 99% cpu 0.982 total
```

#### 5. Minimum size constant is 5
```cpp
const int LIMIT = 5;
```
```sh
❯ time ./p3 < one_million_sorted.txt > /dev/null
./p3 < one_million_sorted.txt > /dev/null  0.67s user 0.31s system 99% cpu 0.978 total
```
## test.cpp (sorted)
```sh
❯ g++ test.cpp
❯ ./a.out
LIMIT = 12;
Times: 0.185264 0.172235 0.167715 0.199424 0.174556 0.186236 0.200217 0.180847 0.18467 0.185791 0.168627 0.20248 0.17616 0.168792 0.204348 0.168172 0.177818 0.199655 0.179788 0.19197 0.183096 0.165977 0.201208 0.185561 0.181929 0.196343 0.167239 0.186145 0.190128 0.175894 0.202103 0.175397 0.171393 0.20418 0.168422 0.178026 0.195684 0.166562 0.188758 0.187103 0.167397 0.205482 0.177798 0.168409 0.202156 0.169727 0.175304 0.196452 0.167874 0.186197 
Average: 0.183254

LIMIT = 11;
Times: 0.201144 0.167322 0.204929 0.178008 0.171367 0.211549 0.168883 0.18006 0.192749 0.168001 0.191048 0.186493 0.167257 0.209962 0.172443 0.173021 0.202445 0.167854 0.181904 0.193008 0.166848 0.19257 0.183415 0.167366 0.200119 0.18401 0.177764 0.197874 0.166735 0.185177 0.188868 0.166484 0.195453 0.180869 0.168912 0.204338 0.184269 0.184737 0.193764 0.167599 0.188752 0.181679 0.1679 0.199957 0.174727 0.171179 0.199921 0.18098 0.187906 0.190741 
Average: 0.183807

LIMIT = 10;
Times: 0.238841 0.199807 0.167431 0.179457 0.196324 0.17911 0.19084 0.182908 0.184182 0.204699 0.17166 0.175996 0.196874 0.166883 0.186387 0.189494 0.166908 0.191269 0.1814 0.183017 0.205033 0.169208 0.176947 0.195511 0.167131 0.185983 0.189529 0.167955 0.194614 0.175832 0.173685 0.211966 0.16996 0.17623 0.194984 0.167826 0.186488 0.189756 0.16748 0.193662 0.178121 0.169432 0.214923 0.170924 0.178642 0.192507 0.165798 0.188027 0.187404 0.166059 
Average: 0.184102

LIMIT = 9;
Times: 0.205606 0.176429 0.170786 0.21415 0.169442 0.190481 0.190498 0.16775 0.193462 0.181383 0.167702 0.203857 0.171592 0.182415 0.208849 0.168083 0.191939 0.190546 0.166786 0.201378 0.17558 0.169908 0.200161 0.166989 0.179531 0.200791 0.176031 0.198174 0.23279 0.176021 0.242832 0.229857 0.271095 0.243637 0.272825 0.236216 0.277497 0.20726 0.231822 0.200805 0.195274 0.177742 0.168365 0.203245 0.170472 0.194011 0.248922 0.26379 0.198326 0.168129 
Average: 0.199825

LIMIT = 8;
Times: 0.203372 0.17854 0.16938 0.202978 0.168321 0.199861 0.193979 0.165762 0.189505 0.184357 0.166722 0.199954 0.175284 0.170691 0.202769 0.169564 0.182253 0.202451 0.168668 0.191487 0.182784 0.168052 0.199942 0.172661 0.179401 0.201133 0.167495 0.181339 0.202645 0.166619 0.1941 0.181974 0.16732 0.207717 0.170558 0.176664 0.199255 0.166494 0.184186 0.200558 0.166873 0.197839 0.175 0.169798 0.200955 0.16777 0.177507 0.196874 0.168218 0.184898 
Average: 0.183251

LIMIT = 7;
Times: 0.209139 0.172064 0.212195 0.170491 0.181026 0.206664 0.16656 0.187723 0.185548 0.165805 0.195251 0.187373 0.178242 0.201078 0.1681 0.178813 0.193514 0.166687 0.188321 0.185784 0.167665 0.197998 0.175241 0.185899 0.201433 0.168234 0.17907 0.19065 0.166511 0.188811 0.185931 0.167195 0.200621 0.172604 0.195574 0.200972 0.167261 0.197142 0.194172 0.166864 0.212613 0.171086 0.171802 0.199834 0.166823 0.190337 0.195836 0.166787 0.18648 0.1844 
Average: 0.184325

LIMIT = 6;
Times: 0.18335 0.199863 0.171599 0.171581 0.200159 0.178977 0.188864 0.198434 0.167171 0.193979 0.177971 0.170632 0.202771 0.169532 0.173576 0.198661 0.167085 0.184698 0.201504 0.166909 0.194477 0.177475 0.174996 0.202136 0.167736 0.17378 0.198707 0.16695 0.186053 0.201369 0.167037 0.195645 0.174294 0.169316 0.203226 0.168219 0.176159 0.195814 0.166181 0.186568 0.200535 0.176445 0.209215 0.169922 0.172746 0.201624 0.168929 0.180032 0.190531 0.166766 
Average: 0.183004

LIMIT = 5;
Times: 0.197263 0.185089 0.167823 0.184751 0.16141 0.162554 0.191566 0.160738 0.158762 0.190037 0.15837 0.158758 0.192462 0.160016 0.175353 0.186148 0.156347 0.165349 0.185978 0.155767 0.164741 0.184482 0.155527 0.168494 0.184856 0.156625 0.1847 0.180872 0.156417 0.173802 0.18029 0.154918 0.172576 0.175655 0.156389 0.175651 0.1754 0.156894 0.186267 0.177382 0.155821 0.177837 0.174376 0.155919 0.178458 0.174549 0.156224 0.180556 0.173139 0.155573 
Average: 0.171179

LIMIT = 4;
Times: 0.198727 0.164795 0.153388 0.177796 0.160362 0.15149 0.185571 0.162407 0.152611 0.183251 0.162343 0.151043 0.182129 0.171233 0.152585 0.17837 0.174864 0.158709 0.193338 0.172732 0.188431 0.21524 0.205135 0.252471 0.301141 0.302047 0.161283 0.192043 0.181253 0.174907 0.200956 0.170682 0.1591 0.180183 0.16355 0.164129 0.178645 0.153312 0.171944 0.212457 0.151413 0.169723 0.171704 0.150794 0.165481 0.174436 0.161539 0.172907 0.176355 0.151028 
Average: 0.179241

LIMIT = 3;
Times: 0.198821 0.171411 0.15195 0.173555 0.169629 0.153471 0.180288 0.168219 0.161157 0.182855 0.164704 0.150937 0.174136 0.168389 0.151293 0.173816 0.169523 0.151297 0.170816 0.172631 0.151419 0.180129 0.174152 0.192169 0.190228 0.163616 0.152531 0.17264 0.167609 0.151347 0.170922 0.166679 0.151155 0.175487 0.170287 0.150883 0.167333 0.17139 0.152291 0.165914 0.173402 0.151735 0.162172 0.176518 0.151496 0.164515 0.189342 0.150597 0.165191 0.17784 
Average: 0.167198
```

## Test results
Based on the tests above, the optimal value for the constant was found to be around `5`. When tested with a sorted array this value yielded the best results for an sorted input. For unsorted inputs, the overhead of median of three was minuscule compared to the benefits in the sorted case.