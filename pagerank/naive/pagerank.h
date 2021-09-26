/*
Implementation based on:
Hong, Oguntebi, Olukotun. "Efficient Parallel Graph Exploration on Multi-Core CPU and GPU." PACT, 2011.
*/

#include <stdlib.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include "../../common/support.h"

// Terminology (but not values) from graph500 spec
//   graph density = 2^-(2*SCALE - EDGE_FACTOR)
#define SCALE 8
#define EDGE_FACTOR 50

#define N_NODES (1<<SCALE)
#define N_EDGES (N_NODES*EDGE_FACTOR)

#define eps 0.0001
#define max_iter 10000
#define dp_ratio 0.85
#define constant (1 - dp_ratio)/N_NODES

// Larger than necessary for small graphs, but appropriate for large ones
typedef uint64_t edge_index_t;
typedef uint64_t node_index_t;
typedef double pagerank_index_t;

typedef struct edge_t_struct {
  // These fields are common in practice, but we elect not to use them.
  //weight_t weight;
  //node_index_t src;
  node_index_t dst;
} edge_t;

typedef struct node_t_struct {
  edge_index_t edge_begin;
  edge_index_t edge_end;
} node_t;

#define pagerank_t pagerank_index_t

////////////////////////////////////////////////////////////////////////////////
// Test harness interface code.

struct bench_args_t {
  node_t nodes[N_NODES];
  edge_t edges[N_EDGES];
  pagerank_t pagerank_cur[N_NODES];
  pagerank_t pagerank_next[N_NODES];
};

void pagerank_init(pagerank_t pagerank_cur[N_NODES], pagerank_t pagerank_next[N_NODES]);
void pagerank(node_t nodes[N_NODES], edge_t edges[N_EDGES], pagerank_t pagerank_cur[N_NODES]);
double fabs(double a);
