//
//  T378-kth-smallest-element-in-a-sorted-matrix.c
//  algorithm
//
//  Created by Ankui on 7/2/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include "T378-kth-smallest-element-in-a-sorted-matrix.h"
#include "algorithm-common.h"



int t387cmp(const void * v1, const void * v2) {
    return *(int *)v1 - *(int *)v2;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    if (matrix == NULL || matrixColSize == NULL || matrixSize <= 0 || k <= 0) {
        return -1;
    }
    
    int *list = malloc(sizeof(int) * matrixSize * (*matrixColSize));
    int num = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            list[num++] = matrix[i][j];
        }
    }
    
    qsort(list, num, sizeof(int), t387cmp);
    
    return list[k - 1];
}
