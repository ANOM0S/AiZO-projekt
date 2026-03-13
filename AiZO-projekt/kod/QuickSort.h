#pragma once
#include "ISorter.h"
#include <vector>

class QuickSort : public ISorter {
public:
    void sort(std::vector<int>& data) override;
};
