#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

void numberOfComplementEdges(int** graph, int numberOfVertices, int* degrees) {
    long long int lnumberOfVertices = numberOfVertices;
    long long int numberOfCompleteGraphEdges = lnumberOfVertices * (lnumberOfVertices - 1) / 2;
    long long int numberOfGraphEdges = 0;
    for (int vertexIndex = 0; vertexIndex < numberOfVertices; vertexIndex++) {
        numberOfGraphEdges += degrees[vertexIndex];
    }
    printf("%lld\n", numberOfCompleteGraphEdges - (numberOfGraphEdges / 2));
}