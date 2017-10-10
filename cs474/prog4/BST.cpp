#include<iostream>
#include "Collection.h"
#include "BST.h"

BST::BST(){
	cout<<"Created Tree"<<endl;
	t = new bst;
	t->root = NULL;
	t->size = 0;
	size = 0;

	//root->children_left = 0;
	//root->children_right = 0;
}

static void remove_r(NODE *r){
    if(r==NULL) return;
    remove_r(r->left);
    remove_r(r->right);
    delete r;
}

BST::~BST(){
	remove_r(t->root);
	delete t;
}

//copy helper
NODE* BST::copyHelp(const NODE *r){
	if (r == NULL)
		return NULL;
	NODE *copyNode = new NODE;
	copyNode->value = r->value;
	copyNode->left = copyHelp(r->left);
	copyNode->right = copyHelp(r->right);
	t->size++;
	size++;
	return copyNode;
}

//copy constructor for the bst
BST::BST(const BST &rgh){
	t = new bst;
	t->root = copyHelp(rgh.t->root);
	
}

//virtual copy scheme
Collection* BST::copy(){
	return new BST(*this);
}

BST& BST::operator=(const BST&temp){
	if(this == &temp) return *this;
	
	if(holder!=NULL && isdigit(holder[0]))//check for null array and number
		delete[]holder;
	
	remove_r(t->root);
	delete t;
	
	t = new bst;
	t->root = copyHelp(temp.t->root);
}

NODE*BST:: insert(int n, NODE*r){
	NODE *leaf;
    if(r == NULL){
		leaf = new NODE;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->value = n;
		t->size++;
		size++;
		return leaf;
    }
	
    if(r->value == n)
        return r;
    if(n < r->value){
        r->left = insert(n,r->left);
		r->children_left++;
        return r;
    }
    else {
		//cout<<"enter2"<<endl;
        r->right = insert(n,r->right);
		r->children_right++;
        return r;
    }
	
}

int position;

//used for the = operator
void BST:: inOrder(NODE*r){
	if(r!=NULL){
		inOrder(r->left);
		holder[position] = r->value;
		position++;
		inOrder(r->right);
	}
}

void BST::add(int n){
	t->root = insert(n,t->root);
	if(holder!=NULL){
		holder = NULL;
		delete holder;
	}
	position = 0;
	holder = new int[t->size];
	inOrder(t->root);
	
}


//equal operator calls inOrder to traverse tree in order
//then based off the global variable position it will mark
//the found variable
int &BST::operator[](int n){
	//position = 0;
	//holder = new int[t->size];
	//inOrder(t->root);
	return holder[n];
}

//print out in order
void inOrderHelper(NODE *r){
	if(r!=NULL){
		inOrderHelper(r->left);
		cout<<r->value<<" ";
		position++;
		inOrderHelper(r->right);
	}
}

void BST::printIn(){
	inOrderHelper(t->root);
	cout<<endl;
	cout<<"size of tree "<<t->size<<endl;
}
