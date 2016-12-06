//
// Created by Ryan Morales on 12/3/16.
//

#include <iomanip>
#include "StackLinkedList.h"

StackLinkedList::StackLinkedList(){
    head = nullptr;
    numOfItems = 0;
}

Node *StackLinkedList::getHead() {
    return head;
}

void StackLinkedList::setHead(Node *head) {
    this->head = head;
}

void StackLinkedList::push(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    if(getHead() == NULL){
        setHead(newNode);
    } else{
        newNode->next = getHead();
        setHead(newNode);
        //cout<<"item pushed"<<endl;
    }
    numOfItems++;
}

void StackLinkedList::pop(){          //deletes the item at the position
    Node *temp = new Node;                        //Temp node to traverse the list
    temp = getHead();                              //Temp node to traverse the list
    setHead(getHead()->next);
    temp->next = NULL;
    //cout<<temp->data<<endl; //Outputs the popped value

    delete temp;                             //We then delete the node at the position
    numOfItems--;                                   //Decrement the number of items
}

int StackLinkedList::top(){
    return getHead()->data;
}

void StackLinkedList::destroyList() {
    Node *currentNode = head;
    Node *tempNode = nullptr;
    while (currentNode != nullptr) {
        tempNode = currentNode;
        currentNode = currentNode->next;
        delete[] tempNode;
    }
}

int StackLinkedList::getNumOfItems() const {
    return numOfItems;
}

int StackLinkedList::getItem(int position){
    if(position >= numOfItems){
        return -1;
    }
    Node *temp = getHead();
    for (int i = 0; i < position; ++i) {
        temp = temp->next;
    }
    return temp->data;
}

void StackLinkedList::printList(){
    Node *current = getHead();
    for(int i = 0; i < numOfItems; i++){
        if(i % 10 == 0){
            cout<<endl;
        }
        cout<<setw(4)<<current->data<<" ";
        current = current ->next;
    }
}