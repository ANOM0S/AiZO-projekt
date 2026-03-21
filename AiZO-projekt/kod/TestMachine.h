#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// Dołączenie odpowiednich algorytmów i testerów
#include "TestMachine.h"
#include "DataGenerator.h"
#include "Tester.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "HybridSort.h"
#include "PrintVector.h"

using namespace std;

// Klasa maszyny testowej do przeprowadzenia całego testu do wyników do sprawozdania.
template <typename T>
class TestMachine {
public:
    // Funkcja przeprowadzająca testy
    void playTestScenario() {
        // Stworzenie instancji klas
        Tester<T> tester;
        DataGenerator generator;
        PrintVector<string> printer;

        // Stworzenie instancji sorterów
        HybridSort<T> hybridSort10(10);
        HybridSort<T> hybridSort25(25);
        HybridSort<T> hybridSort100(100);
        QuickSort<T> quickSortLeft(0);
        QuickSort<T> quickSortRight(1);
        QuickSort<T> quickSortMiddle(2);
        QuickSort<T> quickSortRandom(3);
        HeapSort<T> heapSort;
        ShellSort<T> shellSort(1);
        ShellSort<T> shellSortFrank(2);

        // Tablica z wynikami
        vector<string> results;
        
        // Rozmiary - na podstawie testów wybrałem te wartości:
        vector<int> sizes = {50000, 100000, 250000, 500000, 1000000, 2500000, 5000000};
        
        // Pętla po wszystkich trybach generacji (od 1 do 5)
        int typeOfGeneration;

        // "Main loop" testera
        while (1) {
            // Wybór rodzaju generowania.
            cout << "Podaj typ generowania:" << endl;
            cin >> typeOfGeneration;

            // Wyświetlenie z którego typu korzystamy.
            switch (typeOfGeneration) {
                case 1: cout << "\n--- Rozpoczynam testy normalnej generacji ---" << endl; break;
                case 2: cout << "\n--- Rozpoczynam testy posortowanej generacji ---" << endl; break;
                case 3: cout << "\n--- Rozpoczynam testy odwrotnie posortowanej generacji ---" << endl; break;
                case 4: cout << "\n--- Rozpoczynam testy 33\% posortowanej generacji ---" << endl; break;
                case 5: cout << "\n--- Rozpoczynam testy 66\% posortowanej generacji ---" << endl; break;
            }

            // przeprowadzanie testów dla różnych algorytmów sortowania oraz wyświetlenie ich średnich wyników
            cout << endl << "Hybrid Sort (threshold = 10):";
            results = tester.benchmark(hybridSort10, sizes, typeOfGeneration);
            printer.printVector(results);

            cout << endl << "Hybrid Sort: (threshold = 25):";
            results = tester.benchmark(hybridSort25, sizes, typeOfGeneration);
            printer.printVector(results);

            cout << endl << "Hybrid Sort (threshold = 100):";
            results = tester.benchmark(hybridSort100, sizes, typeOfGeneration);
            printer.printVector(results);
            
            cout << endl << "Quick Sort (Left):";
            results = tester.benchmark(quickSortLeft, sizes, typeOfGeneration);
            printer.printVector(results);
            
            cout << endl << "Quick Sort (Right):";
            results = tester.benchmark(quickSortRight, sizes, typeOfGeneration);
            printer.printVector(results);
            
            cout << endl << "Quick Sort (Middle):";
            results = tester.benchmark(quickSortMiddle, sizes, typeOfGeneration);
            printer.printVector(results);
            
            cout << endl << "Quick Sort (Random):";
            results = tester.benchmark(quickSortRandom, sizes, typeOfGeneration);
            printer.printVector(results);
            
            cout << endl << "Heap Sort:";
            results = tester.benchmark(heapSort, sizes, typeOfGeneration);
            printer.printVector(results);
            
            cout << endl << "Shell Sort (Shell):";
            results = tester.benchmark(shellSort, sizes, typeOfGeneration);
            printer.printVector(results);
            
            cout << endl << "Shell Sort (Frank&Lazarus):";
            results = tester.benchmark(shellSortFrank, sizes, typeOfGeneration);
            printer.printVector(results);
        }

        // Informacja o zakończeniu danego testu!
        cout << endl << "\nTesty zakonczone!";
    }
};