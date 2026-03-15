#pragma once
#include<iostream>
#include<vector>

// Definition of a Interface that will be inherited in next classes.
class ISorter {
public:
	virtual ~ISorter() = default;

	virtual void sort(std::vector<int>& data) = 0;
	virtual void sort(std::vector<double>& data) = 0;
};
