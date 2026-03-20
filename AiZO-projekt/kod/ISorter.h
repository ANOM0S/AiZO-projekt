#pragma once
#include<iostream>
#include<vector>

// Definition of a Interface that will be inherited in next classes.
template <typename T>
class ISorter {
public:
	virtual ~ISorter() = default;

	virtual void sort(std::vector<T>& data) = 0;
};
