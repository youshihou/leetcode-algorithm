//
//  T315-count-of-smaller-numbers-after-self.c
//  algorithm
//
//  Created by Ankui on 5/6/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/

#include "T315-count-of-smaller-numbers-after-self.h"
#include "high-frequency-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    if (nums == NULL || numsSize == 0) { return NULL; }
    
    int *list = malloc(sizeof(int) * numsSize);
    memset(list, 0, sizeof(int) * numsSize);
    
    
    
    return list;
}
