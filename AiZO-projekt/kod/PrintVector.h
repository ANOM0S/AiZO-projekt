#pragma once
#include <vector>

using namespace std;

// Class that will print vector.
template <typename T>
class PrintVector {
public:
    void printVector(vector<T>& vec) {
        cout << endl << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i != vec.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};