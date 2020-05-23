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

void place(int n, int row, int* count, bool* cols, bool* leftTop, bool* rightTop) {
    if (row == n) {
        (*count)++;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (cols[col]) { continue; }
        int leftIdx = row - col + n - 1; // CARE!!!
        if (leftTop[leftIdx]) { continue; }
        int rightIdx = row + col; // CARE!!!
        if (rightTop[rightIdx]) { continue; }
        
        cols[col] = true;
        leftTop[leftIdx] = true;
        rightTop[rightIdx] = true;
        place(n, row + 1, count, cols, leftTop, rightTop);
        
        cols[col] = false; // CARE!!! back tracking
        leftTop[leftIdx] = false;
        rightTop[rightIdx] = false;
    }
}

int totalNQueens(int n) {
    if (n < 1) { return n; }
    
    int count = 0;
    int size = (n << 1) - 1;
    
    bool* cols = calloc(n, sizeof(bool));
    memset(cols, false, sizeof(bool) * n);
    bool* left_top = calloc(size, sizeof(bool));
    memset(left_top, false, sizeof(bool) * size);
    bool* right_top = calloc(size, sizeof(bool));
    memset(right_top, false, sizeof(bool) * size);
    
    place(n, 0, &count, cols, left_top, right_top);
    
    free(cols);
    free(left_top);
    free(right_top);
    
    return count;
}






bool is_valid(int row, int col, int* cols) {
    for (int i = 0; i < row; i++) {
        if (cols[i] == col) { return false; }
        if (row - i == abs(col - cols[i])) { return false; }
    }
    
    return true;
}

void place1(int n, int row, int* cols, int* count) {
    if (row == n) {
        (*count)++;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (is_valid(row, col, cols)) {
            cols[row] = col;
            place1(n, row + 1, cols, count);
        }
    }
}

int totalNQueens1(int n) {
    if (n < 1) { return 1; }
    
    int* cols = malloc(sizeof(int) * n);
    memset(cols, 0, sizeof(int) * n);
    int count = 0;
    
    place1(n, 0, cols, &count);
    
    free(cols);
    return count;
}
