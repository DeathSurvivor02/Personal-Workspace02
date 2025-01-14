#ifndef NODE_H
#define NODE_H

// default Node
class Node

{
public:
	struct recordBst
	{
		char month[10];
		int year;
		char artist[50];
		char song[50];
		char label[15];
		int weeksAtNumberOne;
	};
	typedef struct recordBst recBst;
	// checkover maybe not

	Node *next;

	Node(char recBst.month[10], int year, char artist[50], char song[50], char label[15], int weeksAtNumberOne)
	{
		this->month[10] = month[10];
		this->year = year;
		this->artist[50] = artist[50];
		this->song[50] = song[50];
		this->label[15] = label[15];
		this->weeksAtNumberOne = weeksAtNumberOne;
	}


	// Red-Black Tree

	class RBTNode
	{
	private:
		int data;
		string colour;

	public:
		RBTNode *left;
		RBTNode *right;
		RBTNode *parent;

		// constructor function
		RBTNode()
		{
			right = left = parent = NULL;
			colour = "RED";
		}

		// override constructor
		RBTNode(int val)
		{
			data = val;
			right = left = NULL;
			colour = "RED";
		}

		// Functions: Mutator
		void setData(int val) { data = val; }
		void setColour(string val) { colour = val; }

		// Functions: Accessor
		int getData() { return data; }
		string getColour() { return colour; }
	};

	class BSTNode

	{
	private:
		string data;

	public:
		BSTNode *left;
		BSTNode *right;

		BSTNode(string val)
		{
			data = val;
			left = right = 0;
		}
		string getData() { return data; }
		void setData(string val) { data = val; }
	};

	class AVLNode
	{
	private:
		int data;
		int height;

	public:
		AVLNode *left
			AVLNode *right;
		AVLNode()
		{
			right = left = NULL;
			height = 0;
		}
		AVLNode(int val)
		{
			data = val;
			height = 0;
			right = left = 0;
		}
		void setData(int val) { data = val; }
		void setHeight(int val) { height = val; }
		int getData() { return data; }
		int getHeight() { return height; }
	};
#endif // NODE_H
