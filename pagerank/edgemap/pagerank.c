/*
Implementation based on:
Hong, Oguntebi, Olukotun. "Efficient Parallel Graph Exploration on Multi-Core CPU and GPU." PACT, 2011.
*/

#include "pagerank.h"

double fabs(double a){
    a > 0 ? a : -a;
}

void pagerank(node_t nodes[N_NODES], edge_t edges[N_EDGES], 
                pagerank_t pagerank_cur[N_NODES])
{
    pagerank_t pagerank_next[N_NODES];
    int curNode = 0;
    int num = 0;
    int m = 0;
    int i, dst;
    pagerank_init(pagerank_cur, pagerank_next); // initialization for the pagerank_cur and pagerank_next
    // for (int i = 0; i < N_NODES; i++){
    //     pagerank_cur[i] = 1.0 / N_NODES;
    //     pagerank_next[i] = 0;
    // }
    while (m < max_iter){
        for (i = 0; i < N_EDGES; i++){
            while (i == nodes[curNode].edge_end){
                curNode++;
            }
            dst = edges[i].dst;
            pagerank_next[dst] += pagerank_cur[curNode]/(nodes[curNode].edge_end - nodes[curNode].edge_begin);
        }
        for (i = 0; i < N_NODES; i++){
            pagerank_next[i] = pagerank_next[i]*dp_ratio + constant;
        }
        for (i = 0; i < N_NODES; i++){
            if (fabs(pagerank_next[i] - pagerank_cur[i]) > eps){
                num++;
            }
        }
        if (num > 0){
            for (i = 0; i < N_NODES; i++){
                pagerank_cur[i] = pagerank_next[i];
                pagerank_next[i] = 0;
            }
            num = 0;
            curNode = 0;
        }else{
            break;
        }
        m++;
    }
    // for(int i = 0; i < N_NODES; i++){
    //     printf("%f\n",pagerank_cur[i]);
    // }
}
