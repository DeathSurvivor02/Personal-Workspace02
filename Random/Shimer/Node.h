#ifndef NODE_H
#define NODE_H

#include <cstring>
#include <fstream>
#include <iostream>

struct Node {
    char Month[10];
    int Year;
    char Artist[50];
    char Title[50];
    char Label[15];
    int Week;

    Node* next;

    
};
class node{


Node() {
        next = nullptr;
        memset(Month, 0, sizeof(Month));
        memset(Artist, 0, sizeof(Artist));
        memset(Title, 0, sizeof(Title));
        memset(Label, 0, sizeof(Label));
    }
    

Node* readfile(){
    ifsteam infile("Catalog.dat", ios::binary);

    //Cheak if the file is open
    if (!infile.is_open())
    {
        cout<< "Error opening file."<<endl;
        return nullptr;
    }

    //Read the data from the file
    Node* head=nullptr;
    string line;
    while(getline(input_file,line)){
        Node* new_node=new Node;

        char* cstr = new char[line.length()+1];
        strcpy(cstr,line.c_str());

        char* token = strtok(cstr, "*");
        strcpy(new_node->Month, token);

        token = strtok(NULL,"*");
        new_node->Year=atoi(token);

        token = strtok(NULL,"*");
        strcpy(new_node->Artist, token);

        token = strtok(NULL,"*");
        strcpy(new_node->Title, token);

        token = strtok(NULL,"*");
        strcpy(new_node->Label, token);

        token = strtok(NULL,"*");
        new_node->Week=atoi(token);

        new_node->next = head;
        head=new_node;

        delete[] cstr;
    }

    //Close the file 
    infile.close();

    return head;
    
}
}
#endif
