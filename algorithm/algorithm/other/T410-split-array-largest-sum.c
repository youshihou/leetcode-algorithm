//
//  T410-split-array-largest-sum.c
//  algorithm
//
//  Created by Ankui on 7/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/split-array-largest-sum/


#include "T410-split-array-largest-sum.h"
#include "algorithm-common.h"


int splitArray(int* nums, int numsSize, int m) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    long long dp[numsSize + 1][m + 1];
    memset(dp, 0x3f, sizeof(dp));
    long long list[numsSize + 1];
    memset(list, 0, sizeof(list));
    for (int i = 0; i < numsSize; i++) {
        list[i + 1] = list[i] + nums[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= numsSize; i++) {
        for (int j = 1; j <= fmin(i, m); j++) {
            for (int k = 0; k < i; k++) {
                dp[i][j] = fmin(dp[i][j], fmax(dp[k][j - 1], list[i] - list[k]));
            }
        }
    }

    return (int)dp[numsSize][m];
}
