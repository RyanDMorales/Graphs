//
// Created by Ryan Morales on 11/11/16.
//

#ifndef GRAPHS_LINKEDLIST_H
#define GRAPHS_LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList {
    Node *head = nullptr;
    Node *tail = nullptr;
    int numOfItems = 0;
public:

    LinkedList();

    void addItem(int item);

    void setItem(int item, int position);

    int getItem(int position);

    //void deleteItem(int position);

    int getNumOfItems() const;

    Node *getHead();

    void setHead(Node *head);

    Node *getTail();

    void setTail(Node *tail);

    void destroyList();

    void printList();
};


#endif //GRAPHS_LINKEDLIST_H
