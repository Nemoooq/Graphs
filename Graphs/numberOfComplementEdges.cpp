#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

// Function to calculate the number of edges in the complement graph
void numberOfComplementEdges(int numberOfVertices, int* degrees) {
    long long int lnumberOfVertices = numberOfVertices; // Convert to long long int
    long long int numberOfCompleteGraphEdges = lnumberOfVertices * (lnumberOfVertices - 1) / 2; // Calculate the number of edges in the complete graph
    long long int numberOfGraphEdges = 0; // Initialize the number of edges in the graph

    for (int vertexIndex = 0; vertexIndex < numberOfVertices; vertexIndex++) {
        numberOfGraphEdges += degrees[vertexIndex]; // Add the number of edges of the vertex to the total number of edges
    }

    printf("%lld\n", numberOfCompleteGraphEdges - (numberOfGraphEdges / 2)); // Print the number of edges in the complement graph
}