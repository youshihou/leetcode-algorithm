//
//  T61-bu-ke-pai-zhong-de-shun-zi-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/


#include "T61-bu-ke-pai-zhong-de-shun-zi-lcof.h"
#include "algorithm-common.h"


int t61cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

bool isStraight(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return false; }
    
    int s = 0;
    qsort(nums, numsSize, sizeof(int), t61cmp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == 0) {
            s++;
        } else if (nums[i] == nums[i + 1]) {
            return false;
        }
    }
    
    return nums[numsSize - 1] - nums[s] < 5;
}
