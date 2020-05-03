//
//  T39-combination-sum.c
//  algorithm
//
//  Created by Ankui on 5/3/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/combination-sum/

#include "T39-combination-sum.h"
#include "depth-first-search-common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int* array, int** list, int idx, int start) {
    if (target == 0) {
        list[*returnSize] = malloc(sizeof(int) * idx);
        memcpy(list[*returnSize], array, sizeof(int) * idx);
        (*returnColumnSizes)[*returnSize] = idx;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) { // CARE!!!  i = start not i = idx
        // if (target < candidates[i]) return; // ERROR!!!
       if (candidates[i] > target) continue;
        array[idx] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], returnSize, returnColumnSizes, array, list, idx + 1, i); 
        array[idx] = 0; // CARE!!!
    }

}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = 0;
    if (candidates == NULL || candidatesSize <= 0) { return NULL; }
    
    int len = 1024;
    int** list = malloc(sizeof(int*) * len);
    memset(list, 0, sizeof(int*) * len);
    *returnColumnSizes = malloc(sizeof(int) * len);
    
    int* array = malloc(sizeof(int) * target);
    memset(array, 0, sizeof(int) * target);
        
    dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, array, list, 0, 0);
    
    return list;
}




void dfs111(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int* array, int arraySize, int** list, int idx) {
    for (int i = idx; i < candidatesSize; i++) {
        int m = candidates[i];
        int mSize = arraySize + 1;
        int* mArray = malloc(sizeof(int) * mSize);
        if (array && mArray) {
            memcpy(mArray, array, sizeof(int) * (mSize - 1));
        }
        mArray[mSize - 1] = m;
        
        if (candidates[i] < target) {
            dfs111(candidates, candidatesSize, target - m, returnSize, returnColumnSizes, mArray, mSize, list, i);
        }
        else if (candidates[i] == target) {
            list[*returnSize] = mArray;
            (*returnColumnSizes)[*returnSize] = mSize;
            (*returnSize)++;
        }
    }
}

int** combinationSum1(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = 0;
    if (candidates == NULL || candidatesSize <= 0) { return NULL; }
    
    int len = 1024;
    int** list = malloc(sizeof(int*) * len);
    memset(list, 0, sizeof(int*) * len);
    *returnColumnSizes = malloc(sizeof(int) * len);
    
    int* array = malloc(sizeof(int) * target);
    memset(array, 0, sizeof(int) * target);
    
    int arraySize = 0;

    dfs111(candidates, candidatesSize, target, returnSize, returnColumnSizes, array, arraySize, list, 0);
    
    return list;
}
