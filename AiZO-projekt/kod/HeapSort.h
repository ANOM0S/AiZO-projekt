#pragma once

#include <iostream>
#include <vector>
#include <utility>

#include "ISorter.h"

using namespace std;

// klasa heapsort korzystająca z interfejsu isorter
// Używamy template aby nie trzeba było robić wersji dla int i float
template <typename T>
class HeapSort : public ISorter<T> {
private: 
    // Klasa tworzenia kopca
    void heapify(vector<T>& table, int n, int i) {
        // Zmienna dla największej liczby
        int largest = i;
        
        // indeksy dzieci
        int left = 2 * i + 1;  
        int right = 2 * i + 2; 

        // 1. Porównanie lewego dziecka
        if (left < n && table[left] > table[largest]) {
            largest = left;
        }

        // 2. Porównanie prawego dziecka
        if (right < n && table[right] > table[largest]) {
            largest = right;
        }

        // 3. Sprawdzenie czy trzeba coś zmieniać
        if (largest != i) {
            swap(table[i], table[largest]);
            
            // Wchodzenie głębiej przez rekurencję.
            heapify(table, n, largest);
        }
    }

public:
    // Publiczna klasa sortująca
    void sort(vector<T>& data){
        int n = data.size();

        // Budowa kopca
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(data, n, i);

        // Ekstrakcja korzenia i zamiana go z ostatnim elementem i zmniejszanie wielkości kopca
        for (int i = n - 1; i > 0; i--) {
            swap(data[0], data[i]);

            // użycie funkcji z mniejszym rozmiarem
            heapify(data, i, 0);
        }
    }   
};