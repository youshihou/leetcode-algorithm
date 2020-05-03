//
//  T47-permutations-ii.c
//  algorithm
//
//  Created by Ankui on 5/3/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/permutations-ii/

#include "T47-permutations-ii.h"
#include "depth-first-search-common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void swap2(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

bool isRepeat(int* nums, int idx, int i) {
    for (int j = idx; j < i; j++) {
        if (nums[j] == nums[i]) {
            return true;
        }
    }
    return false;
}

void dfs3(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** list, int idx) {
    if (idx == numsSize) {
        list[*returnSize] = malloc(sizeof(int) * numsSize);
        memcpy(list[*returnSize], nums, sizeof(int) * numsSize);
//        *returnColumnSizes[*returnSize] = numsSize; // ERROR!!!
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
    }
    
    for (int i = idx; i < numsSize; i++) {
        if (isRepeat(nums, idx, i)) {
            continue;
        }
        
        swap2(nums, idx, i);
        dfs3(nums, numsSize, returnSize, returnColumnSizes, list, idx + 1);
        swap2(nums, idx, i);
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
//    *returnColumnSizes[0] = 0; // ERROR!!!
    (*returnColumnSizes)[0] = 0;
    if (nums == NULL || numsSize == 0) { return NULL; }
    
    int len = 1;
    for (int i = 1; i <= numsSize; i++) {
        len *= i;
    }
    int** list = malloc(sizeof(int*) * len);
    *returnColumnSizes = malloc(sizeof(int) * len);
    
    dfs3(nums, numsSize, returnSize, returnColumnSizes, list, 0);
    
    return list;
}
