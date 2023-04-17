#ifndef __AVL Tree_H__
#define __AVL Tree_H__

#include <iostream>
#include "Node.h"



class AVLTree
{
private:
	AVLNode *root;
	void inseertHelper(AVLNode **, int);
	string preOrderHelper(AVLNode *) const;
	string inOrderHelper(AVLNode *) const;
	string postOrderHelper(AVLNode *) const;
	void deleteNode(AVLNode *, int);

	// checkover
	AVLNode *rotateRight(AVLNode *);
	AVLNode *rotateLeft(AVLNode *);
	AVLNode *rotateDoubleRight(AVLNode *);
	AVLNode *rotateDoubleLeft(AVLNode *);
	AVLNode *rotateLeftRight(AVLNode *);
	AVLNode *rotateRightLeft(AVLNode *);
	int calcHeight(AVLNode *);
	int calcBalance(AVLNode *);

public:
	AVLTree() { root = 0; }
	void insert(int);
	string preOrder() const;
	string postOrder() const;
	string remove(int);
	void removeMin();
};

// checkover
AVLTree::rotateRight(AVLNode *)
{
	
}
AVLTree::rotateLeft(AVLNode *)
{
	
}
AVLTree::rotateDoubleRight(AVLNode *)
{
	
}
AVLTree::rotateDoubleLeft(AVLNode *)
{
	
}
AVLTree::rotateLeftRight(AVLNode *)
{
	
}
AVLTree::rotateRightLeft(AVLNode *)
{
	
}

#endif