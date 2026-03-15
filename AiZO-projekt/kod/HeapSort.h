#pragma once
#include "ISorter.h"
#include <vector>

// Creating a HeapSort class that inherits from ISorter interface
class HeapSort : public ISorter {
private:
    void heapify(std::vector<int>& data, int i, int n);
    void heapify(std::vector<double>& data, int i, int n);

public:
    void sort(std::vector<int>& data) override; 
    void sort(std::vector<double>& data) override; 
};