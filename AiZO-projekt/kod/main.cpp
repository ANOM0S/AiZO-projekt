#include <iostream>
#include <vector>

#include "Tester.h"
#include "PrintVector.h"
#include "DataGenerator.h"
#include "InsertionSort.h"

using namespace std;

int main() {
    DataGenerator generator;
    InsertionSort insertionSort;
    Tester tester;

    int sumTime;
    vector<int> intTable;
    
    for (int i = 0; i < 100; i++){
        intTable = generator.intGenerator(1,10000);
        sumTime += tester.uruchomTest(insertionSort, intTable);
    }

    cout << sumTime/100 << " ms";
    


    return 0;
}