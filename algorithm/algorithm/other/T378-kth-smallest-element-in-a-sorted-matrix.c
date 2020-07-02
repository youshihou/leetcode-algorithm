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

int lower_count(int** matrix, int row, int col, int mid) {
    int i = row - 1;
    int j = 0;
    int count = 0;
    while (i >= 0 && j < col) {
        if (matrix[i][j] <= mid) {
            count = count + i + 1;
            j++;
        } else {
            i--;
        }
    }
    return count;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    if (matrix == NULL || matrixSize <= 0) { return -1; }
    
    int row = matrixSize;
    int col = matrixColSize[0];
    int left = matrix[0][0];
    int right = matrix[row - 1][col - 1];
    while (left < right) {
        int mid = (left + right) >> 1;
        if (lower_count(matrix, row, col, mid) < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}





int t387cmp(const void * v1, const void * v2) {
    return *(int *)v1 - *(int *)v2;
}

int kthSmallest1(int** matrix, int matrixSize, int* matrixColSize, int k) {
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
