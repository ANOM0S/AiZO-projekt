#pragma once
#include "ISorter.h"
#include "DataGenerator.h"
#include "PrintVector.h"
#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <type_traits> 

using namespace std;

template <typename T>
class Tester {
public:
    PrintVector<int> printVector;

    vector<string> benchmark(ISorter<T>& algorytm, vector<int>& amounts, int generationType){
        DataGenerator generator;
        vector<T> table;
        vector<string> results;

        for (int i = 0; i < amounts.size(); i++){
            long long result = 0; 
            bool testFailed = false; // Flaga, czy wybuchło
            
            for (int j = 0; j < 100; j++){
                if constexpr (is_same_v<T, int>) {
                    table = generator.intGenerator(amounts[i], generationType);
                } 
                else if constexpr (is_same_v<T, float>) {
                    table = generator.floatGenerator(amounts[i], generationType);
                }

                try {
                    result += uruchomTest(algorytm, table);
                } 
                catch (const std::runtime_error& e) {
                    cout << "   [!] Przerwano test dla rozmiaru " << amounts[i] 
                         << " - Powod: " << e.what() << endl;
                    
                    results.push_back("BLAD");
                    
                    testFailed = true;
                    break; 
                }
            }

            // Jeśli test przeszedł bez wybuchu, dopisujemy średni czas
            if (!testFailed) {
                results.push_back(to_string(result / 100) + " ms"); 
            }
        }

        return results;
    }

    long long uruchomTest(ISorter<T>& algorytm, vector<T>& dane) {
        // 1. Starting timer
        auto start = std::chrono::high_resolution_clock::now();

        // 2. Sorting data
        algorytm.sort(dane);

        // 3. stoping timer
        auto stop = std::chrono::high_resolution_clock::now();

        // Zabezpieczenie poprawności sortowania
        for (int i = 0; i < dane.size() - 1; i++){
            if(dane[i] > dane[i+1]){
                cout << "Blad w sortowaniu tablicy!!! Index: " << i << endl;
                exit(0);
            }
        }

        // 4. Calculating the difference
        long long czasTrwania = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

        // 5. Returning the time.
        return czasTrwania;
    }
};