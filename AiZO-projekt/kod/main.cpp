#include <iostream>
#include <vector>

#include "DataGenerator.h"
// #include "HeapSort.h"
#include "InsertionSort.h"
// #include "QuickSort.h"
// #include "ShellSort.h"
// #include "Tester.h"

using namespace std;

// Helper function to print vector<int>
void printVector(const vector<int>& vec) {
    cout << endl << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ", ";
    }
    cout << "]";
}
void printVector(const vector<double>& vec) {
    cout << endl << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    DataGenerator generator;
    InsertionSort insertionSorter;

    vector<int> table = generator.intGenerator(1, 10);
    printVector(table);
    insertionSorter.sort(table);
    printVector(table);

    // table = generator.intGenerator(2, 10);
    // printVector(table);

    // table = generator.intGenerator(3, 10);
    // printVector(table);

    // table = generator.intGenerator(4, 10);
    // printVector(table);

    // table = generator.intGenerator(5, 10);
    // printVector(table);

    vector<double> floatTable = generator.floatGenerator(1, 10);
    printVector(floatTable);

    insertionSorter.sort(floatTable);
    printVector(floatTable);

    // floatTable = generator.floatGenerator(2, 10);
    // printVector(floatTable);

    // floatTable = generator.floatGenerator(3, 10);
    // printVector(floatTable); 

    // floatTable = generator.floatGenerator(4, 10);
    // printVector(floatTable);

    // floatTable = generator.floatGenerator(5, 10);
    // printVector(floatTable);

    return 0;
}