#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

int main(){
  graph G;
  initG(&G, "file.txt");
  displayG(G);
  printf("\n /** BFS **/ \n");
  BFS(G, 0);
  printf("\n /** DFS **/ \n");
  DFS(G, 0);
  printf("\n");
  degreeV(G);
  printf("isconnected = %d\n", isConnected(G));
  printf("isAdjacent = %d\n", isAdjacent(G, 0, 0));
  printf("\n /** CYCLES **/ \n");
  cycle(G);
  printf("\n /** COMPONENTS **/ \n");
  componentsV(G);
  printf("\n");
  return 0;
}
