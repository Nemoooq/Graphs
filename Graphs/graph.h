#ifndef GRAPH_H
#define GRAPH_H

void merge(int* leftSide, int* rightSide, int* degrees, int halfFlag, int numberOfVertices);
void mergeSort(int* degrees, int numberOfVertices);
void degreeSequence(int** graph, int numberOfVertices, int* degrees);
void deepSearchFirst(int** graph, int vertex, bool* visited, int numberOfVertices, int* degrees);
void numberOfComponents(int** graph, int numberOfVertices, int* degrees);
void bipartiteness(int** graph, int numberOfVertices);
void eccentricityOfVertices(int** graph, int numberOfVertices);
void planarity(int** graph, int numberOfVertices);
void graphColorsGreedy(int** graph, int numberOfVertices, int* ddegrees);
void graphColorsLF(int** graph, int numberOfVertices);
void graphColorsSLF(int** graph, int numberOfVertices);
void diffrentSubgraphsC(int** graph, int numberOfVertices);
void numberOfComplementEdges(int** graph, int numberOfVertices, int* degrees);
void graphAnalysis(int** graph, int numberOfVertices, int* degrees, int* degreesCopy);
void releaseMemory(int** graph, int numberOfVertices, int* degrees, int* degreesCopy);
void readGraph(int**& graph, int*& degrees, int*& degreesCopy, int numberOfVertices);
void graphInput();

#endif