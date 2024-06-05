#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

#define NONE 0
#define LEFT 1
#define RIGHT 2

// Function that checks whether graph is bipartite or not by using DFS
int dfsCheckBipartiness(int** graph, int vertexID, int* side, int* degrees, int currentSide) {
    side[vertexID] = currentSide; // assign current side to the vertex

    for (int neighbourID = 0; neighbourID < degrees[vertexID]; neighbourID++) {
        int neighbour = graph[vertexID][neighbourID] - 1;
        if (side[neighbour] == NONE) { // if the neighbour has no side assigned, assign it to the opposite side of the current vertex
            if (!dfsCheckBipartiness(graph, neighbour, side, degrees, currentSide == LEFT ? RIGHT : LEFT)) { // if the graph is not bipartite, return 0
                return 0;
            }
        }
        else if (side[neighbour] == currentSide) { // Statement that checks if the neighbour has the same side as the current vertex, if so, return 0 (not bipartite statement)
            return 0;
        }
    }
    return 1;
}

// Function that checks whether graph is bipartite or not
void bipartiteness(int** graph, int numberOfVertices, int* degrees) {
    int* side = new int[numberOfVertices]; // create an array to store side of each vertex

    for (int vertexID = 0; vertexID < numberOfVertices; vertexID++) {
        side[vertexID] = NONE; // initialize all vertices with unasigned side (NONE)
    }

    for (int vertexID = 0; vertexID < numberOfVertices; vertexID++) { 
        if (side[vertexID] == NONE) { // if the vertex has no side assigned, assign it to the left side (LEFT [in next recursive calls, it will be RIGHT])
            if (!dfsCheckBipartiness(graph, vertexID, side, degrees, LEFT)) { // if the graph is not bipartite, print F and return
                printf("F\n"); // print F (not bipartite)
                delete[] side;
                return;
            }
        }
    }
    printf("T\n"); // print T (bipartite)
    delete[] side;
}