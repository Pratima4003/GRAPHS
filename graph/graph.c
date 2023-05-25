/** INCLUDES **/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h"
#include"queue.h"

/** FUNCTIONS **/

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
void displayG(graph G){
  for(int i = 0; i < G.s; i++){
    for(int j = 0; j < G.s; j++){
      printf("%d ", G.A[i][j]);
    }
    printf("\n");
  }
  return;
}

void BFS(graph G, int n){
  int *visited = (int*)calloc(G.s, sizeof(int));
  if(!visited)
    return;
  queue Q;
  initQ(&Q);
  enQ(&Q, n);
  visited[n] = 1; //value corresponding to insex n is marked 1
  int v, s = G.s;
  while(!isEmpty(Q)){
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

