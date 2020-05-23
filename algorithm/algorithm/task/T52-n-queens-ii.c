//
//  T52-n-queens-ii.c
//  algorithm
//
//  Created by Ankui on 5/23/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/n-queens-ii/

#include "T52-n-queens-ii.h"
#include "algorithm-common.h"

bool is_valid(int row, int col, int* cols) {
    for (int i = 0; i < row; i++) {
        if (cols[i] == col) { return false; }
        if (row - i == abs(col - cols[i])) { return false; }
    }
    
    return true;
}


void place(int n, int row, int* cols, int* count) {
    if (row == n) {
        (*count)++;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (is_valid(row, col, cols)) {
            cols[row] = col;
            place(n, row + 1, cols, count);
        }
    }
}

int totalNQueens(int n) {
    if (n < 1) { return 1; }
    
    int* cols = malloc(sizeof(int) * n);
    memset(cols, 0, sizeof(int) * n);
    int count = 0;
    
    place(n, 0, cols, &count);
    
    return count;
}
