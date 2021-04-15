//
//  T239-sliding-window-maximum.c
//  algorithm
//
//  Created by Ankui on 4/24/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/sliding-window-maximum/

#include "T239-sliding-window-maximum.h"
#include "algorithm-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (nums == NULL || numsSize == 0 || k < 1) { return NULL; }
    *returnSize = numsSize - (k - 1);
    if (k == 1) { return nums; }
    
    int* result = (int* )malloc(sizeof(int) * (*returnSize));
        
    int maxIndex = 0;
    for (int i = 1; i < k; i++) { // CARE i < k
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }
    
    // li is the left index
    for (int li = 0; li < *returnSize; li++) {
        // ri is the right index
        int ri = li + k - 1;
        if (nums[ri] >= nums[maxIndex]) {
            maxIndex = ri;
        } else if (maxIndex < li) {
            maxIndex = li;
            for (int i = li + 1; i <= ri; i++) {  // CARE!!! i <= ri
                if (nums[i] > nums[maxIndex]) {
                    maxIndex = i;
                }
            }
        }
        
        result[li] = nums[maxIndex];
    }
    
    return result;
}
