#include<iostream>
#include <cstdint>
#include <cstring>
#include "Collection.h"
#include "Array.h"

Array::Array(int n){
	holder = new int[n];

	size = n;

}

Array::~Array(){
	delete []holder;
}

Array::Array(const Array& rgh){
   holder = new int[rgh.size];
   size = rgh.size;
   for(int i = 0; i<size; i++)
	   holder[i] = rgh.holder[i];
   //memcpy(holder, rgh.holder, sizeof(int) *size);
}

Collection* Array::copy(){
	return new Array(*this);
}

void Array:: add(int n){
	cerr<<"invalid for arrays"<<endl;
}

int &Array::operator[](int n){
	
	return holder[n];
}


Array&  Array:: operator=(const Array &temp){
	if(this == &temp) return *this;
	delete[] holder; 
	holder = new int[temp.size];
	size = temp.size;
	for(int i = 0; i<size; i++)
	   holder[i] = temp.holder[i];
	//memcpy(holder, temp.holder, sizeof(int) * size);
	return *this;
	
}

void Array::populateArray(){
	for(int i = 0; i <size; i++){
		holder[i] = (i+1);
	}
}
