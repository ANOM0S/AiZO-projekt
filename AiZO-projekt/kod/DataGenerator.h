#pragma once
#include <vector>

using namespace std;

// Defining the generator functions
class DataGenerator {
public:
    vector<int> intGenerator(int type, int amount);
    vector<double> floatGenerator(int type, int amount);
};