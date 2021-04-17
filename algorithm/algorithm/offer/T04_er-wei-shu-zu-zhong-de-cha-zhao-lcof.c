//
//  T04_er-wei-shu-zu-zhong-de-cha-zhao-lcof.c
//  algorithm
//
//  Created by Ankui on 4/17/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/


#include "T04_er-wei-shu-zu-zhong-de-cha-zhao-lcof.h"
#include "algorithm-common.h"


bool binary_search(int* nums, int size, int target) {
    if (nums == NULL || size <= 0) { return false; }
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrix == NULL || matrixSize <= 0 || *matrixColSize <= 0) { return false; }
    for (int i = 0; i < matrixSize; i++) {
        if (binary_search(matrix[i], matrixColSize[i], target)) {
            return true;
        }
    }
    return false;
}



bool findNumberIn2DArray1(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrix == NULL || matrixSize <= 0 || *matrixColSize <= 0) { return false; }
    
    int i = 0;
    int j = *matrixColSize - 1;
    while (i < matrixSize && j >= 0) {
        int cur = matrix[i][j];
        if (cur == target) {
            return true;
        } else if (cur < target) {
            i++;
        } else {
            j--;
        }
    }
    
    return false;
}
