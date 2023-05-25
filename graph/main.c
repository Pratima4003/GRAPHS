#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

int main(){
  graph G;
  initG(&G, "file.txt");
  displayG(G);
  BFS(G, 0);
  return 0;
}
