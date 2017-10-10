#include<iostream>

#include "Collection.h"
#include "Array.h"
#include "BST.h"

using namespace std;

//function used for testing map
int whatever(int n){
	return n*n;
}

//Joshua KIm
int main(){
	
	//array testing
	cout<<"Array Testing"<<endl<<endl;
	Array ar1(3);//create array1 size 3
	ar1.populateArray();//populate array with anything
	
	cout<<"Array 1"<<endl;
	for(int i = 0; i<ar1.getSize();i++){
		cout<<ar1[i]<<" ";
	}
	cout<<endl;
	cout<<"size of array1: "<<ar1.getSize()<<endl;//gets the size.
	
	Array ar2(1);//create array2 size 1
	ar2.populateArray();//populate with anything
	
	ar1.add(3);//add test should print out error
	
	cout<<ar1[0]<<endl;//test for operator[]
	
	Array ar3(ar1);//copy constructor for array 3 from array 1
	
	cout<<ar3[0]<<endl;//test for operator[] and see if it is correct
	
	cout<<"Array 3"<<endl;
	for(int i = 0; i<ar1.getSize();i++){
		cout<<ar3[i]<<" ";
	}
	cout<<endl;
	cout<<"size of array3: "<<ar1.getSize()<<endl;
	
	Array ar4(2);
	ar4 = ar1;//calls assginment operator
	
	cout<<ar4[0]<<endl;
	cout<<"Array 4"<<endl;
	for(int i = 0; i<ar1.getSize();i++){
		cout<<ar4[i]<<" ";
	}
	cout<<endl;
	cout<<"size of array4: "<<ar1.getSize()<<endl;
	
	cout<<"Array 4 contains 34: "<<ar4.contains(34)<<endl;//false-0
	cout<<"Array 4 contains 2: "<<ar4.contains(2)<<endl;//true-1
	
	ar1.map(whatever);//pass in random function whatever that will square everything in array1
	cout<<"Map: ";
	for(int i = 0; i<ar1.getSize();i++){
		cout<<ar1[i]<<" ";
	}
	
	cout<<endl<<"BST Testing"<<endl<<endl;
	//BST testing
	BST bs1;

	bs1.add(3);
	bs1.add(2);
	bs1.add(4);
	bs1.add(1);
	bs1.add(5);
	bs1.printIn();//will print in order the bst
	cout<<bs1[3]<<endl;//get the 4 element when traversing in order
	
	BST bs2(bs1);//copy constructor
	bs2.printIn();
	
	BST bs3;
	bs3 = bs2;//equal operator
	bs3.printIn();
	
	//contains
	cout<<bs1.contains(1)<<endl;//true-1
	cout<<bs1.contains(34)<<endl;//false-0
	
	bs1.map(whatever);//map function to square value in bst
	cout<<"Map: ";
	for(int i = 0; i<bs1.getSize();i++)
	cout<<bs1[i]<<" ";
	
	cout<<endl;

	
	
	return 0;
}