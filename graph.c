#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "mylib.h"
#include "queue.h"

typedef enum {UNVISITED,VISITED_SELF,VISITED_DESCENDANTS} state_t;

static int step; 

struct vertex{
    int pred;
    int distance;
    state_t state; 
    int finish;

};

struct graphrec {
    int size;
    int **edges;
    vertex *vertices;
};




graph graph_new(int v) {
    int i;
    int j;
    graph result = emalloc(sizeof *result);
    result->vertices = emalloc( v * sizeof result->vertices[0]);
    result->edges = emalloc(v * sizeof result->edges[0]);
    for(i=0; i<v; i++){
        result->edges[i] = emalloc( v * sizeof result->edges[0][0]);
	for (j=0;j<v;j++){
	  result->edges[i][j] = 0; 
        }
    }
    for(i =0; i<v;i++){
      result->vertices[i].pred = -1;
      result->vertices[i].distance = -1;
      result->vertices[i].state = UNVISITED;
      result->vertices[i].finish = 0;
    }
    result->size = v; 
    return result;

}

void graph_free(graph g){
  int i;
  for(i=0;i<g->size;i++){
      free(g->edges[i]);
  }
  free(g->edges);
  free(g->vertices);
  free(g);

}

static void add(graph g, int a, int b){
  g->edges[a][b]=1; 
}

graph graph_add_edge(graph g,int a, int b, int directional){
    add(g,a,b);
    if (directional == 0){
      add(g,b,a);
    }
    return g; 
}

void graph_bfs(graph g, int source){
  int i;
  int u;
  queue q = queue_new();
  for(i=0; i<g->size;i++){
    g->vertices[i].state = UNVISITED;
    g->vertices[i].distance = -1;
    g->vertices[i].pred = -1;
  }
  g->vertices[source].state = VISITED_SELF;
  g->vertices[source].distance = 0;
  enqueue(q,source);
  while(queue_size(q) >0){
    u = dequeue(q);
    for(i=0;i<g->size;i++){
      if (g->edges[u][i]==1 && g->vertices[i].state == UNVISITED){
	    g->vertices[i].state = VISITED_SELF;
	    g->vertices[i].distance = 1 + g->vertices[u].distance;
	    g->vertices[i].pred = u;
	    enqueue(q, i);
	    }
	}
    g->vertices[u].state= VISITED_DESCENDANTS;
    }
}

void visit(graph g, int v){
    int u;
    g->vertices[v].state = VISITED_SELF;
    step++;
    g->vertices[v].distance = step;
    for(u=0;u<g->size;u++){
        if(g->edges[v][u]==1 && g->vertices[u].state==UNVISITED){
            g->vertices[u].pred = v;
            visit(g,u);
        }
    }
    step++;
    g->vertices[v].state = VISITED_DESCENDANTS;
    g->vertices[v].finish = step;
    

}
void graph_dfs(graph g){
    int i;
    for(i=0; i<g->size; i++){
        g->vertices[i].state= UNVISITED;
        g->vertices[i].pred = -1;
        }
    step = 0;
    for(i = 0; i<g->size;i++){
        if(g->vertices[i].state==UNVISITED){
            visit(g,i);
        }
    }
}

void graph_print(graph g){
  int i, j;
  for(i=0;i< g->size; i++){
    printf("%d |",i);
    for (j=0;j<g->size;j++){
      if (g->edges[i][j]==1){
        printf("%d ", j);
        }
     }
     printf("\n");
     }
   printf("\n");
   printf("vertex distance pred finish\n");
   for(i=0;i< g->size; i++){
        printf("%d\t%d\t%d\t%d\n", i, g->vertices[i].distance, g->vertices[i].pred,g->vertices[i].finish);
        }
  }
  
