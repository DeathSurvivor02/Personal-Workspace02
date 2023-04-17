#ifndef __Red_BlackTree_H__
#define __Red_BlackTree_H__

#include <iostream>
#include "RandomAccessFile.cpp"
#include "Node.h"
// #include
class RBT
{
private:
	RBTNode *root;

	// utility functions
	/* STC: subjct to change */
	void rotateLeft(RBTNode *);
	void rotateRight(RBTNode *);
	void fixUp(RBTNode *);
	string inOrderHelper(RBTNode *);
	string OrderHelper(RBTNode *);
	// string OrderHelper(RBTNode *);
	void deleteNode(RBTNode *);
	RBTNode *findNode(int);
	RBTNode *getMinimum(RBTNode *);
	RBTNode *getSuccessor(RBTNode *);

public:
	// Constructor
	RBT() { root = NULL; }

	// Functions: Mutators
	void insert(int);
	void remove(int);

	// Functions: Accessor
	RBTNode *getRoot() { return root; }
	string inOrder();
	string preOrder();
	string postOrder();
	string showLevels();
		struct Record
	{
		char month[10];
		int year;
		char Artist[50];
		char songTitle[50];
		char recordLabel[50];
		int numberOfWeeks;
	};

	typedef struct Record record;
};

// Functions: Definitions

void RBT::rotateLeft(RBTNode *ptr)
{
	RBTNode *rightChild = ptr->right;
	ptr->right = rightChild->left;

	if (rightChild->left != NULL)
	{
		rightChild->left->parent = ptr;
	}
	rightChild->parent = ptr->parent;
	if (ptr == root)
	{
		root = rightChild;
	}
	else
	{
		if (ptr == ptr->parent->left)
		{
			ptr->parent->left = rightChild;
		}
		else
		{
			ptr->parent->right = rightChild;
		}
	}
	rightChild->left = ptr;
	ptr->parent = rightChild;
}

void RBT::rotateRight(RBTNode *ptr)
{
	RBTNode *leftChild = ptr->left;
	ptr->left = leftChild->right;
	if (leftChild->right != NULL)
	{
		leftChild->right->parent = ptr;
	}
	leftChild->parent = ptr->parent;
	if (ptr == root)
	{
		root = leftChild;
	}
	else
	{
		if (ptr == ptr->parent->right)
		{
			ptr->parent->left = leftChild;
		}
		else
		{
			ptr->parent->right = leftChild;
		}
	}
	leftChild->right = ptr;
	ptr->parent = leftChild;
}

/*review: may have to change the parameters of this fuction */
RBTNode *RBT::findNode(char mon[10], int yr, char singer[50], char song[50], char label[50], int weeks)
{
	RBTNode *ptr = root;
	while (ptr != NULL)
	{
		if (ptr->getData() == ((record.month[10] == mon[10])&& (record.year == yr) && (record.Artist[50] == singer[50]) &&( record.songTitles[50] == label[50] )&&(record.numberOfWeeks == weeks)))
		{
			return ptr;
		}
		if (data < ptr->getData())
		{
			ptr = ptr->left;
		}
		else
		{
			ptr = ptr->right;
		}
	}
	return NULL;
}

void RBT::insert(int val)
{
	RBTNode *newnode = new RBTNode(val);
	if (root == NULL)
	{
		newnode->getData() < current-> getData())
		current = current->left;
		else
		{
			current = current->right;
		}
	}
	newnode->parent = ancestor;
	if (newnode->getData() < ancestor->getData())
	{
		ancestor->right = newnode;
	}
	else
	{
		ancestor->right = newnode;
	}
	fixUp(newnode);
}

void RBT::fixUp(RBTNode *ptr)
{
	RBTNode *ptrsUncle = NULL;

	while (ptr != root && ptr->parent->getColor() == "RED")
	{
		if (ptr->parent == ptr->parent->parent->left)
		{ // ptr's parent is a LEFT child
			ptrsUncle = ptr->parent->parent->right;

			if (ptrsUncle != NULL && ptrsUncle->getColor() == "RED")
			{
				ptr->parent->setColor("BLACK");
				ptrsUncle->setColor("BLACK");
				ptr->parent->parent->setColor("RED");
				ptr = ptr->parent->parent;
			}
			else
			{
				if (ptr == ptr->parent->right)
				{
					ptr = ptr->parent;
					rotateLeft(ptr);
				}

				ptr->parent->setColor("BLACK");
				ptr->parent->parent->setColor("RED");
				rotateRight(ptr->parent->parent);
			}
		}
		else // ptr's parent is a RIGHT child
		{
			ptrsUncle = ptr->parent->parent->left;

			if (ptrsUncle != NULL && ptrsUncle->getColor() == "RED")
			{
				ptr->parent->setColor("BLACK");
				ptrsUncle->setColor("BLACK");
				ptr->parent->parent->setColor("RED");
				ptr = ptr->parent->parent;
			}
			else
			{
				if (ptr == ptr->parent->left)
				{
					ptr = ptr->parent;
					rotateRight(ptr);
				}
				ptr->parent->setColor("BLACK");
				ptr->parent->parent->setColor("RED");
				rotateLeft(ptr->parent->parent);
			}
		}
	}

	root->setColor("BLACK");

	ptrsUncle = NULL;
}

void RBT::remove(int val)
{
	RBTNode *markedNode = findNode(val);
	deleteNode(markedNode);
}

void RBT::deleteNode(RBTNode *node2Zap)
{
	if (node2Zap == NULL) // If node being deleted is NULL then do nothing.
		return;
	else
	{
		RBTNode *successor, *successorChild;
		successor = node2Zap;

		if (node2Zap->left == NULL || node2Zap->right == NULL)
			// If either of the children is NULL
			successor = node2Zap;
		else // node2Zap has 2 children
			successor = getSuccessor(node2Zap);

		if (successor->left == NULL)
			successorChild = successor->right;
		else
			successorChild = successor->right;

		if (successorChild != NULL)
			successorChild->parent = successor->parent;

		if (successor->parent == NULL)
			root = successorChild;
		else if (successor == successor->parent->left)
			successor->parent->left = successorChild;
		else
			successor->parent->right = successorChild;

		if (successor != node2Zap)
			node2Zap->setData(successor->getData());

		// Finally... If color is black call fixup otherwise no fixup required
		if (successor->getColor() == "BLACK" && successorChild != NULL)
			fixUp(successorChild);
	}
}

RBTNode *RBT::getSuccessor(RBTNode *ptr)
{
	if (ptr->right == NULL)
		return ptr->left;
	else
		return (getMinimum(ptr->right));
}

RBTNode *RBT::getMinimum(RBTNode *ptr)
{
	while (ptr->left != NULL)
		ptr = ptr->left;

	return ptr;
}

string RBT::inOrderHelper(RBTNode *ptr)
{
	string str = "";

	if (ptr != NULL)
	{
		str.append(inOrderHelper(ptr->left));

		str.append(to_string(ptr->getData()));
		str.append("  ");

		str.append(inOrderHelper(ptr->right));
	}
	return str;
}

string RBT::preOrderHelper(RBTNode *ptr)
{
	string str = "";

	if (ptr != NULL)
	{
		str.append(to_string(ptr->getData()));
		str.append("  ");

		str.append(preOrderHelper(ptr->left));
		str.append(preOrderHelper(ptr->right));
	}
	return str;
}

string RBT::postOrderHelper(RBTNode *ptr)
{
	string str = "";

	if (ptr != NULL)
	{
		str.append(postOrderHelper(ptr->left));
		str.append(postOrderHelper(ptr->right));

		str.append(to_string(ptr->getData()));
		str.append("  ");
	}
	return str;
}

string RBT::inOrder()
{
	return inOrderHelper(root);
}

string RBT::preOrder()
{
	return preOrderHelper(root);
}

string RBT::postOrder()
{
	return postOrderHelper(root);
}
string RBT::OrderHelper()
#endif