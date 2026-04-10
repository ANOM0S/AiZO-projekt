#pragma once
#include <vector>

using namespace std;

// Klasa "drukarki" do pokazywania zawartości tabel
template <typename T>
class PrintVector {
public:
    // Wyświetlanie vector'a
    void printVector(vector<T>& vec) {
        cout << endl << "[";
        // Petla po elementach vector'a
        for (size_t i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i != vec.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};