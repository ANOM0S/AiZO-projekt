#include <iostream>
#include <vector>

#include "Tester.h"
#include "QuickSort.h"
#include "PrintVector.h"
#include "DataGenerator.h"
#include "InsertionSort.h"

using namespace std;

int main() {
    DataGenerator generator;
    QuickSort quickSort(0);
    InsertionSort insertionSort;
    Tester tester;

    vector<int> table = generator.intGenerator(3,500);
    cout << tester.uruchomTest(quickSort,table);


    return 0;
}