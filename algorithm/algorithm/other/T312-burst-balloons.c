//
//  T312-burst-balloons.c
//  algorithm
//
//  Created by Ankui on 7/19/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/burst-balloons/


#include "T312-burst-balloons.h"
#include "algorithm-common.h"

int maxCoins(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    int value[numsSize + 2];
    size_t n = sizeof(value) / sizeof(value[0]);
    value[0] = value[n - 1] = 1;
    memcpy(&value[1], nums, sizeof(int) * numsSize);
    
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    for (int s = 2; s < n; s++) {
        for (int i = 0; i < n - s; i++) {
            int j = i + s;
            for (int k = i + 1; k < j; k++) {
                int t = dp[i][k] + dp[k][j] + value[i] * value[k] * value[j];
//                if (dp[i][j] < t) {
//                    dp[i][j] = t;
//                }
                dp[i][j] = fmax(dp[i][j], t);
            }
        }
    }
    
    return dp[0][n - 1];
}




int maxCoins1(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    int dp[numsSize + 2][numsSize + 2];
    memset(dp, 0, sizeof(dp));
    
    int value[numsSize + 2];
    value[0] = value[numsSize + 1] = 1;
    for (int i = 1; i <= numsSize; i++) {
        value[i] = nums[i - 1];
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        for (int j = i + 2; j <= numsSize + 1; j++) {
            for (int k = i + 1; k < j; k++) {
                int sum = value[i] * value[k] * value[j];
                sum += dp[i][k] + dp[k][j];
                dp[i][j] = fmax(dp[i][j], sum);
            }
        }
    }

    return dp[0][numsSize + 1];
}
