#pragma once
#include<iostream>
#include "Collection.h"

class Array: public Collection{
	public: 
	Array(int n);
	~Array();
	Array(const Array &rgh);//virtual copy constructor
	void add(int n);
	int& operator[](int n);
	Array& operator=(const Array &temp);//deep copy Array
	Collection*copy();
	void populateArray();
	
};