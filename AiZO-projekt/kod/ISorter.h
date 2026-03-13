#include<iostream>
#include<vector>

class ISorter {
public:
    // Wirtualny destruktor
	virtual ~ISorter() = default;

    // Metoda do implementacji
	virtual void sort(std::vector<int>& data) = 0;

	virtual void sort(std::vector<double>& data) = 0;
};