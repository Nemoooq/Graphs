#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

void printColorsGreedy(int* colors, int numberOfVertices) {
    for (int i = 0; i < numberOfVertices; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

void graphColorsGreedy(int** graph, int numberOfVertices, int* degrees) {
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
        for (int neighbourID = 0; neighbourID < degrees[vertexID]; neighbourID++) {
            int neighbour = graph[vertexID][neighbourID] - 1;
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
        colors[vertexID] = color + 1;
        if (color == maxColorUsed) {
            maxColorUsed++;
        }
    }
    printColorsGreedy(colors, numberOfVertices);
    delete[] colors;
    delete[] usedColors;
}