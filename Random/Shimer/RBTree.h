//
//  RBTree.h
//  RBT
//
//  Created by Dr. John Charlery on 03/22/2023.
//  Copyright (c) 2023 University of the West Indies. All rights reserved.
//

#ifndef RBTREE_H
#define RBTREE_H

#include <string>

using std::string;

class RBTNode
{
private:
    int data;
    string color;
    string label; // new field for label

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
    RBTNode(int val, string lbl)
    {
        data = val;
        right = left = parent = NULL;
        color = "RED";
        label = lbl;
    } // updated constructor

    // Mutator functions
    void setData(int val) { data = val; }
    void setColor(string col) { color = col; }
    void setLabel(string lbl) { label = lbl; } // new mutator function

    // Accessor functions
    int getData() { return data; }
    string getColor() { return color; }
    string getLabel() { return label; } // new accessor function
};

class RBT
{
private:
    RBTNode *root;

    // Utility functions
    void rotateLeft(RBTNode *);
    void rotateRight(RBTNode *);
    void fixUp(RBTNode *);
    string inOrderHelper(RBTNode *);
    string preOrderHelper(RBTNode *);
    string postOrderHelper(RBTNode *);
    void deleteNode(RBTNode *);
    RBTNode *findNode(int);
    RBTNode *getMinimum(RBTNode *);
    RBTNode *getSuccessor(RBTNode *);

public:
    // Constructor function
    RBT() { root = NULL; }

    // Mutator functions
    void insert(int, string); // updated mutator function with label
    void remove(int);

    // Accessor functions
    RBTNode *getRoot() { return root; }
    string inOrder();
    string preOrder();
    string postOrder();
    string showLevels();
    void displayRecordsWithLabel(string label); // new function to display records with a specific label
};

void RBT::insert(int val, string lbl)
{
    RBTNode *newnode = new RBTNode(val, lbl); // updated constructor with label

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

void RBT::displayRecordsWithLabel(string label)
{
    Node *curr = root;
    bool found = false;

    while (curr != nil)
    {
        if (curr->label == label)
        {
            cout << "Label: " << curr->label << endl;
            cout << "Value: " << curr->value << endl;
            found = true;
            // Traverse left subtree for more nodes with same label
            Node *temp = curr->left;
            while (temp != nil && temp->label == label)
            {
                cout << "Label: " << temp->label << endl;
                cout << "Value: " << temp->value << endl;
                temp = temp->left;
            }
            // Traverse right subtree for more nodes with same label
            temp = curr->right;
            while (temp != nil && temp->label == label)
            {
                cout << "Label: " << temp->label << endl;
                cout << "Value: " << temp->value << endl;
                temp = temp->right;
            }
            break;
        }
        else if (label < curr->label)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    if (!found)
    {
        cout << "No records found with label: " << label << endl;
    }
}

void RBT::displayRecordsWithLabelHelper(Node *node, wxString &text)
{
    if (node == nullptr)
    {
        return;
    }

    displayRecordsWithLabelHelper(node->left, text); // traverse left subtree

    // Check if the node has the desired label
    if (node->label == label)
    {
        wxString record = "ID: " + std::to_string(node->id) + " | Label: " + node->label + " | Value: " + std::to_string(node->value) + "\n";
        text += record; // add the record to the output string
    }

    displayRecordsWithLabelHelper(node->right, text); // traverse right subtree
}

void RBT::displayRecordsWithLabel(string label)
{
wxString text;
displayRecordsWithLabelHelper(root, label, text); // call the helper function to traverse the tree
wxMessageBox(text, "Records with Label " + label, wxOK | wxICON_INFORMATION, NULL); // display the output in a message box
}

// description: back to work!!!!!!
// error 
// todo
// tsc
// function