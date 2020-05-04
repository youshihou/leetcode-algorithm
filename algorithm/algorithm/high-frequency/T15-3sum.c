//
//  T15-3sum.c
//  algorithm
//
//  Created by Ankui on 5/4/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/3sum/

#include "T15-3sum.h"
#include "high-frequency-common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void * a, const void * b) {
    return *((int*)a) - *((int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = 0;
    if (nums == NULL || numsSize < 3) { return NULL; }
    
    int len = (numsSize * (numsSize - 1)) >> 1;
    int** list = malloc(sizeof(int*) * len);
    *returnColumnSizes = malloc(sizeof(int) * len);
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    int last = numsSize - 3;
    int lastR = numsSize - 1;
    for (int i = 0; i <= last; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) { continue; }
        
        int l = i + 1;
        int r = lastR;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                list[*returnSize] = malloc(sizeof(int) * 3);
                list[*returnSize][0] = nums[i];
                list[*returnSize][1] = nums[l];
                list[*returnSize][2] = nums[r];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                
                while (l < r && nums[l] == nums[l + 1]) {
                    l++;
                }
                while (l < r && nums[r] == nums[r - 1]) {
                    r--;
                }
                
                l++;
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
    }

    return list;
}
