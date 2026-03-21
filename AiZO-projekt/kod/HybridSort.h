#pragma once
#include "ISorter.h"
#include <vector>

// Defining a class of a simple insertion sorter using ISorter interface. 
template <typename T>
class HybridSort : public ISorter<T> {
    private:
    int pivot = 2;
    int depth = 1;
    int threshold;

    void insertionSort(std::vector<T>& data, int l, int r) {
        for (int i = l + 1; i <= r; i++) {
            T key = data[i];
            int j = i - 1;
            while (j >= l && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }

    // Int sort
    void sortHidden(vector<T>& data, int l, int r, int pivot, int depth){
        if (depth > 1000) {
            throw std::runtime_error("Stack Overflow - przerwano dzialanie QuickSorta");
        }

        if(r - l + 1 > threshold){
            int m = partition(data, l, r, pivot);

            if(m-l>threshold){
                sortHidden(data, l, m, pivot, depth + 1);
            } else {
                insertionSort(data, l, m);
            }

            if(r-(m+1)>threshold){
                sortHidden(data, m+1, r, pivot, depth + 1);
            } else {
                insertionSort(data, m+1, r);
            }
            
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
                pivot = rand() % data.size();
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
    HybridSort(int threshold = 5, int p = 2) {
        this->pivot = p;
        this->threshold = threshold;
    }

    void sort(vector<T>& data){
        int left = 0;
        int right = data.size() - 1;

        sortHidden(data, left, right, pivot, depth);
    }
};
