#pragma once
#include <iostream>
#include <vector>

using namespace std;

class PrintVector {
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
};