// Including c++ libraries
#include <iostream>
#include <vector>
#include <fstream>

// Including header files
#include "Tester.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "PrintVector.h"
#include "DataGenerator.h"
#include "InsertionSort.h"
#include "HeapSort.h"

using namespace std;

int main() {
    // Creating instances
    Tester tester;
    DataGenerator generator;
    PrintVector printer;

    // Sorters
    InsertionSort insertionSort;
    QuickSort quickSortLeft(0);
    QuickSort quickSortRight(1);
    QuickSort quickSortMiddle(2);
    QuickSort quickSortRandom(3);
    HeapSort heapSort;
    ShellSort shellSort(1);
    ShellSort shellSortFrank(2);

    // Variables for main loop.
    vector<int> intTable;
    vector<double> doubleTable;
    int actionType;
    string fileName;

    string actions = R"(
|-------------------------------|
|0 -> Wyswietl akcje            |
|1 -> Wczytaj dane z pliku      |
|2 -> Wygeneruj tabele          |
|3 -> Wyswietl tabele           |
|4 -> Posortuj tabele           |
|5 -> Wykonaj pelna symulacje   |
|6 -> cofnij / wylacz program   |
|-------------------------------|
)";

    // Main Loop:
    while(1){
        string testType;
        cout << "Podaj nazwe typu danych [int/float]: " << endl;
        cin >> testType;

        if (testType == "6") exit(0);
        cout << actions;

        while (testType == "Int" || testType == "int"){
            cout << "Podaj rodzaj akcji ktora chcesz podjac: " << endl;
            cin >> actionType;

            switch (actionType) {
                case 0:
                    cout << actions;
                    break;
                
                case 1: 
                {
                    cout << "Podaj nazwe pliku: " << endl;
                    cin >> fileName;

                    // Wczytanie pliku
                    ifstream inFile(fileName);

                    // Ustawienie wielkości 
                    int size;
                    inFile >> size;
                    intTable.reserve(size);

                    // Wczytanie wszystkich danych
                    int a;
                    while (inFile >> a){
                        intTable.push_back(a);
                    }
                    break; 
                }

                case 2:
                    int amount;
                    cout << "Podaj ilosc danych: " << endl;
                    cin >> amount;

                    intTable = generator.intGenerator(amount);
                    break;

                case 3:
                    printer.printVector(intTable);
                    break;

                case 4:

                case 5:

                case 6:
                    testType = " ";
                    break;
                
                default:
                    cout << "Zła komenda!";
                    break;
            }
        }

        while (testType == "float" || testType == "Float"){
            cout << "Podaj rodzaj akcji którą chcesz podjac: " << endl;
            cin >> actionType;

switch (actionType) {
                case 0:
                    cout << actions;
                    break;
                
                case 1: 
                {
                    cout << "Podaj nazwe pliku: " << endl;
                    cin >> fileName;

                    // Wczytanie pliku
                    ifstream inFile(fileName);

                    // Ustawienie wielkości 
                    int size;
                    inFile >> size;
                    intTable.reserve(size);

                    // Wczytanie wszystkich danych
                    int a;
                    while (inFile >> a){
                        intTable.push_back(a);
                    }
                    break; 
                }

                case 2:
                    int amount;
                    cout << "Podaj ilosc danych: " << endl;
                    cin >> amount;

                    doubleTable = generator.floatGenerator(amount);
                    break;

                case 3:
                    printer.printVector(doubleTable);
                    break;

                case 4:

                case 5:

                case 6:
                    testType = " ";
                    break;
                
                default:
                    cout << "Zła komenda!";
                    break;
            }

        }
    }

    


    // Generating data:
    // vector<int> sizes = {100000, 200000, 500000};
    // vector<string> times;

    // times = tester.benchmark(insertionSort, sizes, 1);
    // printer.printVector(times);

    // times = tester.benchmark(heapSort, sizes, 1);
    // printer.printVector(times);

    // times = tester.benchmark(shellSort, sizes, 1);
    // printer.printVector(times);

    // times = tester.benchmark(quickSortLeft, sizes, 1);
    // printer.printVector(times);

    // times = tester.benchmark(quickSortMiddle, sizes, 1);
    // printer.printVector(times);

    return 0;
}