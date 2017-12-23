#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "graph.h"
int main(void) {
  graph g = graph_new(6);
  g = graph_add_edge(g,0,1,1);
  g = graph_add_edge(g,0,3,1);
  g = graph_add_edge(g,3,1,1);
  g = graph_add_edge(g,1,4,1);
  g = graph_add_edge(g,4,3,1);
  g = graph_add_edge(g,2,4,1);
  g = graph_add_edge(g,2,5,1);
  g = graph_add_edge(g,5,5,1);
  graph_print(g);
  graph_dfs(g);
  graph_print(g);
  graph_free(g);
  return EXIT_SUCCESS;
}
