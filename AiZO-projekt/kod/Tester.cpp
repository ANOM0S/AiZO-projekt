#include<chrono>

#include "Tester.h"

int Tester::uruchomTest(ISorter& algorytm, std::vector<int>& dane) {
    // 1. Starting timer
    auto start = std::chrono::high_resolution_clock::now();
    
    // 2. Sorting data
    algorytm.sort(dane);
    
    // 3. stoping timer
    auto stop = std::chrono::high_resolution_clock::now();

    // 4. Calculating the difference
    int czasTrwania = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

    // 5. Returning the time.
    return czasTrwania;
}
