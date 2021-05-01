//
//  T268-missing-number.c
//  algorithm
//
//  Created by Ankui on 5/1/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/missing-number/



#include "T268-missing-number.h"
#include "algorithm-common.h"


int missingNumber(int* nums, int numsSize) {
    int result = numsSize;
    for (int i = 0; i < numsSize; i++) {
        result = result ^ nums[i] ^ i;
    }
    return result;
}




int __missingNumber(int* nums, int numsSize) {
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum += nums[i];
    }
    
//    int total = (numsSize * (numsSize + 1)) >> 1;
//    return total - sum;
    
    sum = ((numsSize * (numsSize + 1)) >> 1) - sum;
    return sum;
}



int t268_cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int _missingNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), t268_cmp);
    if (nums[0] != 0) {
        return 0;
    } else if (nums[numsSize - 1] != numsSize) {
        return numsSize;
    }
    
    for (int i = 1; i < numsSize; i++) {
        int target = nums[i - 1] + 1;
        if (nums[i] != target) {
            return target;
        }
    }
    return -1;
}
