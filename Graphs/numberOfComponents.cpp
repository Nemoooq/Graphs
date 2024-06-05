#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "graph.h"

//Function to perform a deep search first in a graph
void deepSearchFirst(int** graph, int vertex, int* visited, int numberOfVertices, int* degrees) {
    visited[vertex] = 1;

    for (int i = 0; i < degrees[vertex]; i++) {
        int index = (graph[vertex][i] - 1); //Get the index of the neighbour (-1 because the vertices are 1-indexed)

        if (!visited[index]) { //If the neighbour has not been visited, perform a DFS from it
            deepSearchFirst(graph, index, visited, numberOfVertices, degrees);
        }
    }
}

//Function to count the number of components in a graph (number of connected subgraphs), it counts the number of times the DFS is called
void numberOfComponents(int** graph, int numberOfVertices, int* degrees) {
    int* visited = new int[numberOfVertices]; //Array to store if a vertex has been visited
    int componentsCounter = 0; //Counter for the number of components

    for (int i = 0; i < numberOfVertices; i++) {
        visited[i] = 0;  //Initialize all vertices as not visited
    }

    for (int i = 0; i < numberOfVertices; i++) {
        if (!visited[i]) { //If the vertex has not been visited, start a new component
            deepSearchFirst(graph, i, visited, numberOfVertices, degrees); //DFS from the vertex
            componentsCounter++; //Increment the number of components
        }
    }

    printf("%d\n", componentsCounter); //Print the number of components

    delete[] visited; //Free the memory
}