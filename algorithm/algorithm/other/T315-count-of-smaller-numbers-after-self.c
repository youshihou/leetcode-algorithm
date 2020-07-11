//
//  T315-count-of-smaller-numbers-after-self.c
//  algorithm
//
//  Created by Ankui on 7/11/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/


#include "T315-count-of-smaller-numbers-after-self.h"
#include "algorithm-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (nums == NULL || numsSize <= 0) { return NULL; }
    
    int *result = malloc(sizeof(int) * numsSize);
    memset(result, 0, sizeof(int) * numsSize);
    int *list = malloc(sizeof(int) * numsSize);
    memset(list, 0, sizeof(int) * numsSize);
    
    int sortIndex = 0;
    list[sortIndex] = nums[numsSize - 1];
    int j = 0;
    
    for (int i = numsSize - 2; i >= 0; i--) {
        j = sortIndex;
        while (j >= 0 && nums[i] <= list[j]) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = nums[i];
        sortIndex++;
        result[i] = j + 1;
    }
    
    return result;
}
