/*
Implementation based on:
Hong, Oguntebi, Olukotun. "Efficient Parallel Graph Exploration on Multi-Core CPU and GPU." PACT, 2011.
*/

#include "pagerank.h"
// float absolute value
double fabs(double a){
    return a > 0 ? a : -a;
}

void pagerank(node_t nodes[N_NODES], edge_t edges[N_EDGES], 
                pagerank_t pagerank_cur[N_NODES])
{   
    pagerank_t pagerank_next[N_NODES];
    int num = 0; // record the number of the nodes's page rank value difference that is larger than eps
    int m = 0; // iteration number
    int i, j, dis_node;
    pagerank_init(pagerank_cur, pagerank_next); // initialization for the pagerank_cur and pagerank_next
    // for (int i = 0; i < N_NODES; i++){
    //     pagerank_cur[i] = 1.0 / N_NODES;
    //     pagerank_next[i] = 0;
    // }
    // for (int i = 0; i < N_NODES; i++){
    //     printf("%lf\n", pagerank_cur[i]);
    // }
    while (m < max_iter){
        for (i = 0; i < N_NODES; i++){
            for (j = nodes[i].edge_begin; j < nodes[i].edge_end; j++){
                dis_node = edges[j].dst;
                pagerank_next[dis_node] += pagerank_cur[i]/(nodes[i].edge_end - nodes[i].edge_begin);
            }
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
        }else{
            break;
        }
        m++;
    }
    // for(int i = 0; i < N_NODES; i++){
    //     printf("%f\n",pagerank_cur[i]);
    // }
}
