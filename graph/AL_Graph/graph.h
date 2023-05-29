//structure of graph
typedef struct node{
  int data;
  struct node *next;
}node;

typedef struct graph{
  node **list;
  int n;
}graph;

void initG(graph *G, char *filename);
