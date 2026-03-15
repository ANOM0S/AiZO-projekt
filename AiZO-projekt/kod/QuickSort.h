#pragma once
#include "ISorter.h"
#include <vector>

class QuickSort : public ISorter {
private:
    int pivot = 0;

    // Int sort
    void sortHidden(std::vector<int>& data, int l, int r, int pivot);
    int partition(std::vector<int>& data, int leftIndex, int rightIndex, int pivotNum);

    // Float sort
    void sortHidden(std::vector<double>& data, int l, int r, int pivot);
    int partition(std::vector<double>& data, int leftIndex, int rightIndex, int pivotNum);

public:
    QuickSort(int p = 0) {
        this->pivot = p;
    }

    void sort(std::vector<int>& data) override;
    void sort(std::vector<double>& data) override;
};
