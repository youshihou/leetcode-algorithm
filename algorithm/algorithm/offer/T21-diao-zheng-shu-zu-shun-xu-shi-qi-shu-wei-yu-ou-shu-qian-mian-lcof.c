//
//  T21-diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/

#include "T21-diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof.h"
#include "algorithm-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL) { return NULL; }
    
    *returnSize = numsSize;
    int fast = 0, low = 0;
    while (fast < numsSize) {
        if (nums[fast] & 1) {
            int tmp = nums[low];
            nums[low] = nums[fast];
            nums[fast] = tmp;
            low++;
        }
        fast++;
    }
    return nums;
}


int* exchange1(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL) { return NULL; }
    
    *returnSize = numsSize;
    int* result = malloc(sizeof(int) * numsSize);
    int left = 0;
    int right = numsSize - 1;
    int v = 0;
    for (int i = 0; i < numsSize; i++) {
        v = nums[i];
        if ((v & 1) == 1) {
//        if (v % 2) {
            result[left++] = v;
        } else {
            result[right--] = v;
        }
    }
    return result;
}
