//
//  T674-longest-continuous-increasing-subsequence.c
//  algorithm
//
//  Created by Ankui on 5/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/

#include "T674-longest-continuous-increasing-subsequence.h"
#include "algorithm-common.h"

int findLengthOfLCIS(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    int maxLen = 0;
    int start = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] <= nums[i-1]) {
            start = i;
        }
        maxLen = fmax(maxLen, i - start + 1);
    }
    
    return maxLen;
}
