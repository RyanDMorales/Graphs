//
// Created by Ryan Morales on 11/16/16.
//

#ifndef GRAPHS_ARRAYSORT_H
#define GRAPHS_ARRAYSORT_H

#include <math.h>

//Insertion Sort
void ArrayMatrix::sortMatrix() {
    counter = 0;
    // simple insertion sort in ascending order
    int i, j;
    for (i = 1; i < this->arrayList->getNumElements(); i++) {
        MatrixElement currentElement = *this->arrayList->getMatrixElement(i);
        for (j = i - 1; j >= 0 && greaterThan(*this->arrayList->getMatrixElement(j), currentElement, &counter); j--) {

            this->arrayList->setMatrixElement(j + 1, this->arrayList->getMatrixElement(j));
        }
        this->arrayList->setMatrixElement(j + 1, &currentElement);
    }
}


void ArrayMatrix::nlogn() {

    this->mergeSort(0, this->arrayList->getNumElements() - 1);

}
//Merge Sort
void ArrayMatrix::merge(int l, int m, int r) {

    int i, j, k = 0;
    int n1 = m - l + 1;
    int n2 = r - m;

    //create temp arrays
    Array *leftArray = new Array;
    Array *rightArray = new Array;

    //Copy data to temp arrays LeftArray and RightArray
    for (i = 0; i < n1; i++) {
        MatrixElement tempElement = *this->arrayList->getMatrixElement(l + i);
        leftArray->addMatrixElement(&tempElement);
    }
    for (j = 0; j < n2; j++) {
        MatrixElement tempElement = *this->arrayList->getMatrixElement(m + 1 + j);
        rightArray->addMatrixElement(&tempElement);
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (lessThanEqual(*leftArray->getMatrixElement(i), *rightArray->getMatrixElement(j), &counter)) {
            this->arrayList->setMatrixElement(k, leftArray->getMatrixElement(i));
            i++;
        } else {
            this->arrayList->setMatrixElement(k, rightArray->getMatrixElement(j));
            j++;
        }
        k++;
    }
    while (i < n1) {
        this->arrayList->setMatrixElement(k, leftArray->getMatrixElement(i));
        i++;
        k++;
    }
    while (j < n2) {
        this->arrayList->setMatrixElement(k, rightArray->getMatrixElement(j));
        j++;
        k++;
    }
    delete leftArray;
    delete rightArray;
}

//
///* l is for left index and r is right index of the
//   sub-array of arr to be sorted */
void ArrayMatrix::mergeSort(int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
        // Sort first and second halves
        this->mergeSort(l, m);
        this->mergeSort(m + 1, r);
        this->merge(l, m, r);
    }

}

#endif //GRAPHS_ARRAYSORT_H
