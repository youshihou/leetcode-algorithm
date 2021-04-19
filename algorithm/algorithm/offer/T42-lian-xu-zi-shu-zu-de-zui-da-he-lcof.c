//
//  T42-lian-xu-zi-shu-zu-de-zui-da-he-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/


#include "T42-lian-xu-zi-shu-zu-de-zui-da-he-lcof.h"
#include "algorithm-common.h"


int maxSubArray(int* nums, int numsSize) {
    int result = nums[0];
    for (int i = 1; i < numsSize; i++) {
        nums[i] += fmax(nums[i-1], 0);
        result = fmax(result, nums[i]);
    }
    return result;
}
