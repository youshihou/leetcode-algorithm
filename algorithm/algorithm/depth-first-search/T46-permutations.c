//
//  T46-permutations.c
//  algorithm
//
//  Created by Ankui on 5/3/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/permutations/

#include "T46-permutations.h"
#include "algorithm-common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void swap1(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void dfs2(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** list, int idx) {
    if (idx == numsSize) {
        list[*returnSize] = malloc(sizeof(int) * numsSize);
        memcpy(list[*returnSize], nums, sizeof(int) * numsSize);
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = idx; i < numsSize; i++) {
        swap1(nums, idx, i);
        dfs2(nums, numsSize, returnSize, returnColumnSizes, list, idx + 1);
        swap1(nums, idx, i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    (*returnColumnSizes)[0] = 0;
    if (nums == NULL || numsSize == 0) { return NULL; }
        
    int len = 1;
    for (int i = 1; i <= numsSize; i++) {
        len *= i;
    }
    int** list = malloc(sizeof(int *) * len);
    memset(list, 0, sizeof(int *) * len);
    *returnColumnSizes = malloc(sizeof(int) * len);

    dfs2(nums, numsSize, returnSize, returnColumnSizes, list, 0);
    
    return list;
}


void dfs1(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, bool* used, int* array, int** list, int idx) {
    if (idx == numsSize) {
        list[*returnSize] = malloc(sizeof(int) * numsSize);
        memcpy(list[*returnSize], array, sizeof(int) *numsSize);
        (*returnColumnSizes)[*returnSize] = numsSize; // CARE!!!
//        **returnColumnSizes = numsSize; // ERROR!!!
        (*returnSize)++;
        // (**returnColumnSizes)++; // ERROR!!!
        return;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        array[idx] = nums[i];
        used[i] = true;
        dfs1(nums, numsSize, returnSize, returnColumnSizes, used, array, list, idx + 1);
        used[i] = false;
    }
}

int** permute1(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
//    **returnColumnSizes = 0;
    (*returnColumnSizes)[0] = 0;
    if (nums == NULL || numsSize == 0) { return NULL; }
    
    int* array = malloc(sizeof(int) * numsSize);
    memset(array, 0, sizeof(int) * numsSize);
    bool* used = malloc(sizeof(bool) * numsSize);
    memset(used, false, sizeof(bool) * numsSize);
    
    int len = 1;
    for (int i = 1; i <= numsSize; i++) {
        len *= i;
    }
    int** list = malloc(sizeof(int *) * len);
    memset(list, 0, sizeof(int *) * len);
    *returnColumnSizes = malloc(sizeof(int) * len);

    dfs1(nums, numsSize, returnSize, returnColumnSizes, used, array, list, 0);
    
    return list;
}
