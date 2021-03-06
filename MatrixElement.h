//
// Created by Ryan Morales on 11/16/16.
//

#ifndef GRAPHS_MATRIXELEMENT_H
#define GRAPHS_MATRIXELEMENT_H


#include <string>

using namespace std;
struct MatrixElement {
    int row = 0;                                    //row index
    int col = 0;                                    //col index
    double value = 0;                               //value at row and col index
};

//help functions
int max(int a, int b);

bool goodInput(string line);

bool greaterThan(MatrixElement a, MatrixElement b, int *counter);

bool lessThanEqual(MatrixElement leftArray, MatrixElement rightArray, int *counter);


#endif //GRAPHS_MATRIXELEMENT_H
