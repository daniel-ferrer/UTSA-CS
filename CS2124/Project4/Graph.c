#include "Graph.h"

/******
 * In this file, provide all of the definitions of the graph functions as described in Graph.h.
 *
 * ****/

//Given the number of vertices of the graph, allocate the nxn adjacency matrix and initialize every edge to 0 (i.e. the edges aren't there initially).
//Return the address of the graph.
Graph newGraph(int n) {
    int i, j;

    Graph myGraph = (Graph)malloc(sizeof(GraphImp));
    myGraph->n = n;
    myGraph->adjacencyM = (int**)malloc(n * sizeof(int*));

    for(i = 0; i < n; i++) {
        myGraph->adjacencyM[i] = (int*)malloc(n * sizeof(int));
        for(j = 0; j < n; j++) {
            myGraph->adjacencyM[i][j] = 0;
        }
    }

    return myGraph;
}

//Free the adjacency matrix and then the graph itself.
void freeGraph(Graph g) {
    int i; 

    for(i = 0; i < g->n; i++) {
        free(g->adjacencyM[i]);
    }
    free(g->adjacencyM);
    free(g);
}

//Add the edge e to the graph g.
void addEdge(Graph g, Edge e) {
    g->adjacencyM[e.fromVertex][e.toVertex] = 1;
}

//Given graph g and vertex v, scan the adjacency matrix and return the first edge in g such that v is the "fromVertex" of the edge.
//Return NULL if there is no such edge.
Edge firstAdjacent(Graph g, Vertex v) {
    int i;
    Edge temp;

    for(i = 0; i < g->n; i++) {
        if(g->adjacencyM[v][i] != 0) {
            temp.fromVertex = v;
            temp.toVertex = i;
            return temp;
        }
    }
    temp.toVertex = -1;
    temp.fromVertex = -1;
    return temp;
}

//Given graph g and vertex e, scan the adjacency matrix and return the next edge after e in g such that e.fromVertex is the "fromVertex" of the edge.
//Return NULL if there is no such edge.
Edge nextAdjacent(Graph g, Edge e) {
    Vertex v = e.fromVertex;
    int i;
    Edge e2;

    for(i = e.toVertex + 1; i < g->n; i++) {
        if(g->adjacencyM[v][i] == 1) {
            e2.fromVertex = v;
            e2.toVertex = i;
            return e2;
        }
    }
    e2.fromVertex = -1;
    e2.toVertex = -1;
    return e2;
}

//Print the sequence of vertices on a shortest path in g starting from start and ending at destination.  
//A shortest path should be computed using the Breadth First Search (BFS) algorithm that maintains the parents of each vertex in the shortest path tree as defined in class.  
//BFS can be implemented directly in this function, or you may create a new function for BFS.
void shortestPath(Graph g, Vertex start, Vertex destination) {
    int i;
    Edge e;
    int* visited = (int*)malloc(g->n * sizeof(int));
    int* parent = (int*)malloc(g->n * sizeof(int));

    for(i = 0; i < g->n; i++) {
        visited[i] = 0;
    }

    Vertex currVertex, tempVertex;
    Queue q = newQueue();
    enqueue(q, start);
    visited[start] = 1;

    while(dequeue(q, &currVertex)) {
        for(e = firstAdjacent(g, currVertex); e.toVertex != -1; e = nextAdjacent(g, e)) {
            tempVertex = e.toVertex;
            if(visited[tempVertex] == 0) {
                enqueue(q, tempVertex);
                visited[tempVertex] = 1;
                parent[tempVertex] = currVertex;
            }
            if(tempVertex == destination) {
                backtracePath(parent, start, destination, g->n);
            }
        }
    }
    freeQueue(q);
}

void backtracePath(int* parent, int start, int end, int size) {
    int i;
    
    Queue path = newQueue();
    Queue ans = newQueue();
    enqueue(path, end);

    for(i = size - 1; path->foot->element != start;) {
        if(parent[i] == 0) {
            break;
        }

        enqueue(path, parent[i]);
        i = parent[i];
    }

    printQueue(path, start, end);
}

void printAdjMatrix(Graph g) {
    int i, j;
    
    for(i = 0; i < g->n; i++) {
        for(j = 0; j < g->n; j++) {
            printf("%d ", g->adjacencyM[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}