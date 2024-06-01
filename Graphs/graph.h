#ifndef GRAPH_H
#define GRAPH_H

void merge(int* leftSide, int* rightSide, int* degrees, int* leftIndices, int* rightIndices, int* sortedVertexMap, int halfFlag, int numberOfVertices);
void mergeSort(int* degrees, int numberOfVertices, int* sortedVertexMap);
void degreeSequence(int** graph, int numberOfVertices, int* degrees, int* sortedVertexMap);
void deepSearchFirst(int** graph, int vertex, bool* visited, int numberOfVertices, int* degrees);
void numberOfComponents(int** graph, int numberOfVertices, int* degrees);
void bipartiteness(int** graph, int numberOfVertices, int* degrees);
void eccentricityOfVertices(int** graph, int numberOfVertices);
void planarity(int** graph, int numberOfVertices);
void graphColorsGreedy(int** graph, int numberOfVertices, int* degrees);
void graphColorsLF(int** graph, int numberOfVertices, int* sortedDegrees, int* sortedVertexMap);
void graphColorsSLF(int** graph, int numberOfVertices, int* sortedDegrees, int* sortedVertexMap);
void diffrentSubgraphsC(int** graph, int numberOfVertices);
void numberOfComplementEdges(int** graph, int numberOfVertices, int* degrees);
void graphAnalysis(int** graph, int numberOfVertices, int* degrees, int* degreesCopy, int* sortedVertexMap);
void releaseMemory(int** graph, int numberOfVertices, int* degrees, int* degreesCopy);
void readGraph(int**& graph, int*& degrees, int*& degreesCopy, int numberOfVertices, int* sortedVertexMap);
void graphInput();

#endif