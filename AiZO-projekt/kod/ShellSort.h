#pragma once
#include "ISorter.h"
#include <vector>
#include <cmath>

using namespace std;

// Shell sort algorithm using ISorter interface.
template <typename T>
class ShellSort : public ISorter<T> {
private:
    int gapSelector;

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
        
        ++power;
        int iterator = gap;

        cout << endl << gap;

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

        if(gap>1){
            shellSort(data, power, n, gapSelector);
        }
    }

public:
    ShellSort(int gapSelector = 1){
        this->gapSelector = gapSelector;
    }

    void sort(vector<T>& data){
        int n = data.size();

        shellSort(data, 1, n, gapSelector);
    }
};
