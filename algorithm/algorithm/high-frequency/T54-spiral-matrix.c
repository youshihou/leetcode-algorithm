//
//  T54-spiral-matrix.c
//  algorithm
//
//  Created by Ankui on 5/4/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/spiral-matrix/

#include "T54-spiral-matrix.h"
#include "algorithm-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = 0;
    if (matrix == NULL || matrixSize <= 0 || *matrixColSize <= 0) { return NULL; }
    
    int* list = malloc(sizeof(int) * (matrixSize * (*matrixColSize)));

    int top = 0;
    int right = *matrixColSize - 1;
    int left = 0;
    int bottom = matrixSize - 1;
    
    while (top <= bottom && left <= right) {
        // left top  -> right top
        for (int i = left; i <= right; i++) {
            list[*returnSize] = matrix[top][i];
            (*returnSize)++;
        }
        top++;
//        if (top > bottom) break; // CARE!!!

        // right top -> right bottom
        for (int i = top; i <= bottom; i++) {
            list[*returnSize] = matrix[i][right];
            (*returnSize)++;
        }
        right--;
//        if (left > right) break; // CARE!!!
        
        if (top > bottom || left > right) {
            break;
        }
         
        // right bottom -> left bottom
        for (int i = right; i >= left; i--) {
            list[*returnSize] = matrix[bottom][i];
            (*returnSize)++;
        }
        bottom--;
        // left bottom -> left top
        for (int i = bottom; i >= top; i--) {
            list[*returnSize] = matrix[i][left];
            (*returnSize)++;
        }
        left++;
    }
        
    return list;

}
