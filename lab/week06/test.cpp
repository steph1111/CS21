#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <time.h> 
#include <cmath>
#include <fstream>
#include <iomanip>

// ----------------function def here----------------

int main() {
    std::vector<int> numbers;
    int sign[2] = {-1, 1};
    double time_taken;
    double sum = 0;
    int input;
    const int NUM_TESTS = 20;

    srand(time(0));
    {
    std::ofstream fout("bin.txt");

    for (int i = 0; i < 21; i++) {
        numbers.resize(pow(2, i));
        for(int j = 0; j < pow(2, i); j++) {
            numbers[j] = rand() % 1000000 * sign[rand() % 2];
        }
        for (int j = 0; j < NUM_TESTS; j++) { 
            auto start = std::chrono::high_resolution_clock::now();
            // ----------------function call here---------------- 
            auto end = std::chrono::high_resolution_clock::now();
            time_taken = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;
            sum += time_taken;
        }
        fout << std::fixed << std::setprecision(8) << sum / NUM_TESTS << "\t" 
             << std::setprecision(0) << pow(2, i) << "\n";
    }
    }
    return 0;
}