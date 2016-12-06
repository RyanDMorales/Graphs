//
// Created by Ryan Morales on 11/11/16.
//

#include "LinkedList.h"
#include <iomanip>

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    numOfItems = 0;
}

Node *LinkedList::getHead() {
    return head;
}

void LinkedList::setHead(Node *head) {
    this->head = head;
}

Node *LinkedList::getTail() {
    return tail;
}

void LinkedList::setTail(Node *tail){
    this->tail = tail;
}

void LinkedList::addItem(int item) {
    Node *newNode = new Node;
    newNode->data = item;
    if(getHead() == NULL){
        setHead(newNode);
        setTail(newNode);
    } else{
        getTail()->next = newNode;
        setTail(newNode);
    }
    numOfItems++;
}

void LinkedList::destroyList() {
    Node *currentNode = head;
    Node *tempNode = nullptr;
    while (currentNode != nullptr) {
        tempNode = currentNode;
        currentNode = currentNode->next;
        delete[] tempNode;
    }
}

int LinkedList::getNumOfItems() const {
    return numOfItems;
}

int LinkedList::getItem(int position){
    if(position >= numOfItems){
        return -1;
    }
    Node *temp = getHead();
    for (int i = 0; i < position; ++i) {
        temp = temp->next;
    }
    return temp->data;
}

void LinkedList::printList(){
    Node *current = getHead();
    for(int i = 0; i < numOfItems; i++){
        if(i % 10 == 0){
            cout<<endl;
        }
        cout<<setw(4)<<current->data<<" ";
        current = current ->next;
    }
}
