/** INCLUDES **/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h"
#include"queue.h" //for BFS
#include"stack.h" //for DFS

/** UTILITY FUNCTIONS **/

//for display all the cycles in a graph
int *cycleUtility(graph G, int Q, int *visited){
  visited[Q] = 1;
  int *C = (int*)malloc(sizeof(int) * G.s);
  if(!C)
    return NULL;
  for(int i = 0; i < G.s; i++){
    for(int j = 0; j < G.s; j++){
      if(G.A[Q][j] && !visited[i]){  
        C[i] = i;
        C = cycleUtility(G, i, visited);
      }
    }
  }
  return C;
}

//for number of components in graph
void componentsUtility(graph G, int v, int *visited){
  printf("%d ", v);
  visited[v] = 1;
  for(int i = 0; i < G.s; i++){
    for(int j = 0; j < G.s; j++){
      if(G.A[v][i] && !visited[i]){
        componentsUtility(G, i, visited);
      }
    }
  }
  return;
}

void DFS2(graph G){
  int *visited = (int*)calloc(G.s, sizeof(int));
  if(!visited)
    return;
  stack S;
  initS(&S);
  for(int p = 0; p < G.s; p++){
    if(!visited[p]){
      pushS(&S, p);
      visited[p] = 1;
      int n, s = G.s;
      while(!isEmptyS(S)){
        n = popS(&S);
        printf("%d\t", n);
        for(int i = 0; i < s; i++){
          if(G.A[n][i] != 0 && !visited[i]){
            pushS(&S, i);   //it takes place (n - 1) times
            visited[i] = 1;
          }
        }
      }
    }
  }
  return;
}

/** FUNCTIONS **/

//initialization of graph from a file with name filename
void initG(graph *G, char* filename){
  FILE *fp = fopen(filename, "r");
  if(!fp)
    return;
  fscanf(fp, "%d", &G->s);
  G->A = (int**)malloc(sizeof(int*)*G->s);
  if(!G->A)
    return;
  for(int i = 0; i < G->s; i++){
    G->A[i] = (int*)malloc(sizeof(int)*G->s);
    if(G->A[i] == NULL){
      free(G->A);
      return;
    }
    for(int j = 0; j < G->s; j++){
      fscanf(fp, "%d", &G->A[i][j]);
    }
  }
  return;
}

//display the graph as it is in the file
void displayG(graph G){
  for(int i = 0; i < G.s; i++){
    for(int j = 0; j < G.s; j++){
      printf("%d ", G.A[i][j]);
    }
    printf("\n");
  }
  return;
}

//BFS traversal
void BFS(graph G, int n){
  int *visited = (int*)calloc(G.s, sizeof(int));
  if(!visited)
    return;
  queue Q;
  initQ(&Q);
  enQ(&Q, n);
  visited[n] = 1; //value corresponding to insex n is marked 1
  int v, s = G.s;
  while(!isEmptyQ(Q)){
    v = deQ(&Q);
    printf("%d\t", v);
    //look for all non visited adjacent vertices of v
    for(int i = 0; i < s; i++){
      if(G.A[v][i] && !visited[i]){
        enQ(&Q, i);
        visited[i] = 1;
      }
    }
  }
  printf("\n");
  return;
}

//DFS traversal
void DFS(graph G, int v){
  int *visited = (int*)calloc(G.s, sizeof(int));
  if(!visited)
    return;
  stack S;
  initS(&S);
  pushS(&S, v);
  visited[v] = 1;
  int n, s = G.s;
  while(!isEmptyS(S)){
    n = popS(&S);
    printf("%d\t", n);
    for(int i = 0; i < s; i++){
      if(G.A[n][i] != 0 && !visited[i]){
        pushS(&S, i);   //it takes place (n - 1) times
        visited[i] = 1;
      }
    }
  }
  return;
}

//displays degree of each vertex
void degreeV(graph G){
  for(int i = 0; i < G.s; i++){
    int deg = 0;
    for(int j = 0; j < G.s; j++){
      if(G.A[i][j])
        deg++;
    }
    printf("V = %d\tD = %d", i, deg);
    printf("\n");
  }
  return;
}

//this function checks whether the graph is connected or not
int isConnected(graph G){
  int *marked = (int*)calloc(G.s, sizeof(int));
  if(!marked)
    return INT_MIN;
  for(int i = 0; i < G.s; i++){
    for(int j = 0; j < G.s; j++){
      if(G.A[i][j])
        marked[i] = 1;
    }
  }
  for(int i = 0; i < G.s; i++){
    if(marked[i] == 0)
      return 0;
  }
  return 1;
}

//this function displays the number of components in the graph and its vertices
void componentsV(graph G){
  /*int *visited = (int*)calloc(G.s, sizeof(int));
  if(!visited)
    return;
  for(int i = 0; i < G.s; i++){
    if(!visited[i]){
      componentsUtility(G, i, visited);
    }
  }
  free(visited);*/
  DFS2(G);
  printf("\n");
  return;
}

//this function returns 1 when A and B are connected and 0 if they are not
int isAdjacent(graph G, int P, int Q){
  if(G.A[P][Q])
    return 1;
  return 0;
}

//displays all cycles in the graph
void cycle(graph G){
  int cond = isConnected(G);
  if(cond == 0)
    return;
  int *visited = (int*)calloc(G.s, sizeof(int));
  if(!visited)
    return;
  int s = G.s;
  int *C;
  for(int i = 0; i < s; i++){
    C = cycleUtility(G, i, visited);
    for(int j = 0; j <= i; j++){
      printf("%d\t", C[j]);
    }
    printf("\n");
  }
  return;
}

