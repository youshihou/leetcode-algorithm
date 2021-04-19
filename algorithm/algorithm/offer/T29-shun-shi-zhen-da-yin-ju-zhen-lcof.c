//
//  T29-shun-shi-zhen-da-yin-ju-zhen-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/


#include "T29-shun-shi-zhen-da-yin-ju-zhen-lcof.h"
#include "algorithm-common.h"


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = 0;
    if (matrix == NULL || matrixSize <= 0 || *matrixColSize <= 0) { return NULL; }
    
    int* list = malloc(sizeof(int) * matrixSize * (*matrixColSize));
    int top = 0;
    int right = *matrixColSize - 1;
    int left = 0;
    int bottom = matrixSize - 1;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            list[*returnSize] = matrix[top][i];
            (*returnSize)++;
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            list[*returnSize] = matrix[i][right];
            (*returnSize)++;
        }
        right--;
        
        if (top > bottom || left > right) {
            break;
        }
        
        for (int i = right; i >= left; i--) {
            list[*returnSize] = matrix[bottom][i];
            (*returnSize)++;
        }
        bottom--;
        
        for (int i = bottom; i >= top; i--) {
            list[*returnSize] = matrix[i][left];
            (*returnSize)++;
        }
        left++;
    }
    
    return list;
}
