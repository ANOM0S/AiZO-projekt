#include <algorithm>
#include "InsertionSort.h"

// Simple insertion sort algorithm.

// +++++++++++++++++++++++++++++++++++++++++++++++ INT SORTER ++++++++++++++++++++++++++++++++++++++++++++
void InsertionSort::sort(std::vector<int>& data) {
    for (int i = 1; i<data.size(); i++){
        for (int j = i; j>0; j--){
            if(data[j]<data[j-1]){
                std::swap(data[j],data[j-1]);
            }else{
                break;
            }
        }
    }
}

// +++++++++++++++++++++++++++++++++++++++++++++++ FLOAT SORTER ++++++++++++++++++++++++++++++++++++++++++++
void InsertionSort::sort(std::vector<double>& data) {
    for (int i = 1; i<data.size(); i++){
        for (int j = i; j>0; j--){
            if(data[j]<data[j-1]){
                std::swap(data[j],data[j-1]);
            }else{
                break;
            }
        }
    }
}