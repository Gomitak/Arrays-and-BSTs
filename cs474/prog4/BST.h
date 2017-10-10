#pragma once
#include<iostream>
#include "Collection.h"

struct bst_node {
    int value;
	int children_left;
	int children_right;
	int all_children;
    struct bst_node *left;
    struct bst_node *right;
};
typedef struct bst_node NODE;


struct bst {
    NODE *root;
	int size;
	int smallest;
	int biggest;
};
typedef struct bst *BST_PTR;
	
class BST: public Collection{
	
	public: 
	BST();
	~BST();
	
	NODE * copyHelp(const NODE *r);
	BST(const BST &rgh);//virtual copy constructor
	
	void add(int n);//add node to bst
	void inOrder(NODE *r);//helper for printing in order
	void printIn();//print pre order
	NODE* insert(int n, NODE*r);//used for inserting into BST
	int& operator[](int n);//find index based off in order traversal
	BST& operator=(const BST &temp);//deep copy Array
	Collection*copy();//virtual copy scheme
	
	protected:
	BST_PTR t;
	


	

};