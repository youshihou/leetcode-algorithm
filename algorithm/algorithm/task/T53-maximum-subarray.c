//
//  T53-maximum-subarray.c
//  algorithm
//
//  Created by Ankui on 5/23/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/maximum-subarray/

#include "T53-maximum-subarray.h"
#include "algorithm-common.h"


int maxSubArray(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    int max = INT_MIN;
    for (int begin = 0; begin < numsSize; begin++) {
        int sum = 0;
        for (int end = begin; end < numsSize; end++) {
            sum += nums[end];
            max = MAX(max, sum);
        }
    }
    
    return max;
}


int maxSubArray1(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    int max = INT_MIN;
    for (int begin = 0; begin < numsSize; begin++) {
        for (int end = begin; end < numsSize; end++) {
            int sum = 0;
            for (int i = begin; i <= end; i++) {
                sum += nums[i];
            }
            max = MAX(max, sum);
        }
    }
    
    return max;
}
