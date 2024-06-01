#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

#define NONE 0
#define LEFT 1
#define RIGHT 2

bool dfsCheck(int** graph, int vertexID, int* side, int* degrees, int currentSide) {
    side[vertexID] = currentSide;
    for (int neighbourID = 0; neighbourID < degrees[vertexID]; neighbourID++) {
        int neighbour = graph[vertexID][neighbourID] - 1;
        if (side[neighbour] == NONE) {
            if (!dfsCheck(graph, neighbour, side, degrees, currentSide == LEFT ? RIGHT : LEFT)) {
                return false;
            }
        }
        else if (side[neighbour] == currentSide) {
            return false;
        }
    }
    return true;
}

void bipartiteness(int** graph, int numberOfVertices, int* degrees) {
    int* side = new int[numberOfVertices];
    for (int vertexID = 0; vertexID < numberOfVertices; vertexID++) {
        side[vertexID] = NONE;
    }
    for (int vertexID = 0; vertexID < numberOfVertices; vertexID++) {
        if (side[vertexID] == NONE) {
            if (!dfsCheck(graph, vertexID, side, degrees, LEFT)) {
                printf("F\n");
                delete[] side;
                return;
            }
        }
    }
    printf("T\n");
    delete[] side;
}