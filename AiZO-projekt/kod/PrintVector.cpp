#include <iostream>
#include <vector>

#include "PrintVector.h"

using namespace std;

// ++++++++++++++++++++++++++++++++ INT VECTOR PRINTING +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void PrintVector::printVector(vector<int>& vec) {
    cout << endl << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// ++++++++++++++++++++++++++++++++++ FLOAT VECTOR PRINTING +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void PrintVector::printVector(vector<double>& vec) {
    cout << endl << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// ++++++++++++++++++++++++++++++++++ STRING VECTOR PRINTING +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void PrintVector::printVector(vector<string>& vec) {
    cout << endl << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}
