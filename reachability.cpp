#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

#include "ArgumentManager.h"
#include "LinkedList.h"
#include "MatrixElement.h"
#include "ArrayMatrix.h"
#include "Graph.h"
#include "StackLinkedList.h"
#include "HashTable.h"


int main(int argc, char *argv[]) {

//    ArgumentManager am(argc, argv);
//    string dfs = am.get("dfs");
////    string iterations = am.get("k");
//    string sourceNum = am.get("source");
//    string inputA = am.get("E");
//    string output = am.get("result");
//    string labelFile = am.get("labels");

    string inputA = "a1.txt";
    string output = "S.txt";
    string labelFile = "l01.txt";
    //string dfs = "iterative";
    string dfs = "recursive";
    //string dfs = "no";
    //string iterations = "100";
    string sourceNum = "512";


    //istringstream it(iterations); // Number of Iterations
    istringstream so(sourceNum); // Source number
    int source = 1;
    //int numOfIterations = 0;
    //it >> numOfIterations;
    so >> source;
    int vertex = source;

    bool found = false;
    ArrayMatrix *matrixA = new ArrayMatrix(inputA, output);
    for (int i = 0; i < matrixA->arrayList->getNumElements(); ++i) {
        MatrixElement *current = matrixA->arrayList->getMatrixElement(i);
        if(current->row == vertex || current->col == vertex){
            found = true;
        }
    }

    if(!found){
        cout<<"Source is not in graph"<<endl;
        return 0;
    }

    int vectorCols = matrixA->getNumOfVectCols();
    Graph *graph = new Graph(vectorCols + 1);

    ArrayMatrix *result;
    if(dfs == "iterative") {

        //cout<<"using dfs"<<endl;
        graph->createGraph(matrixA);
        result = graph->dftAtVertexIter(vertex, output);
        //graph->dftAtVertexWithK(vertex, numOfIterations, output);
        //graph->printGraph();
    }

    else if(dfs == "no") {
        //cout<<"using vmm"<<endl;
        matrixA->nlogn();
        result = new ArrayMatrix;
        result->setValueAtCoordinate(1, source, 1);
        int numberOfVisitedVertices = 0;


        while(numberOfVisitedVertices < result->arrayList->getNumElements()){
            if (result->getValueAtCoordinate(1, vectorCols) == 0) {
                result->setValueAtCoordinate(1, vectorCols, 0);
            }
            //vectorS->unionSets(vectorS->matrixMultiplication(matrixA));
            numberOfVisitedVertices = result->arrayList->getNumElements();
            result->unionSets(result->vectorMatrixMultiplication(matrixA));
        }
//        result->sortMatrix();
//        result->printResultToFile(output);
//        result->printResult();
    }

    else if (dfs == "recursive"){

        //cout<<"using dfs2"<<endl;
        Graph *graph = new Graph(vectorCols + 1);
        graph->createGraph(matrixA);
        result = graph->dftAtVertex(vertex);
        //graph->dftAtVertexWithK(vertex, numOfIterations, output);
        //graph->printGraph();
    }else{
        //cout<<"using dfs2"<<endl;
        Graph *graph = new Graph(vectorCols + 1);
        graph->createGraph(matrixA);
        result = graph->dftAtVertex(vertex);
        //graph->dftAtVertexWithK(vertex, numOfIterations, output);
        //graph->printGraph();
    }
    HashTable *labels = new HashTable(labelFile, "empty.txt");
    result->sortMatrix();
    result->printResultToFile(labels, output);
    //result->printResult(labels);

    return 0;
}