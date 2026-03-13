#include <iostream>
#include "ISorter.h"

using namespace std;

class ShellSort : public ISorter {
    public:
        void sort(std::vector<int>& data) override {
            cout << "Test print";
        }
};
