#pragma once
#include "ISorter.h" // Musimy zaincludować interfejs, bo po nim dziedziczymy
#include <vector>    // Musimy zaincludować vector, bo używamy go w parametrze funkcji

class HeapSort : public ISorter {
public:
    // Tu tylko OBIECUJESZ, że napiszesz tę funkcję. Dajesz średnik na końcu!
    void sort(std::vector<int>& data) override; 
};