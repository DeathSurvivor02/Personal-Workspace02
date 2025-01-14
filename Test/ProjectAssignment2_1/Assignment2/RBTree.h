#ifndef RBTREE_H
#define RBTREE_H

#include <string>

class RBTNode
{
private:
    string data;
    string color;

public:
    RBTNode *left;
    RBTNode *right;
    RBTNode *parent;

    // Constructor functions
    RBTNode()
    {
        right = left = parent = NULL;
        color = "RED";
    }
    RBTNode(string val)
    {
        data = val;
        right = left = parent = NULL;
        color = "RED";
    }

    // Mutator functions
    void setData(string val) { data = val; }
    void setColor(string col) { color = col; }

    // Accessor functions
    string getData() { return data; }
    string getColor() { return color; }
    string printData();
};
string RBTNode::printData()
{
    char d[5];
    sprintf(d, "%d", getData());
    string print = d;
    // print.append(to_string(faith));
    print.append("\n");
    return print;
}
class RBT
{
private:
    RBTNode *root;

    void rotateLeft(RBTNode *);
    void rotateRight(RBTNode *);
    void fixUp(RBTNode *);
    string inOrderHelper(RBTNode *);
    string preOrderHelper(RBTNode *);
    string postOrderHelper(RBTNode *);
    void deleteNode(RBTNode *);
    RBTNode *findNode(string);
    RBTNode *getMinimum(RBTNode *);
    RBTNode *getSuccessor(RBTNode *);

public:
    // Constructor function
    RBT() { root = NULL; }

    // Mutator functions
    void insert(string);
    void remove(string);

    // Accessor functions
    RBTNode *getRoot() { return root; }
    string inOrder();
    string preOrder();
    string postOrder();
    string showLevels();
};

void RBT::rotateLeft(RBTNode *ptr)
{
    RBTNode *rightChild = ptr->right;
    ptr->right = rightChild->left;

    if (rightChild->left != NULL)
        rightChild->left->parent = ptr;

    rightChild->parent = ptr->parent;

    if (ptr == root)
        root = rightChild;
    else
    {
        if (ptr == ptr->parent->left)
            ptr->parent->left = rightChild;
        else
            ptr->parent->right = rightChild;
    }

    rightChild->left = ptr;
    ptr->parent = rightChild;
}

void RBT::rotateRight(RBTNode *ptr)
{
    RBTNode *leftChild = ptr->left;
    ptr->left = leftChild->right;

    if (leftChild->right != NULL)
        leftChild->right->parent = ptr;

    leftChild->parent = ptr->parent;

    if (ptr == root)
        root = leftChild;
    else
    {
        if (ptr == ptr->parent->right)
            ptr->parent->right = leftChild;
        else
            ptr->parent->left = leftChild;
    }

    leftChild->right = ptr;
    ptr->parent = leftChild;
}

RBTNode *RBT::findNode(string data)
{
    RBTNode *ptr = root;

    while (ptr != NULL)
    {
        if (ptr->getData() == data)
        {
            return ptr;
        }

        if (data < ptr->getData())
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    return NULL;
}

void RBT::insert(string val)
{
    RBTNode *newnode = new RBTNode(val);

    if (root == NULL)
    {
        newnode->setColor("BLACK");
        root = newnode;
        return;
    }
    else
    {
        RBTNode *ancestor = NULL;
        RBTNode *current = root;

        while (current != NULL)
        {
            ancestor = current;

            if (newnode->getData() < current->getData())
                current = current->left;
            else
                current = current->right;
        }

        newnode->parent = ancestor;

        if (newnode->getData() < ancestor->getData())
            ancestor->left = newnode;
        else
            ancestor->right = newnode;
        fixUp(newnode);
    }
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
        else
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

void RBT::remove(string val)
{
    RBTNode *markedNode = findNode(val);
    deleteNode(markedNode);
}

void RBT::deleteNode(RBTNode *node2Zap)
{
    if (node2Zap == NULL)
        return;
    else
    {
        RBTNode *successor, *successorChild;
        successor = node2Zap;

        if (node2Zap->left == NULL || node2Zap->right == NULL)
            successor = node2Zap;
        else
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

        str.append(ptr->printData());
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
        str.append(ptr->printData());
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

        str.append(ptr->printData());
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

#endif
