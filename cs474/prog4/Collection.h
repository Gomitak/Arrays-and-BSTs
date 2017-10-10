#pragma once
#include <iostream>
#include <string>

using namespace std;

class Collection{
	public: 
	Collection();//constructor
	virtual ~Collection()=0;//deconstructor
	
	Collection(const Collection &rgh);//copy constructor
	
	virtual void add(int n)=0;//add
	virtual int &operator[](int n)=0;//return value
	bool contains(int n);//inherited
	Collection& operator=(const Collection &temp);//deep copy
	virtual Collection *copy();//virtual copy scheme
	Collection& map(int (*fn)(int));//inherited
	
	int getSize();
	
	protected:
	int size;//returns # elements in receiver
	int *holder;
	
	
};