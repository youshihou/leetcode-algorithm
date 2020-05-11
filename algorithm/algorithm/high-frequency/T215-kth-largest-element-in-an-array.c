//
//  T215-kth-largest-element-in-an-array.c
//  algorithm
//
//  Created by Ankui on 5/6/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

#include "T215-kth-largest-element-in-an-array.h"
#include "algorithm-common.h"

int t215compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}


int findKthLargest(int* nums, int numsSize, int k) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    qsort(nums, numsSize, sizeof(int), t215compare);
    
    return nums[numsSize - k];
}
