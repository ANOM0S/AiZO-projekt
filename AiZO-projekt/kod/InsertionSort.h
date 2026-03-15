#pragma once
#include "ISorter.h"
#include <vector>

// Defining a class of a simple insertion sorter using ISorter interface. 
class InsertionSort : public ISorter {
public:
    void sort(std::vector<int>& data) override;
    void sort(std::vector<double>& data) override;
};
