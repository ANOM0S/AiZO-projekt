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
    // General
    DataGenerator generator;
    string fileName;
    int actionType;
    int sortingType;
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
    string sortingTypes = R"(
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

    Tester<int> intTester;
    vector<int> intTable;
    vector<int> intTableCopy;
    vector<int> sortedIntTable;
    PrintVector<int> intPrinter;

    // Sorters - wszystkie muszą wiedzieć, że na ten moment sortują floaty
    HybridSort<float> floatHybridSort(15);
    QuickSort<float> floatQuickSortLeft(0);
    QuickSort<float> floatQuickSortRight(1);
    QuickSort<float> floatQuickSortMiddle(2);
    QuickSort<float> floatQuickSortRandom(3);
    HeapSort<float> floatHeapSort;
    ShellSort<float> floatShellSort(1);
    ShellSort<float> floatShellSortFrank(2);
    TestMachine<float> floatTestMachine;

    Tester<float> floatTester;
    vector<float> floatTable; 
    vector<float> floatTableCopy;
    vector<float> sortedFloatTable;
    PrintVector<float> floatPrinter;

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
                    cout << sortingTypes;
                    cin >> sortingType;

                    // Switch z wyborem sortowania
                    switch (sortingType){
                        // Hybrid sort
                        case 1:
                            intTester.uruchomTest(hybridSort, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;
                        
                        // Quick sort (Lewy)
                        case 2:
                            intTester.uruchomTest(quickSortLeft, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Quick sort (Prawy)
                        case 3:
                            intTester.uruchomTest(quickSortRight, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Quick sort (Środkowy)
                        case 4:
                            intTester.uruchomTest(quickSortMiddle, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Quick sort losowy
                        case 5:
                            intTester.uruchomTest(quickSortRandom, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Heap sort
                        case 6:
                            intTester.uruchomTest(heapSort, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break; 

                        // Shell sort (shell)
                        case 7:
                            intTester.uruchomTest(shellSort, intTableCopy);
                            sortedIntTable.assign(intTableCopy.begin(), intTableCopy.end());
                            intPrinter.printVector(sortedIntTable);
                            break;

                        // Shell sort (Frank & Lazarus)
                        case 8:
                            intTester.uruchomTest(shellSortFrank, intTableCopy);
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

// ++++++++++++++++++++++++++++ FLOAT +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        // Pętla działająca dla danych typu float
        while (testType == "float" || testType == "Float"){
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
                floatTable.reserve(size);

                // Wczytanie wszystkich danych
                float a;
                while (inFile >> a){
                    floatTable.push_back(a);
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

                floatTable = generator.floatGenerator(amount);
                break;

            // Wyświetlenie tablicy przed sortowaniem
            case 3:
                if(floatTable.empty()){
                cout << "Tabela jest pusta" << endl;
                break;
                }
                floatPrinter.printVector(floatTable);
                break;
            
            // Wyświetlenie tablicy po sortowaniu
            case 4:
                if(sortedFloatTable.empty()){
                cout << "Tabela jest pusta" << endl;
                break;
                }

                floatPrinter.printVector(sortedFloatTable);
                break;
            
            // Sortowanie z wybieraniem sposobu
            case 5:
                if(floatTable.empty()){
                cout << "Nie dodano rzadnej tabeli" << endl;
                break;
                }

                // Kopiowanie tabeli
                floatTableCopy.assign(floatTable.begin(), floatTable.end());

                // Wyświetlenie rodzajów sortowania.
                cout << sortingTypes;
                cin >> sortingType;

                // Switch z wyborem sortowania
                switch (sortingType){
                // Hybrid sort
                case 1:
                    floatTester.uruchomTest(floatHybridSort, floatTableCopy);
                    sortedFloatTable.assign(floatTableCopy.begin(), floatTableCopy.end());
                    floatPrinter.printVector(sortedFloatTable);
                    break;
                
                // Quick sort (Lewy)
                case 2:
                    floatTester.uruchomTest(floatQuickSortLeft, floatTableCopy);
                    sortedFloatTable.assign(floatTableCopy.begin(), floatTableCopy.end());
                    floatPrinter.printVector(sortedFloatTable);
                    break;

                // Quick sort (Prawy)
                case 3:
                    floatTester.uruchomTest(floatQuickSortRight, floatTableCopy);
                    sortedFloatTable.assign(floatTableCopy.begin(), floatTableCopy.end());
                    floatPrinter.printVector(sortedFloatTable);
                    break;

                // Quick sort (Środkowy)
                case 4:
                    floatTester.uruchomTest(floatQuickSortMiddle, floatTableCopy);
                    sortedFloatTable.assign(floatTableCopy.begin(), floatTableCopy.end());
                    floatPrinter.printVector(sortedFloatTable);
                    break;

                // Quick sort losowy
                case 5:
                    floatTester.uruchomTest(floatQuickSortRandom, floatTableCopy);
                    sortedFloatTable.assign(floatTableCopy.begin(), floatTableCopy.end());
                    floatPrinter.printVector(sortedFloatTable);
                    break;

                // Heap sort
                case 6:
                    floatTester.uruchomTest(floatHeapSort, floatTableCopy);
                    sortedFloatTable.assign(floatTableCopy.begin(), floatTableCopy.end());
                    floatPrinter.printVector(sortedFloatTable);
                    break; 

                // Shell sort (shell)
                case 7:
                    floatTester.uruchomTest(floatShellSort, floatTableCopy);
                    sortedFloatTable.assign(floatTableCopy.begin(), floatTableCopy.end());
                    floatPrinter.printVector(sortedFloatTable);
                    break;

                // Shell sort (Frank & Lazarus)
                case 8:
                    floatTester.uruchomTest(floatShellSortFrank, floatTableCopy);
                    sortedFloatTable.assign(floatTableCopy.begin(), floatTableCopy.end());
                    floatPrinter.printVector(sortedFloatTable);
                    break;

                // Informacja o błędnym wyborze
                default:
                    cout << "Bledny typ sortowania";
                    break;
                }
                break;

            // Przeprowadzenie pełnej symulacji
            case 6:
                floatTestMachine.playTestScenario();
                break;
            
            // Jeżeli błąd to cofnięcie programu
            default:
                testType = " ";
                break;
            }
        }
        }

    return 0;
}