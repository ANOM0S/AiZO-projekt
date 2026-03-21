#pragma once
#include "ISorter.h"
#include <vector>

// Definicja klasy sortowania hybrydowego z interfejsu ISorter
template <typename T>
class HybridSort : public ISorter<T> {
    private:
    // Pivot - standardowo środkowy
    int pivot = 2;
    // Zmienna sprawdzająca głębokość rekurencji
    int depth = 1;
    // Wielkość do której sortowanie się nie przerwie
    int threshold;

    // Funkcja pomocnicza do sortowania przez wstawianie
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

    // Sortowanie hybrydowe
    void sortHidden(vector<T>& data, int l, int r, int pivot, int depth){
        // sprawdzenie zabezpieczające program przed stack overflow
        if (depth > 3000) {
            throw std::runtime_error("Stack Overflow");
        }

        // sprawdzenie czy mam iść dalej.
        if(l<r){
            // Podział elementów i ich sortowanie
            int m = partition(data, l, r, pivot);

            // Sprawdzenie czy wielkość pod tablic jest większa od threshold
            if(m-l>threshold){
                // Jeżeli tak to wchodzimy dalej rekurencją
                sortHidden(data, l, m, pivot, depth + 1);
            } else {
                // Jeżeli nie to sortujemy insertionSortem
                insertionSort(data, l, m);
            }

            // Sprawdzenie czy wielkość pod tablic jest większa od threshold
            if(r-(m+1)>threshold){
                // Jeżeli tak to wchodzimy dalej rekurencją
                sortHidden(data, m+1, r, pivot, depth + 1);
            } else {
                // Jeżeli nie to sortujemy insertionSortem
                insertionSort(data, m+1, r);
            }
        }
    }

    // Funkcja pomocnicza do sortowania i podziału.
    int partition(vector<T>& data, int leftIndex, int rightIndex, int pivotNum){
        // Zmienna z wartością pivot'a
        T pivot;

        // Wybór który pivot mamy wybrać
        switch (pivotNum){
            case 1:
                // Pivot z prawej
                pivot = data[rightIndex];
                break;

            case 2:
                // Pivot z środka
                pivot = data[(leftIndex + rightIndex) / 2];
                break;
            
            case 3:
                // Pivot losowy
                pivot = rand() % data.size();
                break;
            
            default:
                // Pivot lewy
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
    HybridSort(int threshold = 5, int p = 2) {
        this->pivot = p;
        this->threshold = threshold;
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