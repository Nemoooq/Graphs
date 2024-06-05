#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

void printColorsGreedy(int* colors, int numberOfVertices) {
    for (int i = 0; i < numberOfVertices; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

//Function to color the graph using greedy algorithm
void graphColorsGreedy(int** graph, int numberOfVertices, int* degrees) {
    int* colors = new int[numberOfVertices]; //Array to store the color of each vertex
    int* usedColors = new int[numberOfVertices]; //Array to store the used colors
    int maxColorUsed = 0; //Variable to store the maximum color used

    for (int i = 0; i < numberOfVertices; i++) {
        colors[i] = 0; //Initialize all vertices as not colored
    }

    for (int vertexID = 0; vertexID < numberOfVertices; vertexID++) {
        for (int i = 0; i <= maxColorUsed; i++) {
            usedColors[i] = 0; // Reset the used colors, couldnt find a faster way to do this
        }

        for (int neighbourID = 0; neighbourID < degrees[vertexID]; neighbourID++) { //Iterate over the neighbours of the vertex
            int neighbour = graph[vertexID][neighbourID] - 1; //Get the neighbour (-1 because the vertices are 1-indexed)
            if (colors[neighbour] != 0) { //If the neighbour is already colored, mark the color as used
                usedColors[colors[neighbour] - 1] = 1; //Mark the color as used
            }
        }
        int color; //Variable to store the color
        for (color = 0; color <= maxColorUsed; color++) {
            if (usedColors[color] == 0) { //If the color is not used, break the loop
                break;
            }
        }
        colors[vertexID] = color + 1; //Assign the color to the vertex
        if (color == maxColorUsed) { //If the color is the maximum color used, increment the maximum color used
            maxColorUsed++;
        }
    }

    printColorsGreedy(colors, numberOfVertices); //Print the colors

    delete[] colors;
    delete[] usedColors;
}