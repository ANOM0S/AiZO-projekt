#pragma once
#include<iostream>
#include<vector>

// Definicja interfejsu z którego będą korzystały wszystkie sortery
template <typename T>
class ISorter {
public:
	virtual ~ISorter() = default;

	virtual void sort(std::vector<T>& data) = 0;
};
