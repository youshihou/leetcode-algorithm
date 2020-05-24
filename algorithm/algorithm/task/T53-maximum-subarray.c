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

    int dp = nums[0];
    int max = dp;
    for (int i = 1; i < numsSize; i++) {
        if (dp <= 0) {
            dp = nums[i];
        } else {
            dp += nums[i];
        }
        max = MAX(max, dp);
    }
    
    return max;
}



int maxSubArray4(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }

    int dp[numsSize];
    dp[0] = nums[0];
    int max = dp[0];
    for (int i = 1; i < numsSize; i++) {
        if (dp[i - 1] <= 0) {
            dp[i] = nums[i];
        } else {
            dp[i] = dp[i - 1] + nums[i];
        }
        max = MAX(max, dp[i]);
    }
    
    return max;
}



int maxSubArray__(int* nums, int begin, int end) {
    if (end - begin < 2) { return nums[begin]; }
    
    int mid = (begin + end) >> 1;
    int leftMax = nums[mid - 1]; // CARE!!!
    int leftSum = nums[mid - 1]; // CARE!!!
    for (int i = mid - 2; i >= begin; i--) { // CARE!!!
        leftSum += nums[i];
        leftMax = MAX(leftMax, leftSum);
    }
    
    int rightMax = nums[mid]; // CARE!!!
    int rightSum = nums[mid]; // CARE!!!
    for (int i = mid + 1; i < end; i++) { // CARE!!!
        rightSum += nums[i];
        rightMax = MAX(rightMax, rightSum);
    }

    int left = maxSubArray__(nums, begin, mid);
    int right = maxSubArray__(nums, mid, end);
    int max = MAX(left, right);
    return MAX(leftMax + rightMax, max);
}

int maxSubArray_(int* nums, int begin, int end) {
    if (end - begin < 2) { return nums[begin]; }
    
    int mid = (begin + end) >> 1;
    int leftMax = INT_MIN; // CARE!!!
    int leftSum = 0;
    for (int i = mid - 1; i >= begin; i--) {
        leftSum += nums[i];
        leftMax = MAX(leftMax, leftSum);
    }
    
    int rightMax = INT_MIN; // CARE!!!
    int rightSum = 0;
    for (int i = mid; i < end; i++) {
        rightSum += nums[i];
        rightMax = MAX(rightMax, rightSum);
    }

    int left = maxSubArray_(nums, begin, mid);
    int right = maxSubArray_(nums, mid, end);
    int max = MAX(left, right);
    return MAX(leftMax + rightMax, max);
}

int maxSubArray3(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }

    return maxSubArray_(nums, 0, numsSize);
}




int maxSubArray2(int* nums, int numsSize) {
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
