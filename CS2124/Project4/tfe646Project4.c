#include "Graph.h"


int main()
{
	FILE *fptr = fopen("p4Input.txt", "r");
	int numOfVertices, numOfEdges, tempFrom, tempTo, pathsToCompute, pathStart, pathEnd;
	Edge myEdge;

	if(fptr == NULL) {
		perror("Error opening file");
		return -1;
	}

	fscanf(fptr, "%d", &numOfVertices);
	fscanf(fptr, "%d", &numOfEdges);

	Graph myGraph = newGraph(numOfVertices);

	while(numOfEdges--) {
		fscanf(fptr, "%d %d", &tempFrom, &tempTo);
		myEdge.fromVertex = tempFrom;
		myEdge.toVertex = tempTo;
		addEdge(myGraph, myEdge);
	}

	//printAdjMatrix(myGraph);

	fscanf(fptr, "%d", &pathsToCompute);

	while(pathsToCompute--) {
		fscanf(fptr, "%*s %d %d", &pathStart, &pathEnd);
		printf("%d %d\n", pathStart, pathEnd);

		shortestPath(myGraph, pathStart, pathEnd);
		printf("\n");
	}
		
	return 0;
}


