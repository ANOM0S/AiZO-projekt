#pragma once
#include "ISorter.h"
#include <vector>
#include <cmath>

using namespace std;

// algorytm sortowania shella korzystający z interfejsu ISorter
template <typename T>
class ShellSort : public ISorter<T> {
private:
    // Zmienna pomocnicza do wyboru odstępu
    int gapSelector;

    // Funkcja do sortowania shella
    void shellSort(vector<T>& data, int power, int n, int gapSelector){
        int gap;

        // Wybór sposobu obliczania przerwy między elementami:
        // Default -> standardowy algorytm shella z 1959 r.
        // case 1 -> zmodyfikowany algorytm shella od Franka i Lazarusa z 1960 r.
        switch (gapSelector){
            case 1:
                gap = 2*(n / static_cast<int>(pow(2, power+1))) + 1;
                break;
    
            default:
                gap = n / static_cast<int>(pow(2, power));
                break;
        }
        
        // Zwiększenie potęgi do następnej iteracji
        ++power;
        // amienna pomocnicza do odpwiedniego przechodzenia po n tym elemencie
        int iterator = gap;

        // Pętla do sortowania (w zasadzie to podobne do sortowania przez wstawianie tylko z większym odstępem)
        for (int k = 0; k<gap; k++){
            for (int i = iterator; i<data.size(); i+=gap){
                for (int j = i; j>=gap; j-=gap){
                    if(data[j]<data[j-gap]){
                        std::swap(data[j],data[j-gap]);
                    }else{
                        break;
                    }
                }
            }
            iterator++;
        }

        // Jeżeli gap jest większy od 1 to idziemy dalej aż do momentu gdy będzie 1.
        if(gap>1){
            shellSort(data, power, n, gapSelector);
        }
    }

public:
    // Konstruktor który ma wybrać rodzaj sortowania
    ShellSort(int gapSelector = 1){
        this->gapSelector = gapSelector;
    }

    // Publiczna funkcja która zaczyna sortowanie
    void sort(vector<T>& data){
        int n = data.size();

        shellSort(data, 1, n, gapSelector);
    }
};
