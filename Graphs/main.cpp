#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

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
    int halfFlag = numberOfVertices/2;
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
    int* degreesCopy = new int[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++) {
        degreesCopy[i] = degrees[i];
    }
    mergeSort(degreesCopy, numberOfVertices);
    for (int i = numberOfVertices-1; i >= 0; i--) {
		printf("%d ", degreesCopy[i]);
	}
    printf("\n");
    delete[] degreesCopy;
}

void deepSearchFirst(int** graph, int vertex, bool* visited, int numberOfVertices, int* degrees) {
    visited[vertex] = true;
    for (int i = 0; i < degrees[vertex]; i++) {
        int index = graph[vertex][i];
        if (!visited[index]) {
			deepSearchFirst(graph, index, visited, numberOfVertices, degrees);
		}
	}
}

void numberOfComponents(int** graph, int numberOfVertices, int* degrees) {
	bool* visited = new bool[numberOfVertices];
    int componentsCounter = 0;
    for (int i = 0; i < numberOfVertices; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < numberOfVertices; i++) {
        if (!visited[i]) {
            deepSearchFirst(graph, i, visited, numberOfVertices, degrees);
            componentsCounter++;
        }
    }
    printf("%d\n", componentsCounter);
    delete[] visited;
}

void bipartiteness(int** graph, int numberOfVertices) {
	printf("?\n");
}

void eccentricityOfVertices(int** graph, int numberOfVertices) {
	printf("?\n");
}

void planarity(int** graph, int numberOfVertices) {
	printf("?\n");
}

void graphColorsGreedy(int** graph, int numberOfVertices) {
	printf("?\n");
}

void graphColorsLF(int** graph, int numberOfVertices) {
	printf("?\n");
}

void graphColorsSLF(int** graph, int numberOfVertices) {
	printf("?\n");
} 

void diffrentSubgraphsC(int** graph, int numberOfVertices) {
	printf("?\n");
}

void numberOfComplementEdges(int** graph, int numberOfVertices) {
	printf("?\n");
}

void graphAnalysis(int** graph, int numberOfVertices, int* degrees) {
    degreeSequence(graph, numberOfVertices, degrees);
    numberOfComponents(graph, numberOfVertices, degrees);
    bipartiteness(graph, numberOfVertices);
    eccentricityOfVertices(graph, numberOfVertices);
    planarity(graph, numberOfVertices);
    graphColorsGreedy(graph, numberOfVertices);
    graphColorsLF(graph, numberOfVertices);
    graphColorsSLF(graph, numberOfVertices);
    diffrentSubgraphsC(graph, numberOfVertices);
    numberOfComplementEdges(graph, numberOfVertices);
}

void releaseMemory(int** graph, int numberOfVertices, int* degrees) {
    for (int i = 0; i < numberOfVertices; ++i) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] degrees;
}

void graphInput() {
    int inputCorrectness = 0;
    int numberOfVertices = 0;
    int numberOfNeigbours = 0;
    inputCorrectness = scanf("%d", &numberOfVertices);
    int** graph = new int* [numberOfVertices];
    int* degrees = new int[numberOfVertices];
    for (int vertexIndex = 0; vertexIndex < numberOfVertices; vertexIndex++) {
        inputCorrectness = scanf("%d", &numberOfNeigbours);
        graph[vertexIndex] = new int[numberOfNeigbours];
        degrees[vertexIndex] = numberOfNeigbours;
        for (int neighbourIndex = 0; neighbourIndex < numberOfNeigbours; neighbourIndex++) {
            inputCorrectness = scanf("%d", &graph[vertexIndex][neighbourIndex]);
        }
    }
    graphAnalysis(graph, numberOfVertices, degrees);
    releaseMemory(graph, numberOfVertices, degrees);
}


int main() {
	int inputCorrectness = 0;
	int numberOfGraphs = 0;
	inputCorrectness = scanf("%d", &numberOfGraphs);
	for (int graphID = 0; graphID < numberOfGraphs; graphID++) {
		graphInput();
	}
	return 0;
}