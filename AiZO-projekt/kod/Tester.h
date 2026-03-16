#pragma once
#include "ISorter.h"
#include <vector>
#include <string>

using namespace std;

// Defining the class Tester.
class Tester {
public:
    // INT
    vector<string> benchmarkInt(ISorter& algorytm, vector<int>& amounts, int generationType);
    int uruchomTest(ISorter& algorytm, vector<int>& dane);

    // FLOAT
    vector<string> benchmarkFloat(ISorter& algorytm, vector<int>& amounts, int generationType);
    int uruchomTest(ISorter& algorytm, vector<double>& dane);
};
