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

        HybridSort<T> hybridSort10(10);
        HybridSort<T> hybridSort35(35);
        HybridSort<T> hybridSort75(75);
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
                case 4: cout << "\n--- Rozpoczynam testy 33\% posortowanej generacji ---" << endl; break;
                case 5: cout << "\n--- Rozpoczynam testy 66\% posortowanej generacji ---" << endl; break;
            }

            cout << endl << "Hybrid Sort (threshold = 10):";
            results = tester.benchmark(hybridSort10, sizes, genType);
            printer.printVector(results);

            cout << endl << "Hybrid Sort: (threshold = 35):";
            results = tester.benchmark(hybridSort35, sizes, genType);
            printer.printVector(results);

            cout << endl << "Hybrid Sort (threshold = 75):";
            results = tester.benchmark(hybridSort75, sizes, genType);
            printer.printVector(results);
            
            cout << endl << "Quick Sort (Left):";
            results = tester.benchmark(quickSortLeft, sizes, genType);
            printer.printVector(results);
            
            cout << endl << "Quick Sort (Right):";
            results = tester.benchmark(quickSortRight, sizes, genType);
            printer.printVector(results);
            
            cout << endl << "Quick Sort (Middle):";
            results = tester.benchmark(quickSortMiddle, sizes, genType);
            printer.printVector(results);
            
            cout << endl << "Quick Sort (Random):";
            results = tester.benchmark(quickSortRandom, sizes, genType);
            printer.printVector(results);
            
            cout << endl << "Heap Sort:";
            results = tester.benchmark(heapSort, sizes, genType);
            printer.printVector(results);
            
            cout << endl << "Shell Sort (Shell):";
            results = tester.benchmark(shellSort, sizes, genType);
            printer.printVector(results);
            
            cout << endl << "Shell Sort (Frank&Lazarus):";
            results = tester.benchmark(shellSortFrank, sizes, genType);
            printer.printVector(results);
        }

        cout << endl << "\nTesty zakonczone!";
    }
};