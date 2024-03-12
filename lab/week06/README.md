# Lab hours: Week 6
**Total Hours:** 4.5

## Better radix bucket sort
I wanted to see if I could make radix bucket sort work for a larger collection of data, without knowing any additional information about it ahead of time.

### Eliminate d param
The first improvement I wanted to make was eliminating `d` parameter which specifies the max number of digits to expect. I did this by first iterating over the array to determine the maximum digits seen in any number. The function is as follows.

```cpp
/**
 * Computes the maximum number of digits for numbers in an vector.
 * 
 * @return The maximum number of digits for all numbers in the vector.
*/
int _max_digits(std::vector<int>& A) {
    int max = A.at(0);
    for (int n : A) {
        if (n > max) max = n;
    }
    return floor(log10(max) + 1); 
}
```

### Negative numbers
I also wanted to find a way such that radix bucket sort would also work for a vector with positive and negative numbers. My initial thought was to partition the vector into a positive and negative section and store the index of the last negative number. And change all the negative numbers to positive. Then sort the two partitions where the positive partition is sorted normally, and the negative is the same until the values are removed from the buckets. Here the order would need to be reversed. Start at bucket 9 and go to 0 removing the elements in LIFO order. Finally numbers in the negative partition have to be multiplied by `-1`.
```cpp
int _partition(std::vector<int>& A) {
    int i = -1;
    int j = A.size();
    while(true) {
        do { i++; } while(A[i] < 0 && i < j);
        do { j--; } while(A[j] >= 0 && j >= 0);
        if (i >= j) {
            return j;
        }
        std::swap(A[i], A[j]);
    }
}
```
This solution seems to work but it requires a few extra iterations over the array as well as a separate sort function for positive and negative partitions. Another solution I thought ous was to start by partitioning the vector in the same manor whilst changing all numbers to positive. Then call the same standard radix bucket sort function on each partition separately. The negative values will be in reversed order and will thus have to be reversed and multiplied by `-1` to be negative again. This solution is a bit cleaner as it removes the need for two separate radix bucket sorts, however it requires another pass over the data to reverse the order.

I am currently looking into other solutions involving bit shifting and accounting for the sign bit but have to do a bit more thought on this solution. Hopefully this will avoid the partition and converting numbers to positive all together.