#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"
#include <cstdio>

int main() {
	int numberOfGraphs = 0;

	scanf("%d", &numberOfGraphs);									// Reading the number of graphs to define how many times the graph will be readeda and analyzed

	for (int graphID = 0; graphID < numberOfGraphs; graphID++) {
		graphInput();												// Calling the function to read the graph and then analyze it
	}

	return 0;
}