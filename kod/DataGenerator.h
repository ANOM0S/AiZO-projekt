#pragma once
#include <vector>

using namespace std;

// Definicja generatora.
class DataGenerator {
public:
    vector<int> intGenerator(int amount, int type = 0);
    vector<float> floatGenerator(int amount, int type = 0);
};