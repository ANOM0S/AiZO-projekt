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
#include "HybridSort.h"
#include "HeapSort.h"
#include "testMachine.h"
#include "HybridSort.h"

using namespace std;

int main() {
// Creating instances
    Tester<int> tester; // Tester też jest teraz szablonem!
    DataGenerator generator;
    PrintVector<int> intPrinter;
    PrintVector<double> floatPrinter;

    // Sorters - wszystkie muszą wiedzieć, że na ten moment sortują inty
    HybridSort<int> hybridSort(15);
    QuickSort<int> quickSortLeft(0);
    QuickSort<int> quickSortRight(1);
    QuickSort<int> quickSortMiddle(2);
    QuickSort<int> quickSortRandom(3);
    HeapSort<int> heapSort;
    ShellSort<int> shellSort(1);
    ShellSort<int> shellSortFrank(2);
    TestMachine<int> intTestMachine; 

    // Sorters - for float 
    // TestMachine<double> floatTestMachine;
    // InsertionSort<double> insertionSort;
    // QuickSort<double> quickSortLeft(0);
    // QuickSort<double> quickSortRight(1);
    // QuickSort<double> quickSortMiddle(2);
    // QuickSort<double> quickSortRandom(3);
    // HeapSort<double> heapSort;
    // ShellSort<double> shellSort(1);
    // ShellSort<double> shellSortFrank(2);

    // Variables for main loop.
    // Tables
    vector<int> intTable;
    vector<double> doubleTable; 
    vector<int> intTableCopy;
    vector<double> doubleTableCopy;
    vector<int> sortedIntTable;
    vector<double> sorteDoubleTable;

    // 
    int actionType;
    int sortingType;
    string fileName;

    string actions = R"(
|-------------------------------------------|
|0 -> Wyswietl akcje                        |
|1 -> Wczytaj dane z pliku                  |
|2 -> Wygeneruj tabele                      |
|3 -> Wyswietl tabele (przed sortowaniem)   |
|4 -> Wyswietl tabele (po sortowaniu)       |
|5 -> Posortuj tabele                       |
|6 -> Wykonaj pelna symulacje               |
|7 -> cofnij / wylacz program               |
|-------------------------------------------|
)";

    // Main Loop:
    while(1){
        string testType;
        // Wybór typu testów.
        cout << "Podaj nazwe typu danych [int/float/exit]: " << endl;
        cin >> testType;

        // Wyjście z programu po wpisaniu "exit" w konsoli.
        if (testType == "exit") exit(0);

        // Wyświetlanie "pomocy".
        cout << actions;

        // Pętla działająca dla danych typu int
        while (testType == "Int" || testType == "int"){
            // Wybór akcji
            cout << "Podaj rodzaj akcji ktora chcesz podjac: " << endl;
            cin >> actionType;

            // Switch po konkretnych akcji
            switch (actionType) {
                // Wyświetlenie pomocy
                case 0:
                    cout << actions;
                    break;
                
                // Wczytanie danych z pliku
                case 1: 
                {
                    cout << "Podaj nazwe pliku: " << endl;
                    cin >> fileName;

                    // Wczytanie pliku
                    ifstream inFile(fileName);
                    
                    if(!inFile.fail()){
                        // Ustawienie wielkości 
                        int size;
                        inFile >> size;
                        intTable.reserve(size);

                        // Wczytanie wszystkich danych
                        int a;
                        while (inFile >> a){
                            intTable.push_back(a);
                        }
                    } else {
                        cout << "Błąd w nazwie pliku!" << endl;
                    }

                    break; 
                }

                // Wygenerowanie danych
                case 2:
                    int amount;
                    cout << "Podaj ilosc danych: " << endl;
                    cin >> amount;

                    intTable = generator.intGenerator(amount);
                    break;

                // Wyświetlenie tablicy przed sortowaniem
                case 3:
                    if(intTable.empty()){
                        cout << "Tabela jest pusta" << endl;
                        break;
                    }
                    intPrinter.printVector(intTable);
                    break;
                
                // Wyświetlenie tablicy po sortowaniu
                case 4:
                    if(sortedIntTable.empty()){
                        cout << "Tabela jest pusta" << endl;
                        break;
                    }

                    intPrinter.printVector(sortedIntTable);
                    break;
                
                // Sortowanie z wybieraniem sposobu
                case 5:
                    if(intTable.empty()){
                        cout << "Nie dodano rzadnej tabeli" << endl;
                        break;
                    }

                    // Kopiowanie tabeli
                    intTableCopy.assign(intTable.begin(), intTable.end());

                    // Wyświetlenie rodzajów sortowania.
                    cout << R"(
|-----------------------------------|
|Wybierz opcje sortowania:          |
|1 -> Hybrid sort                   |
|2 -> Quick sort (lewy)             |
|3 -> Quick sort (prawy)            |
|4 -> Quick sort (srodkowy)         |
|5 -> Quick sort (losowy)           |
|6 -> heap sort                     |
|7 -> Shell sort (shell)            |
|8 -> Shell sort (Frank & Lazarus)  |
|-----------------------------------|
)";
                    cin >> sortingType;

                    // Switch z wyborem sortowania
                    switch (sortingType){
                        // Hybrid sort
                        case 1:
                            tester.uruchomTest(hybridSort, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;
                        
                        // Quick sort (Lewy)
                        case 2:
                            tester.uruchomTest(quickSortLeft, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Quick sort (Prawy)
                        case 3:
                            tester.uruchomTest(quickSortRight, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Quick sort (Środkowy)
                        case 4:
                            tester.uruchomTest(quickSortMiddle, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Quick sort losowy
                        case 5:
                            tester.uruchomTest(quickSortRandom, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Heap sort
                        case 6:
                            tester.uruchomTest(heapSort, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break; 

                        // Shell sort (shell)
                        case 7:
                            tester.uruchomTest(shellSort, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Shell sort (Frank & Lazarus)
                        case 8:
                            tester.uruchomTest(shellSortFrank, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Informacja o błędnym wyborze
                        default:
                            cout << "Bledny typ sortowania";
                            break;
                    }
                    break;

                // Przeprowadzenie pełnej symulacji
                case 6:
                    intTestMachine.playTestScenario();
                    break;
                
                // Jeżeli błąd to cofnięcie programu
                default:
                    testType = " ";
                    break;
            }
        }

        // Pętla działająca dla danych typu double (float)
        while (testType == "float" || testType == "Float"){
            cout << "Podaj rodzaj akcji którą chcesz podjac: " << endl;
            cin >> actionType;

        }
    }

    return 0;
}