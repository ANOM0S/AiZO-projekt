#pragma once
#include "ISorter.h"
#include <vector>
#include <stdexcept>

// Klasa Quicks sorta z wykorzystaniem interfejsu ISorter
template <typename T>
class QuickSort : public ISorter<T> {
private:
    // Wybór pivot'a
    int pivot = 0;
    // Zmienna pomocnicza do sprawdzania głębokości rekurencji
    int depth = 1;

    // Funkcja sortowania
    void sortHidden(vector<T>& data, int l, int r, int pivot, int depth){
        // sprawdzenie zabezpieczające program przed stack overflow
        if (depth > 3000) {
            throw std::runtime_error("Stack Overflow");
        }

        // sprawdzenie czy mam iść dalej.
        if(l < r){
            // Podział elementów i ich sortowanie
            int m = partition(data, l, r, pivot);
            sortHidden(data, l, m, pivot, depth + 1);
            sortHidden(data, m+1, r, pivot, depth + 1);
        }
    }

    // Funkcja pomocnicza do podziału i sortowania elementów
    int partition(vector<T>& data, int leftIndex, int rightIndex, int pivotNum){
        // Wartość elementu pivot
        T pivot;

        // Sprawdzenie rodzaju pivot'a i przypisanie jego wartości
        switch (pivotNum){
            case 1:
                // Pivot jest prawy
                pivot = data[rightIndex];
                break;

            case 2:
                // Pivot jest środkowy
                pivot = data[(leftIndex + rightIndex) / 2];
                break;
            
            case 3:
                // Pivot jest losowy
                pivot = data[leftIndex + (rand() % (rightIndex - leftIndex + 1))];
                break;
            
            default:
                // Pivot jest lewy
                pivot = data[leftIndex];
                break;
    }

    // Lewy oraz prawy indeks
    int l = leftIndex;
    int r = rightIndex;

    // Pętla do sortowania
    while(1){
        // Sprawdzanie 
        while(data[l]<pivot) ++l;
        while(data[r]>pivot) --r;

        // Zamiana elementów tak aby po "lewej" były mniejsze od pivot'a a od "prawej" większe.
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
    // Konstruktor
    QuickSort(int p = 0) {
        this->pivot = p;
    }

    // Publiczna funkcja do sortowania
    void sort(vector<T>& data){
        // Ustalenie lewego i prawego elementu
        int left = 0;
        int right = data.size() - 1;

        // Odpalenie funkcji z potrzebnymi zmiennymi
        sortHidden(data, left, right, pivot, depth);
    }
};