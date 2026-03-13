#pragma once
#include "ISorter.h"
#include <vector>

class InsertionSort : public ISorter {
public:
    void sort(std::vector<int>& data) override;
    void sort(std::vector<double>& data) override;
};
