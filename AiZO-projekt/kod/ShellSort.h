#pragma once
#include "ISorter.h"
#include <vector>

// Shell sort algorithm using ISorter interface.
class ShellSort : public ISorter {
private:
    int gapSelector;

    void shellSort(std::vector<int>& data, int power, int n, int gapSelector);
    void shellSort(std::vector<double>& data, int power, int n, int gapSelector);
public:
    ShellSort(int gapSelector = 1){
        this->gapSelector = gapSelector;
    }

    void sort(std::vector<int>& data) override; 
    void sort(std::vector<double>& data) override; 
};
