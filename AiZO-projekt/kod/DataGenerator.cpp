#include<vector>
#include<cstdlib>
#include<algorithm>
#include<ctime>

#include "DataGenerator.h"

using namespace std;

// +++++++++++++++++++++++++++++++++++++++++ INT GENERATOR ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
vector<int> DataGenerator::intGenerator(int amount, int type){
    vector<int> intTable;
    intTable.reserve(amount);
    srand(static_cast<unsigned int>(time(nullptr)) ^ reinterpret_cast<uintptr_t>(this));

    // Wybór petli w zależności od wybranego trybu:
    // 1 -> normalne (losowe)
    // 2 -> posortowane (do testów)
    // 3 -> Odwrotnie posortowane (do testów)
    // 4 -> 33% początkowych posortowana (do testów)
    // 5 -> 66% początkowych posortowana (do testów)
    switch(type) {
        case 0:
            for (int i = 0; i<amount; i++){
                intTable.push_back(rand() % 101);
            }
            return intTable;
        case 1:
            for (int i = 0; i<amount; i++){
                intTable.push_back(rand() % 10001);
            }
            return intTable;

        case 2:
            for (int i = 0; i<amount; i++){
                intTable.push_back(i*2 + (rand() % 3 - 2));
            }
            return intTable;

        case 3:
            for (int i = 0; i<amount; i++){
                intTable.push_back(i*3 + (rand() % 5 - 2));
            }
            reverse(intTable.begin(), intTable.end());
            return intTable;

        case 4:
            for (int i = 0; i<static_cast<int>(amount*0.33); i++){
                intTable.push_back(i*3 + (rand() % 5 - 2));
            }
            for (int i = static_cast<int>(amount*0.33); i<amount; i++){
                intTable.push_back(rand());
            }
            return intTable;
   
        case 5: 
            for (int i = 0; i<static_cast<int>(amount*0.66); i++){
                intTable.push_back(i*3 + (rand() % 5 - 2));
            }
            for (int i = static_cast<int>(amount*0.66); i<amount; i++){
                intTable.push_back(rand());
            }
            return intTable;

        default:
            return intTable;
    } 
}


// +++++++++++++++++++++++++++++++++++++++++ FLOAT GENERATOR ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
vector<double> DataGenerator::floatGenerator(int amount, int type){
    vector<double> floatTable;
    floatTable.reserve(amount);
    srand(static_cast<unsigned int>(time(nullptr)) ^ reinterpret_cast<uintptr_t>(this));

    // Wybór petli w zależności od wybranego trybu:
    // 1 -> normalne (losowe)
    // 2 -> posortowane (do testów)
    // 3 -> Odwrotnie posortowane (do testów)
    // 4 -> 33% początkowych posortowana (do testów)
    // 5 -> 66% początkowych posortowana (do testów)

    switch(type) {
        case 0:
            for (int i = 0; i<amount; i++){
                floatTable.push_back(static_cast<double>(rand()) / RAND_MAX * 100.0);
            }
            return floatTable;
        case 1:
            for (int i = 0; i<amount; i++){
                floatTable.push_back(static_cast<double>(rand()) / RAND_MAX * 1000.0);
            }
            return floatTable;

        case 2:
            for (int i = 0; i<amount; i++){
                floatTable.push_back(i * 2.0 + (static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0));
            }
            return floatTable;

        case 3:
            for (int i = 0; i<amount; i++){
                floatTable.push_back(i * 2.0 + (static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0));
            }
            reverse(floatTable.begin(), floatTable.end());
            return floatTable;

        case 4:
            for (int i = 0; i<static_cast<int>(amount*0.33); i++){
                floatTable.push_back(i * 2.0 + (static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0));
            }
            for (int i = static_cast<int>(amount*0.33); i<amount; i++){
                floatTable.push_back(static_cast<double>(rand()) / RAND_MAX * 100.0);
            }
            return floatTable;
   
        case 5: 
            for (int i = 0; i<static_cast<int>(amount*0.66); i++){
                floatTable.push_back(i * 2.0 + (static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0));
            }
            for (int i = static_cast<int>(amount*0.66); i<amount; i++){
                floatTable.push_back(static_cast<double>(rand()) / RAND_MAX * 100.0);
            }
            return floatTable;

        default:
            return floatTable;
    } 
}