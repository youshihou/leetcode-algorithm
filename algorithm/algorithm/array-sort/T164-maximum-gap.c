//
//  T164-maximum-gap.c
//  algorithm
//
//  Created by Ankui on 4/20/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/maximum-gap/

#include "T164-maximum-gap.h"
#include <stdlib.h>
#include <math.h>

int t164cmp(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) { return 0; }
    
    qsort(nums, numsSize, sizeof(int), t164cmp);
    
    int result = 0;
    for (int i = 1; i < numsSize; i++) {
        result = fmax(result, nums[i] - nums[i - 1]);
    }
    
    return result;
}
