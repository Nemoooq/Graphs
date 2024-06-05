#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

void printColorsLF(int* colors, int numberOfVertices) {
    for (int i = 0; i < numberOfVertices; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

//Function to color the graph using LF algorithm, it same as greedy except commented lines
void graphColorsLF(int** graph, int numberOfVertices, int* sortedDegrees, int* sortedVertexMap) {
    int* colors = new int[numberOfVertices];
    int* usedColors = new int[numberOfVertices];
    int maxColorUsed = 0;
    for (int i = 0; i < numberOfVertices; i++) {
        colors[i] = 0;
    }
    for (int vertexID = 0; vertexID < numberOfVertices; vertexID++) {
        for (int i = 0; i <= maxColorUsed; i++) {
            usedColors[i] = 0;
        }
        for (int neighbourID = 0; neighbourID < sortedDegrees[vertexID]; neighbourID++) {
            int neighbour = graph[sortedVertexMap[vertexID]][neighbourID] - 1; //sortedVertexMap[vertexID] instead of vertexID becuse it differs from the original graph because of sorting
            if (colors[neighbour] != 0) {
                usedColors[colors[neighbour] - 1] = 1;
            }
        }
        int color;
        for (color = 0; color <= maxColorUsed; color++) {
            if (usedColors[color] == 0) {
                break;
            }
        }
        colors[sortedVertexMap[vertexID]] = color + 1; //sortedVertexMap[vertexID] instead of vertexID becuse it differs from the original graph because of sorting
        if (color == maxColorUsed) {
            maxColorUsed++;
        }
    }
    printColorsLF(colors, numberOfVertices);
    delete[] colors;
    delete[] usedColors;
}