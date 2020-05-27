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
    
    int len = 0;
    int top[numsSize];
    memset(top, 0, sizeof(top));
    
    for (int i = 0; i < numsSize; i++) {
        int begin = 0;
        int end = len;
        while (begin < end) {
            int mid = (begin + end) >> 1;
            if (nums[i] <= top[mid]) { // CARE!!! is top[mid] not nums[mid], nums[i] <= top[mid]
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        top[begin] = nums[i];
        if (begin == len) {
            len++;
        }
    }
    
    return len;
}






int lengthOfLIS2(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    int len = 0;
    int top[numsSize];
    memset(top, 0, sizeof(top));
    
    for (int i = 0; i < numsSize; i++) {
        int j = 0;
        while (j < len) { // CARE!!! j < len
            if (top[j] >= nums[i]) {
                top[j] = nums[i];
                break;
            }
            j++;
        }
        if (j == len) {
            top[j] = nums[i]; // CARE!!!
            len++;
        }
    }
    
    return len;
}




int lengthOfLIS1(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    int dp[numsSize];
    dp[0] = 1;
    int max = dp[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = 1; // CARE!!!
        for (int j = 0; j < i; j++) { // CARE!!! j < i
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
