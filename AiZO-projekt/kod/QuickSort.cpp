#include <iostream>

#include "ISorter.h"
#include "QuickSort.h"

using namespace std;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++ INT VALUES +++++++++++++++++++++++++++++++++++++++++++++++++++
void QuickSort::sort(vector<int>& data){
    int left = 0;
    int right = data.size() - 1;

    sortHidden(data, left, right, pivot);
}

void QuickSort::sortHidden(vector<int>& data, int l, int r, int pivot){
    if(l < r){
        int m = partition(data, l, r, pivot);
        sortHidden(data, l, m, pivot);
        sortHidden(data, m+1, r, pivot);
    }
}

int QuickSort::partition(vector<int>& data, int leftIndex, int rightIndex, int pivotNum){
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

// +++++++++++++++++++++++++++++++++++++++++++++++++++++ FLOAT VALUES +++++++++++++++++++++++++++++++++++++++++++++++++++
void QuickSort::sort(std::vector<double>& data){
    int left = 0;
    int right = data.size() - 1;

    sortHidden(data, left, right, pivot);
}

void QuickSort::sortHidden(vector<double>& data, int l, int r, int pivot){
    if(l < r){
        int m = partition(data, l, r, pivot);
        sortHidden(data, l, m, pivot);
        sortHidden(data, m+1, r, pivot);
    }
}

int QuickSort::partition(vector<double>& data, int leftIndex, int rightIndex, int pivotNum){
    int pivot = 0; // Bazowo lewo
    if (pivotNum == 0){
        pivot = data[leftIndex];
    } else if (pivotNum == 1) {
        pivot = data[rightIndex];
    } else if (pivotNum == 2){
        pivot = data[(leftIndex + rightIndex) / 2];
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
