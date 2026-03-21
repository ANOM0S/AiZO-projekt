#pragma once

#include "ISorter.h"
#include "DataGenerator.h"

#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <type_traits> 

using namespace std;

// Klasa testera potrzebna do sprawdzenia czasów sortowania
template <typename T>
class Tester {
public:
    // Funkcja benchmark która sprawdza czasy i uśrednia (my przyjmujemy 100 pomiarów)
    vector<string> benchmark(ISorter<T>& algorytm, vector<int>& amounts, int generationType){
        // Instancja generatora
        DataGenerator generator;

        // Tablice do zwracania wyników
        vector<T> table;
        vector<string> results;


        for (int i = 0; i < amounts.size(); i++){
            long long result = 0; 
            bool testFailed = false; // Flaga, czy się zepsuło
            
            // Przejście 100 razy aby wyniki były bardziej wiarygodne
            for (int j = 0; j < 100; j++){
                // Sprawdzenie jakiego typu dane używamy i dostosowanie generatora
                if constexpr (is_same_v<T, int>) {
                    table = generator.intGenerator(amounts[i], generationType);
                } 
                else if constexpr (is_same_v<T, float>) {
                    table = generator.floatGenerator(amounts[i], generationType);
                }

                // Zarządzanie wyjątkiem
                try {
                    // Dodawanie czasu do wyniku
                    result += uruchomTest(algorytm, table);
                } 
                catch (const std::runtime_error& e) {
                    // Wyświetlenie stosownej informacji w razie jakiegoś błędu
                    cout << "   [!] Przerwano test dla rozmiaru " << amounts[i] 
                         << " - Powod: " << e.what() << endl;
                    
                    // Wstawienie błędu do wyniku
                    results.push_back("BLAD");
                    
                    // Ustawienie flagi błędu
                    testFailed = true;
                    break; 
                }
            }

            // Jeśli test przeszedł bez wybuchu, dopisujemy średni czas
            if (!testFailed) {
                results.push_back(to_string(result / 100) + " ms"); 
            }
        }

        // Zwrócenie wyniku
        return results;
    }

    // Funkcja uruchomienia pojedynczego testu
    long long uruchomTest(ISorter<T>& algorytm, vector<T>& dane) {
        // 1. Start timer'a
        auto start = std::chrono::high_resolution_clock::now();

        // 2. Sortowanie danych.
        algorytm.sort(dane);

        // 3. Zatrzymanie timer'a
        auto stop = std::chrono::high_resolution_clock::now();

        // Zabezpieczenie poprawności sortowania
        for (int i = 0; i < dane.size() - 1; i++){
            // Przejście po każdym elemencie i sprawdzenie czy jest mniejszy lub równy od poprzedniego
            if(dane[i] > dane[i+1]){
                cout << "Blad w sortowaniu tablicy!!! Index: " << i << endl;
                exit(0);
            }
        }

        // 4. Obliczenie wyniku w milisekundach
        long long czasTrwania = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

        // 5. Zwrócenie czasu.
        return czasTrwania;
    }
};