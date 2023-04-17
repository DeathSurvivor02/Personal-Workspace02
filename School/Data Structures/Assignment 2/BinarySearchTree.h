#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include <iostream>


class BSTree
{
	private:
	BSTNode *root;

	// meh: utitlity functions
void inOrderHelper(BSTNode *);
void preOrderHelper(BSTNode *);
void postOrderHelper(BSTNode *);

// required
void insertHelper(BSTNOde*, string);

void deleteNode(BSTNode *);
BSTNode* findNode(string);
BSTNode* getMinimum(BSTNode *);
BSTNode* getSuccessor(BSTNode *);

// review
BSTNode* getParent(BSTNode *);

public:
// meh: Constructor function
BST(){root = NULL;}

// meh Mutator
void remove(char mon[10], int year,);
void insert();
}