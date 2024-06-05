#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"
#include <cstdio>

// Function to release memory after analyzing graph to avoid memory leaks
void releaseMemory(int** graph, int numberOfVertices, int* degrees, int* degreesCopy) {
    for (int i = 0; i < numberOfVertices; ++i) {
        delete[] graph[i]; // Deleting every array in graph array
    }

    delete[] graph;
    delete[] degrees; 
    delete[] degreesCopy;
}

// Function to read graph from input
void readGraph(int**& graph, int*& degrees, int*& degreesCopy, int numberOfVertices, int* sortedVertexMap) {
    for (int vertexIndex = 0; vertexIndex < numberOfVertices; vertexIndex++) {  //for every vertex in graph read number of neighbours and their IDs
        int numberOfNeighbours = 0;
        scanf("%d", &numberOfNeighbours);  // Reading number of neighbours

        graph[vertexIndex] = new int[numberOfNeighbours];   // Creating second array in graph array to store neighbours
        degrees[vertexIndex] = numberOfNeighbours;          // Storing number of neighbours in degrees array
        degreesCopy[vertexIndex] = numberOfNeighbours;	    // Storing number of neighbours in degreesCopy array, degrees copy is needed for sorting
        sortedVertexMap[vertexIndex] = vertexIndex;		    // Storing vertex ID in sortedVertexMap array, because after it will be sorted, we need to know which vertex it was

        for (int neighbourIndex = 0; neighbourIndex < numberOfNeighbours; neighbourIndex++) { 
            scanf("%d", &graph[vertexIndex][neighbourIndex]);   // Reading neighbours IDs
        }
    }
}

// Function to define needed variable and arrays and call functions to analyze graph
void graphInput() {
    int numberOfVertices = 0;

    scanf("%d", &numberOfVertices); // Reading number of vertices to create needed arrays and variables

    int** graph = new int* [numberOfVertices];           // Creating graph as adjacency list, itd 2D array so i need to use pointer to pointer
    int* degrees = new int[numberOfVertices];            // Creating array to store degrees of vertices
    int* sortedDegrees = new int[numberOfVertices];      // Creating array to store degrees that will be sorted
    int* sortedVertexMap = new int[numberOfVertices];    // Creating array to store vertex IDs that will be sorted

    readGraph(graph, degrees, sortedDegrees, numberOfVertices, sortedVertexMap); // Reading graph from input

    graphAnalysis(graph, numberOfVertices, degrees, sortedDegrees, sortedVertexMap); // Analyzing graph
    releaseMemory(graph, numberOfVertices, degrees, sortedDegrees); // Releasing memory
}

// Function to analyze graph, it calls all functions that analyze graph, if some function is not implemented it will be called but it will just printf "?\n".
void graphAnalysis(int** graph, int numberOfVertices, int* degrees, int* sortedDegrees, int* sortedVertexMap) {
    degreeSequence(numberOfVertices, sortedDegrees, sortedVertexMap); // It sort degrrees in not increasing order using merge sort
    numberOfComponents(graph, numberOfVertices, degrees);                    // It counts number of components in graph using DFS
    bipartiteness(graph, numberOfVertices, degrees);						 // It checks if graph is bipartite using DFS
    eccentricityOfVertices();                                                // Not implemented
    planarity();                                                             // Not implemented
    graphColorsGreedy(graph, numberOfVertices, degrees);					 // It colors graph using greedy algorithm
    graphColorsLF(graph, numberOfVertices, sortedDegrees, sortedVertexMap);  // It colors graph using LF algorithm (Greedy algorithm with sorted vertices)
    graphColorsSLF();                                                        // Not implemented
    diffrentSubgraphsC();                                                    // Not implemented
    numberOfComplementEdges(numberOfVertices, degrees);			     // It counts number of edges in complement graph (how many edges are missing in full graph)
}

