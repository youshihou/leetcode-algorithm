//
//  T1030-matrix-cells-in-distance-order.c
//  algorithm
//
//  Created by Ankui on 5/5/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/matrix-cells-in-distance-order/


#include "T1030-matrix-cells-in-distance-order.h"
#include "algorithm-common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int R0, C0;

int t1030_cmp(const void* a, const void* b) {
    int* _a = *(int**)a;
    int* _b = *(int**)b;
    return abs(_a[0] - R0) + abs(_a[1] - C0) - abs(_b[0] - R0) - abs(_b[1] - C0);
}


int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes) {
    R0 = r0;
    C0 = c0;
    int** ret = malloc(sizeof(int*) * R * C);
    *returnColumnSizes = malloc(sizeof(int) * R * C);
    for (int i = 0; i < R * C; i++) {
        (*returnColumnSizes)[i] = 2;
        ret[i] = malloc(sizeof(int) * 2);
    }
    *returnSize = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ret[*returnSize][0] = i;
            ret[*returnSize][1] = j;
            (*returnSize)++;
        }
    }
    qsort(ret, R * C, sizeof(int*), t1030_cmp);
    return ret;
}
