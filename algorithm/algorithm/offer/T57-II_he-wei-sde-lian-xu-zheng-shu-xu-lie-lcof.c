//
//  T57-II_he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/


#include "T57-II_he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof.h"
#include "algorithm-common.h"


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes) {
    int size = 100000;
    int** result = malloc(sizeof(int*) * size);
    int sum = 0;
    int l = 1, r = 1;
    int idx = 0;
    *returnColumnSizes = malloc(sizeof(int) * size);
    *returnSize = 0;
    
    while (r < target) {
        sum += r;
        if (sum > target) {
            while (sum > target) {
                sum -= l;
                l++;
            }
        }
        
        if (sum == target) {
            idx = 0;
            result[*returnSize] = malloc(sizeof(int) * (r - l + 1));
            for (int j = l; j <= r; j++) {
                result[*returnSize][idx++] = j;
            }
            (*returnColumnSizes)[*returnSize] = r - l + 1;
            (*returnSize)++;
        }
        r++;
    }
    return result;
}

int** findContinuousSequence1(int target, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(sizeof(int*) * target);
    int* col = malloc(sizeof(int) * target);
    int i = 1, m = 0, t = target;
    while (t - i >= 0) {
        t -= i++;
    }
    
    while (t < target && i > 2) {
        t += --i;
        if (t % i == 0) {
            col[m] = i;
            result[m] = malloc(sizeof(int) * i);
            for (int k = t / i, j = 0; k < t / i + i; k++, j++) {
                result[m][j] = k;
            }
            m++;
        }
    }
    *returnSize = m;
    *returnColumnSizes = col;
    return result;
}
