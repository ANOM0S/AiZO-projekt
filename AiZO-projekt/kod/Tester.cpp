void uruchomTest(ISorter& algorytm, std::vector<int>& dane) {
    std::cout << "--- Start testu ---\n";
    
    // Uruchamiamy stoper...
    
    algorytm.sort(dane); // Wywołujemy metodę z interfejsu
    
    // Zatrzymujemy stoper...
    
    std::cout << "--- Koniec testu ---\n";
    
}
