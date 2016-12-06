//
// Created by Ryan Morales on 12/3/16.
//

#ifndef GRAPHS_STACKLINKEDLIST_H
#define GRAPHS_STACKLINKEDLIST_H


#include "LinkedList.h"

class StackLinkedList {
    Node *head = nullptr;
    int numOfItems = 0;
public:

    StackLinkedList();

    void push(int item);

    void pop();

    int top();

    //void setItem(int item, int position);

    int getItem(int position);

    //void deleteItem(int position);

    int getNumOfItems() const;

    Node *getHead();

    void setHead(Node *head);

    void destroyList();

    void printList();
};


#endif //GRAPHS_STACKLINKEDLIST_H
