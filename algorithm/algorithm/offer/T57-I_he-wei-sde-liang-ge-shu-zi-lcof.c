//
//  T57-I_he-wei-sde-liang-ge-shu-zi-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/


#include "T57-I_he-wei-sde-liang-ge-shu-zi-lcof.h"
#include "algorithm-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int __binary_search(int* nums, int l, int r, int value) {
    while (l < r) {
        int m = l + ((r - l) >> 1);
        if (nums[m] > value) {
            r = m;
        } else if (nums[m] < value) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* list = malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        list[0] = nums[i];
        int sub = target - nums[i];
        int j = __binary_search(nums, i+1, numsSize, sub);
        if (j) {
            list[1] = nums[j];
            break;
        }
    }
    return list;
}

int* __twoSum1(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* list = malloc(sizeof(int) * 2);
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int s = nums[l] + nums[r];
        if (s < target) {
            l++;
        } else if (s > target) {
            r--;
        } else {
            list[0] = nums[l];
            list[1] = nums[r];
            break;
        }
    }
    return list;
}
