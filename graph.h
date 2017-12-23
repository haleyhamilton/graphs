#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>

typedef struct graphrec *graph;
typedef struct vertex vertex;
/* 
   function: graph_free
   description: frees all memory allocated for graph, edges, and vertices
   parameters: graph g - the graph to free 
   returns: void 
*/
extern void   graph_free(graph g);
/* 
   function: graph_add_edge
   description: creates an edge between vertices by putting a 1 in the edges matrix
   parameters: graph g - the graph to connect
               int a   - the start vertex
               int b   - the end vertex
               int directional - 0 if not directed, 1 if directional 
   returns: void 
*/

extern graph  graph_add_edge(graph g,int a, int b, int directional);

/* 
   function: graph_new
   description: allocates memory for graph and initialized edges and vertices
   parameters: int size - number of vertices
   returns: graph result - new graph
*/
extern graph  graph_new(int size);
/* 
   function: graph_print
   description: prints each vertex and all of the vertices adjacent to it. Prints each vertex and its distance, pred, and finish
   parameters: graph g - the graph print
   returns: void 
*/
extern void   graph_print(graph g);
/* 
   function: graph_bfs
   description: uses breadth first search to access the shortest distance from the source to each vertices and stores info in each vertex
   parameters: graph g - the graph to search
               int source- the source vertx
   returns: void 
*/
extern void   graph_bfs(graph g, int source);
/* 
   function: graph_dfs
   description: uses depth first search to access and store the shortest path between vertices
   parameters: graph g - the graph to acess
   returns: void 
*/
extern void   graph_dfs(graph g);
#endif
