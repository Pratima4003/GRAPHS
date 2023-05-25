

//structure of graph
typedef struct graph{
  int **A;
  int s;
}graph;

//functions
void initG(graph *G, char* filename);
void displayG(graph G);
void BFS(graph G, int n);
void DFS(graph G, int n);
void degreeV(graph G);
int isConnected(graph G);
int isAdjacent(graph G, int A, int B);
void cycle(graph G);
