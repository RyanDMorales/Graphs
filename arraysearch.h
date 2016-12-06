//
// Created by Ryan Morales on 11/16/16.
//

#ifndef GRAPHS_ARRAYSEARCH_H
#define GRAPHS_ARRAYSEARCH_H
double ArrayMatrix::binarySearch(int row, int col) {
    int max = this->arrayList->getNumElements() - 1;
    int min = 0;
    while (min <= max) {
        int mid = (max + min / 2);
        MatrixElement *current = this->arrayList->getMatrixElement(mid);
        if (current->row == row && current->col == col) {
            return current->value;
        } else if (row > current->row && col > current->col) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return 0;
}

double ArrayMatrix::getValueAtCoordinate(int row, int col) {
    if (this->sorted) {
        return this->binarySearch(row, col);
    }
    for (int i = 0; i < this->arrayList->getNumElements(); i++) {
        MatrixElement *current = this->arrayList->getMatrixElement(i);
        if (current->row == row && current->col == col) {
            return current->value;
        }
    }
    return 0;
}
#endif //GRAPHS_ARRAYSEARCH_H
