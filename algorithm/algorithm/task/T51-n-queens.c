//
//  T51-n-queens.c
//  algorithm
//
//  Created by Ankui on 5/23/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/n-queens/

#include "T51-n-queens.h"
#include "algorithm-common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


bool is_valid_(int row, int col, int* cols) {
    for (int i = 0; i < row; i++) {
        if (cols[i] == col) { return false; } // CARE!!!
        if (row - i == abs(cols[i] - col)) { return false; } // CARE!!!
    }
    return true;
}

void place_(int n, int row, int* cols, char*** result, int* returnSize) {
    if (row == n) {
        result[*returnSize] = malloc(sizeof(char*) * n); // CARE!!!
        for (int i = 0; i < n; i++) {
            result[*returnSize][i] = calloc(n + 1, sizeof(char)); // CARE!!!
            memset(result[*returnSize][i], '.', n);
            result[*returnSize][i][cols[i]] = 'Q'; // CARE!!!
        }
        (*returnSize)++;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (is_valid_(row, col, cols)) {
            cols[row] = col; // CARE!!!
            place_(n, row + 1, cols, result, returnSize);
        }
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (n < 1) { return NULL; }
    
    int* cols = calloc(n, sizeof(int));
    char*** result = malloc(sizeof(char**) * n * n * n);
    place_(n, 0, cols, result, returnSize);
    
    *returnColumnSizes = malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    return result;
}
