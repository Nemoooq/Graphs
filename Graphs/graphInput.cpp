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

void readGraph(int**& graph, int*& degrees, int*& degreesCopy, int numberOfVertices) {
    for (int vertexIndex = 0; vertexIndex < numberOfVertices; vertexIndex++) {
        int numberOfNeighbours;
        scanf("%d", &numberOfNeighbours);
        graph[vertexIndex] = new int[numberOfNeighbours];
        degrees[vertexIndex] = numberOfNeighbours;
        degreesCopy[vertexIndex] = numberOfNeighbours;
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
    int* degreesCopy = new int[numberOfVertices];

    readGraph(graph, degrees, degreesCopy, numberOfVertices);

    graphAnalysis(graph, numberOfVertices, degrees, degreesCopy);
    releaseMemory(graph, numberOfVertices, degrees, degreesCopy);
}

void graphAnalysis(int** graph, int numberOfVertices, int* degrees, int* degreesCopy) {
    degreeSequence(graph, numberOfVertices, degreesCopy);
    numberOfComponents(graph, numberOfVertices, degrees);
    bipartiteness(graph, numberOfVertices);
    eccentricityOfVertices(graph, numberOfVertices);
    planarity(graph, numberOfVertices);
    graphColorsGreedy(graph, numberOfVertices);
    graphColorsLF(graph, numberOfVertices);
    graphColorsSLF(graph, numberOfVertices);
    diffrentSubgraphsC(graph, numberOfVertices);
    numberOfComplementEdges(graph, numberOfVertices, degrees);
}

