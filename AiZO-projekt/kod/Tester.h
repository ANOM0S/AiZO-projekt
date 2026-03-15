#pragma once
#include "ISorter.h"
#include <vector>
#include <string>

using namespace std;

// Defining the class Tester.
class Tester {
public:
    vector<string> benchmark(ISorter& algorytm, vector<int>& amounts, int generationType);
    int uruchomTest(ISorter& algorytm, vector<int>& dane);
};
