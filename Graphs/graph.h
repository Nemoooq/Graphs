#ifndef GRAPH_H
#define GRAPH_H

// Function prototypes for the graph program

void merge(int* leftSide, int* rightSide, int* degrees, int* leftIndices, int* rightIndices, int* sortedVertexMap, int halfFlag, int numberOfVertices);
void mergeSort(int* degrees, int numberOfVertices, int* sortedVertexMap);
void degreeSequence(int numberOfVertices, int* degrees, int* sortedVertexMap);
void numberOfComponents(int** graph, int numberOfVertices, int* degrees);
void deepSearchFirst(int** graph, int vertex, int* visited, int numberOfVertices, int* degrees);
void bipartiteness(int** graph, int numberOfVertices, int* degrees);
int dfsCheckBipartiness(int** graph, int vertexID, int* side, int* degrees, int currentSide);
void eccentricityOfVertices();	// not implemented
void planarity(); // not implemented
void graphColorsGreedy(int** graph, int numberOfVertices, int* degrees);
void printColorsGreedy(int* colors, int numberOfVertices);
void graphColorsLF(int** graph, int numberOfVertices, int* sortedDegrees, int* sortedVertexMap);
void printColorsLF(int* colors, int numberOfVertices);
void graphColorsSLF(); // not implemented
void diffrentSubgraphsC(); // not implemented
void numberOfComplementEdges(int numberOfVertices, int* degrees);
void graphAnalysis(int** graph, int numberOfVertices, int* degrees, int* sortedDegrees, int* sortedVertexMap);
void releaseMemory(int** graph, int numberOfVertices, int* degrees, int* degreesCopy);
void readGraph(int**& graph, int*& degrees, int*& degreesCopy, int numberOfVertices, int* sortedVertexMap);
void graphInput();

#endif