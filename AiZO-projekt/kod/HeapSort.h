#pragma once

#include <iostream>
#include <vector>
#include <utility>

#include "ISorter.h"

using namespace std;

// Creating a HeapSort class that inherits from ISorter interface
template <typename T>
class HeapSort : public ISorter<T> {
private:
    void heapify(vector<T>& table, int n, int i) {
        int largest = i;
        
        // childs indexes
        int left = 2 * i + 1;  
        int right = 2 * i + 2; 

        // 1. Comparing left child
        if (left < n && table[left] > table[largest]) {
            largest = left;
        }

        // 2. Comparing right child
        if (right < n && table[right] > table[largest]) {
            largest = right;
        }

        // 3. Checking if we need to swap
        if (largest != i) {
            swap(table[i], table[largest]);
            
            // Using recursion to go "deeper"
            heapify(table, n, largest);
        }
    }

public:
    void sort(vector<T>& data){
        int n = data.size();

        // Build heap (rearrange vector)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(data, n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(data[0], data[i]);

            // Call max heapify on the reduced heap
            heapify(data, i, 0);
        }
    }   
};