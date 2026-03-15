#include <iostream>
#include <vector>
#include <fstream>

#include "Tester.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "PrintVector.h"
#include "DataGenerator.h"
#include "InsertionSort.h"
#include "HeapSort.h"

using namespace std;

int main() {
    Tester tester;
    DataGenerator generator;
    HeapSort heapSort;
    ShellSort shellSort(1);
    PrintVector printer;
    
    vector<int> table = generator.intGenerator(0,20);
    printer.printVector(table);
    tester.uruchomTest(shellSort, table);
    printer.printVector(table);

    return 0;
}