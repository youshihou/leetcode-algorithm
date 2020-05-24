//
//  T300-longest-increasing-subsequence.c
//  algorithm
//
//  Created by Ankui on 5/24/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/longest-increasing-subsequence/

#include "T300-longest-increasing-subsequence.h"
#include "algorithm-common.h"


int lengthOfLIS(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    int dp[numsSize];
    dp[0] = 1;
    int max = dp[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = 1; // CARE!!!
        for (int j = 0; j < i; j++) {
            if (nums[i] <= nums[j]) { continue; }
            dp[i] = MAX(dp[i], dp[j] + 1);
        }
        
//        if (dp[i] <= dp[i - 1]) { // ERROE!!!
//            dp[i] = 1;
//        } else {
//            dp[i] = MAX(max, dp[i - 1] + 1);
//        }
        
        max = MAX(max, dp[i]);
    }
    
    return max;
}
