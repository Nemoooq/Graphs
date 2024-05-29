#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

void merge(int* leftSide, int* rightSide, int* degrees, int halfFlag, int numberOfVertices) {
    int leftIndex = 0;
    int rightIndex = 0;
    int degreesIndex = 0;
    while (leftIndex < halfFlag && rightIndex < numberOfVertices - halfFlag) {
        if (leftSide[leftIndex] <= rightSide[rightIndex]) {
            degrees[degreesIndex] = leftSide[leftIndex];
            leftIndex++;
        }
        else {
            degrees[degreesIndex] = rightSide[rightIndex];
            rightIndex++;
        }
        degreesIndex++;
    }
    while (leftIndex < halfFlag) {
        degrees[degreesIndex] = leftSide[leftIndex];
        leftIndex++;
        degreesIndex++;
    }
    while (rightIndex < numberOfVertices - halfFlag) {
        degrees[degreesIndex] = rightSide[rightIndex];
        rightIndex++;
        degreesIndex++;
    }
}

void mergeSort(int* degrees, int numberOfVertices) {
    if (numberOfVertices <= 1) {
        return;
    }
    int halfFlag = numberOfVertices / 2;
    int* leftSide = new int[halfFlag];
    int* rightSide = new int[numberOfVertices - halfFlag];
    for (int i = 0; i < halfFlag; i++) {
        leftSide[i] = degrees[i];
    }
    for (int i = halfFlag; i < numberOfVertices; i++) {
        rightSide[i - halfFlag] = degrees[i];
    }
    mergeSort(leftSide, halfFlag);
    mergeSort(rightSide, numberOfVertices - halfFlag);
    merge(leftSide, rightSide, degrees, halfFlag, numberOfVertices);
    delete[] leftSide;
    delete[] rightSide;
}

void degreeSequence(int** graph, int numberOfVertices, int* degrees) {
    mergeSort(degrees, numberOfVertices);
    for (int i = numberOfVertices - 1; i >= 0; i--) {
        printf("%d ", degrees[i]);
    }
    printf("\n");
}