#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

void merge(int* leftSide, int* rightSide, int* degrees, int* leftIndices, int* rightIndices, int* sortedVertexMap, int halfFlag, int numberOfVertices) {
    int leftIndex = 0;
    int rightIndex = 0;
    int degreesIndex = 0;
    while (leftIndex < halfFlag && rightIndex < numberOfVertices - halfFlag) {
        if (leftSide[leftIndex] >= rightSide[rightIndex]) {
            degrees[degreesIndex] = leftSide[leftIndex];
            sortedVertexMap[degreesIndex] = leftIndices[leftIndex];
            leftIndex++;
        }
        else {
            degrees[degreesIndex] = rightSide[rightIndex];
            sortedVertexMap[degreesIndex] = rightIndices[rightIndex];
            rightIndex++;
        }
        degreesIndex++;
    }
    while (leftIndex < halfFlag) {
        degrees[degreesIndex] = leftSide[leftIndex];
        sortedVertexMap[degreesIndex] = leftIndices[leftIndex];
        leftIndex++;
        degreesIndex++;
    }
    while (rightIndex < numberOfVertices - halfFlag) {
        degrees[degreesIndex] = rightSide[rightIndex];
        sortedVertexMap[degreesIndex] = rightIndices[rightIndex];
        rightIndex++;
        degreesIndex++;
    }
}

void mergeSort(int* degrees, int numberOfVertices, int* sortedVertexMap) {
    if (numberOfVertices <= 1) {
        return;
    }
    int halfFlag = numberOfVertices / 2;
    int* leftSide = new int[halfFlag];
    int* rightSide = new int[numberOfVertices - halfFlag];
    int* leftIndices = new int[halfFlag];
    int* rightIndices = new int[numberOfVertices - halfFlag];

    for (int i = 0; i < halfFlag; i++) {
        leftSide[i] = degrees[i];
        leftIndices[i] = sortedVertexMap[i];
    }
    for (int i = halfFlag; i < numberOfVertices; i++) {
        rightSide[i - halfFlag] = degrees[i];
        rightIndices[i - halfFlag] = sortedVertexMap[i];
    }

    mergeSort(leftSide, halfFlag, leftIndices);
    mergeSort(rightSide, numberOfVertices - halfFlag, rightIndices);
    merge(leftSide, rightSide, degrees, leftIndices, rightIndices, sortedVertexMap, halfFlag, numberOfVertices);

    delete[] leftSide;
    delete[] rightSide;
    delete[] leftIndices;
    delete[] rightIndices;
}

void degreeSequence(int** graph, int numberOfVertices, int* degrees, int* sortedVertexMap) {
    mergeSort(degrees, numberOfVertices, sortedVertexMap);
    for (int i = 0; i < numberOfVertices; i++) {
        printf("%d ", degrees[i]);
    }
    printf("\n");
}