#include <iostream>
#include "ISorter.h"
#include "HeapSort.h"

using namespace std;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++ INT VALUES +++++++++++++++++++++++++++++++++++++++++++++++++++
// Sorting function that starts heapify
void HeapSort::sort(vector<int>& data){
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

// Helping function that creates a heap
void HeapSort::heapify(vector<int>& table, int n, int i) {
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

// +++++++++++++++++++++++++++++++++++++++++++++++++++ FLOAT VALUES +++++++++++++++++++++++++++++++++++++++++++++++++++
// Same but for the float values
void HeapSort::sort(vector<double>& data){
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

// Funkcja pomocnicza do tworzenia kopca.
void HeapSort::heapify(vector<double>& table, int n, int i) {
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

        heapify(table, n, largest);
    }
}