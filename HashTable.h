//
// Created by Ryan Morales on 12/4/16.
//

#ifndef GRAPHS_HASHTABLE_H
#define GRAPHS_HASHTABLE_H

#include <string>
using namespace std;

struct Label {
    int id;
    string label;
};

class HashTable {
    Label* data;
    int sizeOfData;


public:
    HashTable(string filename, string outfile);
    HashTable(int initialSize);
    ~HashTable();
    int hash(int key);
    Label getLabel(int key);
    void setLabel(int key, Label lable);
};


#endif //GRAPHS_HASHTABLE_H
