#include<chrono>

#include "Tester.h"
// #include "HeapSort.h"
#include "InsertionSort.h"
// #include "QuickSort.h"
// #include "ShellSort.h"

int Tester::uruchomTest(ISorter& algorytm, std::vector<int>& dane) {
    // 1. Odpalamy stoper (zapisujemy aktualny czas)
    auto start = std::chrono::high_resolution_clock::now();
    
    // 2. Sortujemy dane
    algorytm.sort(dane);
    
    // 3. Zatrzymujemy stoper (zapisujemy czas po zakończeniu)
    auto stop = std::chrono::high_resolution_clock::now();

    // 4. Obliczamy różnicę (np. w milisekundach)
    int czasTrwania = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

    // Wypisujemy wynik na ekran
    return czasTrwania;
}
