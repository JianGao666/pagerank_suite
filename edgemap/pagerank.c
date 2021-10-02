/*
Implementation based on:
Hong, Oguntebi, Olukotun. "Efficient Parallel Graph Exploration on Multi-Core CPU and GPU." PACT, 2011.
*/
int brc_cnt = 0;
int mem_cnt = 0;
int com_cnt = 0;
int sum = 0;

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
    pagerank_init(pagerank_cur, pagerank_next); // initialization for the pagerank_cur and pagerank_next
    // for (int i = 0; i < N_NODES; i++){
    //     pagerank_cur[i] = 1.0 / N_NODES;
    //     pagerank_next[i] = 0;
    // }
    while (m < max_iter){
        for (int i = 0; i < N_EDGES; i++){
            while (i == nodes[curNode].edge_end){
                com_cnt++;
                mem_cnt++;
                curNode++;
            }
            brc_cnt++;
            mem_cnt++;
            int dst = edges[i].dst;
            com_cnt++;
            com_cnt++;
            com_cnt++;
            mem_cnt++;
            mem_cnt++;
            mem_cnt++;
            mem_cnt++;
            pagerank_next[dst] += pagerank_cur[curNode]/(nodes[curNode].edge_end - nodes[curNode].edge_begin);
        }
        brc_cnt++;
        for (int i = 0; i < N_NODES; i++){
            com_cnt++;
            com_cnt++;
            mem_cnt++;
            mem_cnt++;
            pagerank_next[i] = pagerank_next[i]*dp_ratio + constant;
        }
        brc_cnt++;
        for (int i = 0; i < N_NODES; i++){
            com_cnt++;
            com_cnt++;
            mem_cnt++;
            mem_cnt++;
            if (fabs(pagerank_next[i] - pagerank_cur[i]) > eps){
                com_cnt++;
                num++;
            }
        }
        brc_cnt++;
        if (num > 0){
            for (int i = 0; i < N_NODES; i++){
                pagerank_cur[i] = pagerank_next[i];
                pagerank_next[i] = 0;
            }
            brc_cnt++;
            num = 0;
            curNode = 0;
        }else{
            brc_cnt++;
            break;
        }
        m++;
    }
    // for(int i = 0; i < N_NODES; i++){
    //     printf("%f\n",pagerank_cur[i]);
    // }
    sum = brc_cnt + mem_cnt + com_cnt;
    printf("brc %f, mem %f, com %f\n", brc_cnt*1.0/sum,mem_cnt*1.0/sum,com_cnt*1.0/sum);
}
