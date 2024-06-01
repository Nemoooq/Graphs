#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"
#include <cstdio>

void releaseMemory(int** graph, int numberOfVertices, int* degrees, int* degreesCopy) {
    for (int i = 0; i < numberOfVertices; ++i) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] degrees;
    delete[] degreesCopy;
}

void readGraph(int**& graph, int*& degrees, int*& degreesCopy, int numberOfVertices, int* sortedVertexMap) {
    for (int vertexIndex = 0; vertexIndex < numberOfVertices; vertexIndex++) {
        int numberOfNeighbours;
        scanf("%d", &numberOfNeighbours);
        graph[vertexIndex] = new int[numberOfNeighbours];
        degrees[vertexIndex] = numberOfNeighbours;
        degreesCopy[vertexIndex] = numberOfNeighbours;
        sortedVertexMap[vertexIndex] = vertexIndex;
        for (int neighbourIndex = 0; neighbourIndex < numberOfNeighbours; neighbourIndex++) {
            scanf("%d", &graph[vertexIndex][neighbourIndex]);
        }
    }
}

void graphInput() {
    int numberOfVertices;
    scanf("%d", &numberOfVertices);

    int** graph = new int* [numberOfVertices];
    int* degrees = new int[numberOfVertices];
    int* sortedDegrees = new int[numberOfVertices];
    int* sortedVertexMap = new int[numberOfVertices];

    readGraph(graph, degrees, sortedDegrees, numberOfVertices, sortedVertexMap);

    graphAnalysis(graph, numberOfVertices, degrees, sortedDegrees, sortedVertexMap);
    releaseMemory(graph, numberOfVertices, degrees, sortedDegrees);
}

void graphAnalysis(int** graph, int numberOfVertices, int* degrees, int* sortedDegrees, int* sortedVertexMap) {
    degreeSequence(graph, numberOfVertices, sortedDegrees, sortedVertexMap);
    numberOfComponents(graph, numberOfVertices, degrees);
    bipartiteness(graph, numberOfVertices, degrees);
    eccentricityOfVertices(graph, numberOfVertices);
    planarity(graph, numberOfVertices);
    graphColorsGreedy(graph, numberOfVertices, degrees);
    graphColorsLF(graph, numberOfVertices, sortedDegrees, sortedVertexMap);
    graphColorsSLF(graph, numberOfVertices, sortedDegrees,sortedVertexMap);
    diffrentSubgraphsC(graph, numberOfVertices);
    numberOfComplementEdges(graph, numberOfVertices, degrees);
}

