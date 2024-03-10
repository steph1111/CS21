# Median of three minimum size constant (hoare)

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
#include <cstdlib>
#include <time.h> 

int LIMIT_HOARE = 0;


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
 * Hoare partition helper for quicksort()
 * 
 * @param A Vector containing elements to sort
 * @param p Left index
 * @param r Right index
 * @return Index on which the array is split such that elements to the 
 *         left of the index are less than the element at that index 
 *         and elements to the right are greater than the element at that index.
*/
int hoare_partition(std::vector<int>& A, int p, int r) {
    // Select a good pivot
    if ((r - p) > LIMIT_HOARE) {
        int med = med_of_3(A, p, r);
        swap(A, med, p);
    }

    int x = A[p];   // Pivot 
    int i = p - 1;
    int j = r + 1;
    while (true) {
        do { i++; } while (A[i] < x);   // Move i to the right until it finds something out of place
        do { j--; } while (A[j] > x);   // Move j to the left until it finds something out of place
        if (i >= j) return j;           // Nothing left to swap, return index of pivot
        swap(A, i, j);          // Swap out of place elements
    }
}


/**
 * Sorts vector A in place in ascending order with quick sort algo.
 * Better for arrays with duplicates
 * 
 * @param A Vector containing elements to sort
 * @param p Left index
 * @param r Right index
*/
void hoare_quicksort(std::vector<int>& A, int p, int r) {
    if (p < r) {
        int q = hoare_partition(A, p, r);   // Divide 
        hoare_quicksort(A, p, q);           // Conquer (recursive call on lower array)
        hoare_quicksort(A, q + 1, r);       // Conquer (recursive call on upper array)
    }
}


int main() {

    int input;
    std::vector<int> numbers(1000000);
    int tests[14] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3};
    double time_taken;
    double sum = 0;

    // Add random numbers to vector
    srand(time(0));
    for (int i = 0; i < numbers.size(); i++) {
        // numbers[i] = i;
        numbers[i] = rand() % numbers.size();
    }

    for (int i = 0; i < 14; i++) {
        LIMIT_HOARE = tests[i]; // set new limit value
        std::cout << "LIMIT_HOARE = " << tests[i] << ";\nTimes: ";
        sum = 0;

        for (int j = 0; j < 50; j++) {  // Run the test with the limit 10 times
            // Start and end time to run quicksort with the new limit
            auto start = std::chrono::high_resolution_clock::now();
            std::ios_base::sync_with_stdio(false);
            hoare_quicksort(numbers, 0, numbers.size() - 1);
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


## Test data
### one_million_sorted.txt with time command
#### 1. Minimum size constant is 3
```cpp
const int LIMIT_HOARE = 3;
```
```sh
❯ time ./p3 -h < one_million_sorted.txt > /dev/null
./p3 -h < one_million_sorted.txt > /dev/null  0.57s user 0.34s system 99% cpu 0.909 total
```

#### 2. Minimum size constant is 1000
```cpp
const int LIMIT_HOARE = 1000;
```
```sh
❯ time ./p3 -h < one_million_sorted.txt > /dev/null
./p3 -h < one_million_sorted.txt > /dev/null  1.45s user 0.36s system 99% cpu 1.816 total
```

#### 3. Minimum size constant is 100
```cpp
const int LIMIT_HOARE = 100;
```
```sh
❯ time ./p3 -h < one_million_sorted.txt > /dev/null
./p3 -h < one_million_sorted.txt > /dev/null  0.60s user 0.33s system 99% cpu 0.937 total
```

#### 4. Minimum size constant is 50
```cpp
const int LIMIT_HOARE = 50;
```
```sh
❯ time ./p3 -h < one_million_sorted.txt > /dev/null
./p3 -h < one_million_sorted.txt > /dev/null  0.58s user 0.44s system 99% cpu 1.020 total
```

#### 5. Minimum size constant is 10
```cpp
const int LIMIT_HOARE = 10;
```
```sh
❯ time ./p3 -h < one_million_sorted.txt > /dev/null
./p3 -h < one_million_sorted.txt > /dev/null  0.56s user 0.33s system 99% cpu 0.893 total
```

#### 5. Minimum size constant is 5
```cpp
const int LIMIT_HOARE = 5;
```
```sh
❯ time ./p3 -h < one_million_sorted.txt > /dev/null
./p3 -h < one_million_sorted.txt > /dev/null  0.63s user 0.42s system 99% cpu 1.051 total
```
## test.cpp (sorted)
```sh
❯ ./a.out
LIMIT_HOARE = 16;
Times: 0.24281 0.12539 0.116782 0.107902 0.108288 0.12408 0.112853 0.109554 0.113097 0.118109 0.119843 0.101234 0.107105 0.11142 0.131943 0.116693 0.105992 0.106935 0.126789 0.118019 0.108747 0.109588 0.120365 0.127315 0.106906 0.104534 0.110951 0.121827 0.119317 0.10976 0.109447 0.121989 0.119783 0.118476 0.112433 0.125152 0.119444 0.105693 0.110359 0.112271 0.13022 0.107709 0.112281 0.110715 0.11963 0.117402 0.111103 0.103073 0.11187 0.123892 
Average: 0.117342

LIMIT_HOARE = 15;
Times: 0.11008 0.11012 0.102963 0.114778 0.113348 0.106422 0.104859 0.109227 0.121633 0.106829 0.100778 0.0977857 0.116432 0.114428 0.104802 0.105461 0.107943 0.127984 0.113596 0.113243 0.113775 0.127226 0.119846 0.10595 0.103386 0.117245 0.125511 0.108899 0.10716 0.118692 0.130694 0.112025 0.106703 0.108031 0.118363 0.121368 0.107944 0.112275 0.112356 0.118285 0.107956 0.101357 0.10178 0.111542 0.109811 0.104248 0.104112 0.10578 0.116057 0.10687 
Average: 0.111359

LIMIT_HOARE = 14;
Times: 0.104047 0.102314 0.114117 0.123079 0.103475 0.103195 0.116097 0.120851 0.114268 0.107447 0.103196 0.115097 0.123798 0.100136 0.104386 0.107814 0.12055 0.116856 0.102455 0.101546 0.106991 0.125757 0.107294 0.104001 0.105934 0.13251 0.113773 0.106683 0.107799 0.114456 0.121407 0.106232 0.10729 0.106484 0.123656 0.112762 0.107172 0.107725 0.112013 0.124387 0.106276 0.0991441 0.104026 0.118831 0.117214 0.10789 0.102584 0.109656 0.119891 0.109171 
Average: 0.111075

LIMIT_HOARE = 13;
Times: 0.104605 0.101591 0.112073 0.110004 0.102559 0.0978052 0.108605 0.114326 0.108811 0.100101 0.101681 0.103267 0.115469 0.111356 0.0984638 0.105365 0.112902 0.11212 0.107282 0.105367 0.111831 0.114935 0.102671 0.102471 0.0996164 0.110016 0.122246 0.103948 0.0973195 0.105131 0.117423 0.110514 0.113947 0.103176 0.105221 0.125415 0.10434 0.104159 0.101847 0.116692 0.112149 0.103819 0.10462 0.10918 0.119531 0.111551 0.104945 0.100929 0.104376 0.120327 
Average: 0.107962

LIMIT_HOARE = 12;
Times: 0.10639 0.10324 0.102748 0.118972 0.116371 0.098068 0.0979032 0.111902 0.123474 0.107479 0.10515 0.105972 0.107808 0.11376 0.104359 0.101169 0.1119 0.118562 0.109554 0.110374 0.100748 0.105352 0.118053 0.10411 0.101826 0.105203 0.116981 0.113956 0.101082 0.104757 0.106219 0.114828 0.104274 0.0975794 0.101738 0.113077 0.119609 0.104798 0.106458 0.112618 0.110745 0.114468 0.0992198 0.0975546 0.100509 0.1149 0.109132 0.105977 0.106713 0.10742 
Average: 0.107901

LIMIT_HOARE = 11;
Times: 0.118185 0.104114 0.0982257 0.0989481 0.115968 0.114488 0.103998 0.101663 0.116107 0.122069 0.10569 0.104983 0.101563 0.113122 0.112609 0.100787 0.101089 0.10556 0.113598 0.114451 0.102519 0.10217 0.104156 0.119415 0.102198 0.103863 0.0997557 0.114268 0.11377 0.100384 0.0962311 0.100211 0.110978 0.119269 0.0969404 0.0956758 0.0992756 0.113916 0.107819 0.101819 0.101955 0.102263 0.12215 0.101951 0.0992667 0.105377 0.108994 0.119392 0.102227 0.103488 
Average: 0.106778

LIMIT_HOARE = 10;
Times: 0.103887 0.115198 0.110149 0.09928 0.104674 0.105491 0.114033 0.108597 0.101021 0.106187 0.112986 0.119969 0.103167 0.102965 0.106573 0.118059 0.114299 0.103582 0.100331 0.105727 0.114685 0.109468 0.105282 0.100529 0.116742 0.116598 0.104234 0.101633 0.108078 0.117834 0.114572 0.101806 0.100748 0.113972 0.11488 0.108963 0.101371 0.103536 0.112384 0.118016 0.0986638 0.102389 0.107417 0.117277 0.107743 0.104142 0.0981885 0.107035 0.119203 0.102403 
Average: 0.108119

LIMIT_HOARE = 9;
Times: 0.104796 0.104703 0.11227 0.116805 0.103245 0.104237 0.11037 0.12136 0.108042 0.10998 0.101989 0.11523 0.113524 0.102966 0.0993571 0.108516 0.115794 0.110809 0.100226 0.0990462 0.10464 0.115499 0.103024 0.109957 0.101746 0.11973 0.114519 0.0989704 0.0971914 0.100497 0.113182 0.107056 0.102759 0.0987803 0.106315 0.11416 0.0994803 0.0979554 0.098367 0.104408 0.116653 0.102687 0.112157 0.108211 0.111465 0.108499 0.0990937 0.102787 0.0993898 0.117944 
Average: 0.107008

LIMIT_HOARE = 8;
Times: 0.112788 0.100087 0.101728 0.106608 0.115346 0.0988801 0.101608 0.0964787 0.104301 0.119924 0.103826 0.0992911 0.105316 0.117444 0.106972 0.0986882 0.105088 0.105979 0.114108 0.109023 0.101348 0.105566 0.110886 0.11622 0.100919 0.100326 0.0956668 0.117721 0.114846 0.102074 0.102911 0.111559 0.122448 0.100563 0.0985079 0.102619 0.111469 0.118543 0.10039 0.101229 0.101841 0.121408 0.113512 0.103798 0.103298 0.109605 0.125967 0.104094 0.0996335 0.0983489 
Average: 0.106816

LIMIT_HOARE = 7;
Times: 0.152299 0.119318 0.103607 0.096252 0.0965356 0.105755 0.117136 0.099663 0.0979846 0.108944 0.11093 0.10857 0.0993358 0.0986193 0.104129 0.112888 0.103305 0.100248 0.100037 0.110472 0.122498 0.103076 0.103301 0.0974485 0.119697 0.107343 0.0991732 0.0985591 0.106662 0.115614 0.108177 0.10252 0.104483 0.105137 0.117095 0.101106 0.0988242 0.0963506 0.102833 0.120342 0.0973097 0.102267 0.0981928 0.112281 0.112256 0.103382 0.102543 0.101807 0.113958 0.104223 
Average: 0.10649

LIMIT_HOARE = 6;
Times: 0.105535 0.101047 0.10917 0.112833 0.100673 0.0966915 0.104272 0.116371 0.121138 0.120552 0.100014 0.108622 0.115799 0.107423 0.0971984 0.103633 0.112851 0.113335 0.101507 0.100718 0.0997471 0.112148 0.120623 0.105316 0.104261 0.106863 0.122715 0.111642 0.098408 0.0971977 0.112184 0.119897 0.100179 0.104511 0.100767 0.112947 0.113034 0.100164 0.0973123 0.103778 0.115051 0.1111 0.097008 0.0941542 0.111852 0.118552 0.101246 0.106228 0.1029 0.109381 
Average: 0.107211

LIMIT_HOARE = 5;
Times: 0.124905 0.103423 0.0977046 0.101373 0.114416 0.109442 0.103025 0.103164 0.106373 0.12039 0.105408 0.0994187 0.104046 0.112282 0.109553 0.0989026 0.109782 0.105112 0.119867 0.111353 0.103934 0.100658 0.113225 0.122345 0.104488 0.0957982 0.100277 0.109361 0.112822 0.101265 0.101162 0.102229 0.121813 0.103129 0.10542 0.103564 0.101788 0.11931 0.0999113 0.107519 0.0987289 0.111282 0.113686 0.105729 0.100634 0.106972 0.113706 0.105418 0.10227 0.102273 
Average: 0.107013

LIMIT_HOARE = 4;
Times: 0.109971 0.114275 0.102521 0.101696 0.108072 0.116594 0.113894 0.105674 0.102074 0.117286 0.120008 0.105067 0.101705 0.1051 0.116816 0.110593 0.100608 0.0994115 0.105193 0.120076 0.109229 0.106067 0.107649 0.112445 0.118349 0.106209 0.0994775 0.0986951 0.11354 0.115945 0.107234 0.101787 0.10994 0.122202 0.103963 0.102617 0.106921 0.116307 0.119721 0.105429 0.104671 0.108215 0.121891 0.117252 0.102305 0.105277 0.110274 0.117588 0.0995453 0.0992501 
Average: 0.108933

LIMIT_HOARE = 3;
Times: 0.110211 0.123876 0.11541 0.107751 0.101957 0.108572 0.125208 0.105183 0.102276 0.117199 0.117065 0.11392 0.10518 0.105797 0.110167 0.12366 0.10125 0.101764 0.107993 0.119684 0.110435 0.10505 0.104541 0.103337 0.119379 0.106607 0.107234 0.10567 0.113415 0.118138 0.112019 0.102747 0.110529 0.125472 0.112735 0.101705 0.108194 0.115351 0.118993 0.110503 0.101764 0.108058 0.117693 0.113983 0.100919 0.107331 0.111688 0.116927 0.110947 0.107994 
Average: 0.11067
```

## Test results
Based on the tests above, the optimal value for the constant was found to be around `7`. When tested with a sorted array this value yielded the best results for an sorted input. 