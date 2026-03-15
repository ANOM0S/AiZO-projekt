#include<chrono>
#include <vector>
#include <string>

#include "Tester.h"
#include "DataGenerator.h"

using namespace std;

int Tester::uruchomTest(ISorter& algorytm, vector<int>& dane) {
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

vector<string> Tester::benchmark(ISorter& algorytm, vector<int>& amounts, int generationType){
    DataGenerator generator;
    vector<int> table;
    vector<string> results;

    for (int i=0; i<amounts.size(); i++){
        int result = 0;
        for (int j=0; j<100; j++){
            table = generator.intGenerator(generationType, amounts[i]);
            result += uruchomTest(algorytm, table);
        }
        results.push_back(to_string(result/100) + "ms");
    }

    return results;
}