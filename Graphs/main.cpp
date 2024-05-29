#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"
#include <cstdio>

int main() {
	int numberOfGraphs = 0;
	scanf("%d", &numberOfGraphs);
	for (int graphID = 0; graphID < numberOfGraphs; graphID++) {
		graphInput();
	}
	return 0;
}