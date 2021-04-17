//
//  T03_shu-zu-zhong-zhong-fu-de-shu-zi-lcof.c
//  algorithm
//
//  Created by Ankui on 4/17/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/


#include "T03_shu-zu-zhong-zhong-fu-de-shu-zi-lcof.h"
#include "algorithm-common.h"

int findRepeatNumber(int* nums, int numsSize) {
    int list[numsSize];
    memset(list, 0, sizeof(list));
    // [2, 3, 1, 0, 2, 5, 3]
    for (int i = 0; i < numsSize; i++) {
        list[nums[i]]++;
    }
    // [1, 1, 2, 2, 0, 1, 0]
    for (int i = 0; i < numsSize; i++) {
        if (list[i] >= 2) {
            return i;
        }
    }
    return -1;
}



int t03cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int findRepeatNumber1(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), t03cmp);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i + 1] == nums[i]) {
            return nums[i];
        }
    }
    return -1;
}
