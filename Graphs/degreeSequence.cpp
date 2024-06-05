#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

// Function to merge the left and right halves of the array
void merge(int* leftSide, int* rightSide, int* degrees, int* leftIndices, int* rightIndices, int* sortedVertexMap, int halfFlag, int numberOfVertices) {
    int leftIndex = 0; // initializing temponary indexes for the left and right halves
    int rightIndex = 0;
    int degreesIndex = 0;

    while (leftIndex < halfFlag && rightIndex < numberOfVertices - halfFlag) { // merge the left and right halves while there are elements in both halves
        if (leftSide[leftIndex] >= rightSide[rightIndex]) {
            degrees[degreesIndex] = leftSide[leftIndex];                // if the element from the left half is greater or equal to the element from the right half
            sortedVertexMap[degreesIndex] = leftIndices[leftIndex];     // add the element from the left half to the sorted array
            leftIndex++;                                                // and increment the left index
        }
        else {
            degrees[degreesIndex] = rightSide[rightIndex];              // if the element from the right half is greater
            sortedVertexMap[degreesIndex] = rightIndices[rightIndex];   // add the element from the right half to the sorted array
            rightIndex++;											     // and increment the right index
        }
        degreesIndex++; // increment the index of the sorted array
    }

    while (leftIndex < halfFlag) { // add the remaining elements from the left half to the sorted array, same as above
        degrees[degreesIndex] = leftSide[leftIndex];
        sortedVertexMap[degreesIndex] = leftIndices[leftIndex];
        leftIndex++;
        degreesIndex++;
    }

    while (rightIndex < numberOfVertices - halfFlag) { // add the remaining elements from the right half to the sorted array same as above
        degrees[degreesIndex] = rightSide[rightIndex];
        sortedVertexMap[degreesIndex] = rightIndices[rightIndex];
        rightIndex++;
        degreesIndex++;
    }
}

// Function to sort the degree sequence using merge sort, this is part divison of the array
void mergeSort(int* degrees, int numberOfVertices, int* sortedVertexMap) {
    if (numberOfVertices <= 1) {
        return;     // ending condition for the recursion, if array is separated into single elements
    }
    int halfFlag = numberOfVertices / 2; // flag to separate the array into two halves

    int* leftSide = new int[halfFlag]; // arrays to store the hleft half and right half of the array
    int* rightSide = new int[numberOfVertices - halfFlag];

    int* leftIndices = new int[halfFlag]; // arrays to store the indexes of the elements in the left and right halves
    int* rightIndices = new int[numberOfVertices - halfFlag];

    for (int i = 0; i < halfFlag; i++) { // fill the left side with the corresponding elements and indexes
        leftSide[i] = degrees[i];
        leftIndices[i] = sortedVertexMap[i];
    }
    for (int i = halfFlag; i < numberOfVertices; i++) { // fill the right side with the corresponding elements and indexes
        rightSide[i - halfFlag] = degrees[i];
        rightIndices[i - halfFlag] = sortedVertexMap[i];
    }

    mergeSort(leftSide, halfFlag, leftIndices); // recursive call to sort the left and right halves
    mergeSort(rightSide, numberOfVertices - halfFlag, rightIndices);

    merge(leftSide, rightSide, degrees, leftIndices, rightIndices, sortedVertexMap, halfFlag, numberOfVertices); // merge the sorted halves

    delete[] leftSide; // delete the temporary arrays
    delete[] rightSide;
    delete[] leftIndices;
    delete[] rightIndices;
}

// Function to sort and print the degree sequence in non-increasing order
void degreeSequence(int numberOfVertices, int* degrees, int* sortedVertexMap) {
    mergeSort(degrees, numberOfVertices, sortedVertexMap); // sort degrees and create a map of sorted vertices

    for (int i = 0; i < numberOfVertices; i++) {
        printf("%d ", degrees[i]);
    }

    printf("\n");
}

