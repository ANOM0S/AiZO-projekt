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
    

    // Connecting to a file with predefined array to test sorting algorithms
    ifstream inFile("./predefined/definedArray.txt");
    
    // Creating the testArray with defined size of first line in file
    vector<int> testArray;
    int size;
    inFile >> size;
    testArray.reserve(size);
    
    // Reading the file
    int a;
    while (inFile >> a){
        testArray.push_back(a);
    }
    

    // // Sorting etc.
    //     // Testing each sorter:
    //         // Printing array before sorting
    // cout << endl << "Original:"; 
    // printer.printVector(testArray);
    //         // Making copies of the array (cuz algorithms are working on real tables not the copy)
    // vector<int> arrayCopy;
    // arrayCopy.assign(testArray.begin(),testArray.end());
    //         // Testing each sorter while recreating the original array
    //             // Insertion sort
    // cout << endl << "insertion:";
    // tester.uruchomTest(insertionSort, arrayCopy);
    // printer.printVector(arrayCopy);
    // arrayCopy.assign(testArray.begin(),testArray.end());
    //             // Quick sort
    // cout << endl << "Quick:";
    // tester.uruchomTest(quickSortLeft, arrayCopy);
    // printer.printVector(arrayCopy);
    // arrayCopy.assign(testArray.begin(),testArray.end());
    //             // Heap sort
    // cout << endl << "Heap:";
    // tester.uruchomTest(heapSort, arrayCopy);
    // printer.printVector(arrayCopy);
    // arrayCopy.assign(testArray.begin(),testArray.end());
    //             // Shell sort
    // cout << endl << "Shell:";
    // tester.uruchomTest(shellSort, arrayCopy);
    // printer.printVector(arrayCopy);
    // arrayCopy.assign(testArray.begin(),testArray.end());

    // Generating data:
    vector<int> sizes = {100000, 200000, 500000};
    vector<string> times = tester.benchmark(shellSort, sizes, 1);
    printer.printVector(times);



    // Waiting for a input to end a program (for checking data)
    // cout << endl << endl << "Press ANYTHING to end the program" << endl;
    // // cin.get();

    return 0;
}