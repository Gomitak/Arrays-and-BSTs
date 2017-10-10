#include "Collection.h"
using namespace std;


Collection::Collection(){
	
}

Collection::~Collection(){
	
}

Collection*Collection:: copy(){
	
}


Collection::Collection(const Collection &temp){
	
}

//int &Collection:: operator[](int n){
//}

Collection& Collection::operator=(const Collection &temp){
	
}

bool Collection::contains(int n){
	/*for(int i = 0; i<size; i++){
		if(holder[i] == n)return true;
	}
	
	return false;*/
	for(int i = 0; i<size; i++){
		if(this->operator[](i)==n){
			return true;
		}
	}
	return false;
}

Collection & Collection::map(int(*fn)(int)){
	for(int i = 0; i<size; i++){
		this->operator[](i) = fn(this->operator[](i));
	}
	return *this;
}

int Collection::getSize(){
	return size;
}
