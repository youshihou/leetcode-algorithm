//
//  T40-zui-xiao-de-kge-shu-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/


#include "T40-zui-xiao-de-kge-shu-lcof.h"
#include "algorithm-common.h"


int t40cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
    if (arr == NULL || arrSize <= 0) { return NULL; }
    qsort(arr, arrSize, sizeof(int), t40cmp);
    
    *returnSize = k;
    int* list = malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        list[i] = arr[i];
    }
    return list;
}
