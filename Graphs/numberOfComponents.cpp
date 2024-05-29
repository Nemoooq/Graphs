#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

void deepSearchFirst(int** graph, int vertex, bool* visited, int numberOfVertices, int* degrees) {
    visited[vertex] = true;;
    for (int i = 0; i < degrees[vertex]; i++) {
        int index = (graph[vertex][i] - 1);
        if (!visited[index]) {
            deepSearchFirst(graph, index, visited, numberOfVertices, degrees);
        }
    }
}

void numberOfComponents(int** graph, int numberOfVertices, int* degrees) {
    bool* visited = new bool[numberOfVertices];
    int componentsCounter = 0;
    for (int i = 0; i < numberOfVertices; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < numberOfVertices; i++) {
        if (!visited[i]) {
            deepSearchFirst(graph, i, visited, numberOfVertices, degrees);
            componentsCounter++;
        }
    }
    printf("%d\n", componentsCounter);
    delete[] visited;
}