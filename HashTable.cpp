//
// Created by Ryan Morales on 12/4/16.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

#include "MatrixElement.h"
#include "HashTable.h"

#define INITIAL_HASH_VALUE 10
#define HASH_MULTIPLIER 135342

HashTable::HashTable(int initialSize) {
    sizeOfData = initialSize;
    data = new Label[initialSize];
}

HashTable::HashTable(string filename, string outfile){
    sizeOfData = 10000;
    data = new Label[10000];
    fstream ifs(filename.c_str());

    if (ifs.fail()) {                                                                    //Checks to see if there is an input file
        cout << "Error File: " << filename << " " << "could not be opened!"
             << endl;          //Prints error is file does not open or exists
        return;
    } else {
        if (ifs.peek() == ifstream::traits_type::eof()) {    //Checks to see if the file is empty
            //cout << "Error: File is empty!!!" << endl;
            ofstream ofs(outfile.c_str());
            ofs.close();
            return;
        }
    }
    while (!ifs.eof()) {
        //break at end of file
        if (ifs.eof()) {
            break;
        }
        //get line
        string line;
        getline(ifs, line);

        //check if input is valid
        if (line.length() > 0 && line[0] != '#') {
            //parse string
            Label currentLabel;
            stringstream fn(line);
            fn >> currentLabel.id >> currentLabel.label;
            this->setLabel(currentLabel.id, currentLabel);
        }
    }
}

HashTable::~HashTable() {
    delete[] data;
}

int HashTable::hash(int key) {
//    int hash = INITIAL_HASH_VALUE;

//    for (int i = 0; i < key.length(); ++i) {
//        hash += HASH_MULTIPLIER * key[i];
//    }

//    return hash % sizeOfData;
    return key % sizeOfData;
}

Label HashTable::getLabel(int key) {
    return data[hash(key)];
}

void HashTable::setLabel(int key, Label label) {
    data[hash(key)] = label;
}
