#pragma once
#include "ISorter.h"
#include <vector>
#include <stdexcept>

template <typename T>
class QuickSort : public ISorter<T> {
private:
    int pivot = 0;
    int depth = 1;

    // Int sort
    void sortHidden(vector<T>& data, int l, int r, int pivot, int depth){
        if (depth > 1000) {
            throw std::runtime_error("Stack Overflow");
        }

        if(l < r){
            int m = partition(data, l, r, pivot);
            sortHidden(data, l, m, pivot, depth + 1);
            sortHidden(data, m+1, r, pivot, depth + 1);
        }
    }

    int partition(vector<T>& data, int leftIndex, int rightIndex, int pivotNum){
        int pivot;
        switch (pivotNum){
            case 1:
                // Pivot is the right
                pivot = data[rightIndex];
                break;

            case 2:
                // Pivot is the middle
                pivot = data[(leftIndex + rightIndex) / 2];
                break;
            
            case 3:
                // Pivot is random
                pivot = data[leftIndex + (rand() % (rightIndex - leftIndex + 1))];
                break;
            
            default:
                // Pivot is left (Default)
                pivot = data[leftIndex];
                break;
    }

    int l = leftIndex;
    int r = rightIndex;

    while(1){
        while(data[l]<pivot) ++l;
        while(data[r]>pivot) --r;

        if(l < r) {
            swap(data[l],data[r]);
            ++l;
            --r;
        } else {
            if (r == rightIndex) r--;
            return r;
        }
    }
}

public:
    QuickSort(int p = 0) {
        this->pivot = p;
    }

    void sort(vector<T>& data){
        int left = 0;
        int right = data.size() - 1;

        sortHidden(data, left, right, pivot, depth);
    }
};
