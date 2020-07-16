//
//  T785-is-graph-bipartite.c
//  algorithm
//
//  Created by Ankui on 7/16/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/is-graph-bipartite/


#include "T785-is-graph-bipartite.h"
#include "algorithm-common.h"

bool dfs(int** graph, int* graphColSize, int node, int c, int* color) {
    color[node] = c;
    int cNei = (c == 1 ? 2 : 1);
    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (color[neighbor] == 0) {
            if (!dfs(graph, graphColSize, neighbor, cNei, color)) {
                return false;
            }
        } else if (color[neighbor] != cNei) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = malloc(sizeof(int) * graphSize);
    memset(color, 0, sizeof(int) * graphSize);
    for (int i = 0; i < graphSize; i++) {
        if (color[i] == 0) {
            if (!dfs(graph, graphColSize, i, 1, color)) {
                free(color);
                return false;
            }
        }
    }
    free(color);
    return true;
}
