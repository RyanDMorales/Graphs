//
// Created by Ryan Morales on 11/10/16.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include "LinkedList.h"
#include "ArrayMatrix.h"

class Graph {
public:
    bool isEmpty(); //Checks if Graph is empty

    void createGraph(ArrayMatrix *matrix);

    void clearGraph();

    void printGraph();

    void dft(); //Depth first traversal of entire Graph

    ArrayMatrix *dftAtVertex(int vertex); //Depth first traversal at specified node

    void dftAtVertex(int vertex, bool visited[], ArrayMatrix *visitedVertices); //Depth first traversal at specified node

    ArrayMatrix *dftAtVertexIter(int vertex, string output); //Depth first search Iterative

    void dftAtVertexWithK(int vertex, int k, string output);

    void dftAtVertexWithK(int vertex, bool visited[], int k, int current, string output);

    Graph(int size);

    ~Graph();

protected:
    int maxSize; //Max number of vertices

    int gSize; //Current number of vertices

    LinkedList *graph;

};


#endif //GRAPHS_GRAPH_H
