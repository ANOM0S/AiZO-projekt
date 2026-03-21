#pragma once
#include <vector>

using namespace std;

// Defining the generator functions
class DataGenerator {
public:
    vector<int> intGenerator(int amount, int type = 0);
    vector<float> floatGenerator(int amount, int type = 0);
};