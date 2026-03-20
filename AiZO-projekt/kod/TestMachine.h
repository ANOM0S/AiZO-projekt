#pragma once

#include "TestMachine.h"
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

#include "DataGenerator.h"
#include "Tester.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "HybridSort.h"
#include "PrintVector.h"

using namespace std;
template <typename T>
class TestMachine {
public:
    void playTestScenario() {
        Tester<T> tester;
        DataGenerator generator;
        PrintVector<string> printer;

        HybridSort<T> hybridSort;
        QuickSort<T> quickSortLeft(0);
        QuickSort<T> quickSortRight(1);
        QuickSort<T> quickSortMiddle(2);
        QuickSort<T> quickSortRandom(3);
        HeapSort<T> heapSort;
        ShellSort<T> shellSort(1);
        ShellSort<T> shellSortFrank(2);

        vector<string> results;
        
        // Rozmiary - dostosuj w razie potrzeby, tu wziąłem z Twojego kodu dla Int
        vector<int> sizes = {50000, 100000, 200000, 400000, 600000, 1000000, 1400000};
        
        cout << "Rozpoczynam zautomatyzowane testy..." << endl;

        // Pętla po wszystkich trybach generacji (od 1 do 5)
        for (int genType = 1; genType <= 5; ++genType) {
            
            switch (genType) {
                case 1: cout << "\n--- Rozpoczynam testy normalnej generacji ---" << endl; break;
                case 2: cout << "\n--- Rozpoczynam testy posortowanej generacji ---" << endl; break;
                case 3: cout << "\n--- Rozpoczynam testy odwrotnie posortowanej generacji ---" << endl; break;
                case 4: cout << "\n--- Rozpoczynam testy 33% posortowanej generacji ---" << endl; break;
                case 5: cout << "\n--- Rozpoczynam testy 66% posortowanej generacji ---" << endl; break;
            }

            cout << "Hybrid Sort:" << endl;
            results = tester.benchmark(hybridSort, sizes, genType);
            printer.printVector(results);
            
            cout << "Quick Sort (Left):" << endl;
            results = tester.benchmark(quickSortLeft, sizes, genType);
            printer.printVector(results);
            
            cout << "Quick Sort (Right):" << endl;
            results = tester.benchmark(quickSortRight, sizes, genType);
            printer.printVector(results);
            
            cout << "Quick Sort (Middle):" << endl;
            results = tester.benchmark(quickSortMiddle, sizes, genType);
            printer.printVector(results);
            
            cout << "Quick Sort (Random):" << endl;
            results = tester.benchmark(quickSortRandom, sizes, genType);
            printer.printVector(results);
            
            cout << "Heap Sort:" << endl;
            results = tester.benchmark(heapSort, sizes, genType);
            printer.printVector(results);
            
            cout << "Shell Sort (1):" << endl;
            results = tester.benchmark(shellSort, sizes, genType);
            printer.printVector(results);
            
            cout << "Shell Sort (2):" << endl;
            results = tester.benchmark(shellSortFrank, sizes, genType);
            printer.printVector(results);
        }

        cout << "\nTesty zakonczone!" << endl;
    }
};