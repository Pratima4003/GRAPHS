void initG(graph *G, char *filename){
  FILE *fp = fopen(filename, "r");
  if(!fp)
    return;
  fscanf(fp, "%d", &G->n);
  G->list = (node**)malloc(sizeof(int*)*G->n);
  if(!G->list)
    return;
  int x;
  for(int i = 0; i < G->n; i++){
    G->list[i] = NULL;
    node *nn = (node*)malloc(sizeof(node));
    if (!nn){
      free(G->list);
      return;
    }
    x = fscanf(fp, "%d", &x);
    nn->data = x;
    nn->next = NULL;
    for(int j = 0; j < G.n; j++){
      if(!G.list[i][j]){
        G.list[i][j] = nn;
        return;
      }
      node *r = G.list[i][j];
      while(r->next)
          r = r->next;
      r->next = nn;
    }
  }
  return;
}

