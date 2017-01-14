//
// Created by Ryan Morales on 11/10/16.
//

#include <iostream>
#include <fstream>
using namespace std;
#include "Graph.h"
#include "StackLinkedList.h"


//Checks if Graph is empty
bool Graph::isEmpty(){
    return (gSize == 0);
}

void Graph::createGraph(ArrayMatrix *matrix){

    for(int i = 0; i < matrix->arrayList->getNumElements(); i++){
        MatrixElement *current = matrix->arrayList->getMatrixElement(i);
        if(current->value == 1){
//            graph[current->col].addItem(current->row);
            graph[current->row].addItem(current->col);
        }

    }
    gSize = matrix->getNumOfVectCols() + 1;



}
//this is a test

void Graph::clearGraph(){
    for(int index = 1; index < gSize; index++){
        graph[index].destroyList();
    }
    gSize = 0; //Number of vertices
}

void Graph::printGraph(){
    for (int index = 1; index < gSize; index++){
        cout<< index <<" ";
        graph[index].printList();
        cout<<endl;
    }
    cout<<endl;
}

//Depth first traversal of entire Graph
//void Graph::dft(){
//
//    bool *visited = new bool[gSize];
//    for (int index = 1; index < gSize; index++){
//        dftAtVertex(index, visited, );
//    }
//    delete[] visited;
//}

//Depth first traversal at specified node
ArrayMatrix *Graph::dftAtVertex(int vertex){
    ArrayMatrix *visitedVertices = new ArrayMatrix;
    bool *visited = new bool[gSize];
    for (int j = 0; j < gSize; ++j) {
        visited[j] = false;
    }
    dftAtVertex(vertex, visited, visitedVertices);
    visitedVertices->nlogn();
    delete[] visited;
    return visitedVertices;
}

void Graph::dftAtVertex(int vertex, bool visited[], ArrayMatrix *visitedVertices){
    if(visited[vertex]){
        return;
    }
    visitedVertices->setValueAtCoordinate(1, vertex, 1);

    //cout<<vertex<<endl;
    visited[vertex] = true;
    for(int i = 0; i < graph[vertex].getNumOfItems(); i++){
        dftAtVertex(graph[vertex].getItem(i), visited, visitedVertices);
    }

}

ArrayMatrix *Graph::dftAtVertexIter(int vertex, string output){
    ofstream ofs(output.c_str());
    bool *visited = new bool[gSize];
    for (int j = 0; j < gSize; ++j) {
        visited[j] = false;
    }
    StackLinkedList *stack = new StackLinkedList;
    ArrayMatrix* visitedVertices = new ArrayMatrix;
    stack->push(vertex);
    while(stack->getNumOfItems() != 0){
        int currentVertex = stack->top();
        stack->pop();
        if(!visited[currentVertex]){
            //cout<<currentVertex<<endl;
            visitedVertices->setValueAtCoordinate(1, currentVertex, 1);
            visited[currentVertex] = true;
        }
        for (int i = 0; i < graph[currentVertex].getNumOfItems(); ++i) {
            int adjV = graph[currentVertex].getItem(i);
            if(!visited[adjV]){
                stack->push(adjV);
            }
        }
    }
    visitedVertices->nlogn();
    delete[] visited;
    return visitedVertices;
}

void Graph::dftAtVertexWithK(int vertex, int k, string output){
    ofstream ofs(output.c_str());
    if(k == 0){

        ofs<<vertex<<endl;
        //cout<<vertex<<endl;
        ofs.close();
        return;
    }
    bool *visited = new bool[gSize];
    dftAtVertexWithK(vertex, visited, k, 0, output);
    delete[] visited;
}

void Graph::dftAtVertexWithK(int vertex, bool visited[], int k, int current, string output){
    ofstream ofs;
    ofs.open(output, ios::app);

    if((visited[vertex] && (current > k)) || (current > k)){
        ofs.close();
        return;
    }
    ofs<<vertex<<endl;
    ofs.close();
    cout<<vertex<<endl;
    visited[vertex] = true;
    for(int i = 0; i < graph[vertex].getNumOfItems(); i++){
        dftAtVertexWithK(graph[vertex].getItem(i), visited, k, current + 1, output);
    }

}

Graph::Graph(int size){
    maxSize = size;
    gSize = 0;
    graph = new LinkedList[size];
}

Graph::~Graph(){
    clearGraph();
}