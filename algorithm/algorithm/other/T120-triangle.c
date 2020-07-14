//
//  T120-triangle.c
//  algorithm
//
//  Created by Ankui on 7/14/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/triangle/


#include "T120-triangle.h"
#include "algorithm-common.h"

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    if (triangle == NULL || triangleSize <= 0) { return 0; }
    
    int dp[2][triangleSize];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i++) {
        int curr = i % 2;
        int prev = 1 - curr;
        dp[curr][0] = dp[prev][0] + triangle[i][0];
        for (int j = 1; j < i; j++) {
            dp[curr][j] = fmin(dp[prev][j - 1], dp[prev][j]) + triangle[i][j];
        }
        dp[curr][i] = dp[prev][i - 1] + triangle[i][i];
    }
    int ret = dp[(triangleSize - 1) % 2][0];
    for (int i = 1; i < triangleSize; i++) {
        ret = fmin(ret, dp[(triangleSize - 1) % 2][i]);
    }
    return ret;
}




int minimumTotal1(int** triangle, int triangleSize, int* triangleColSize) {
    if (triangle == NULL || triangleSize <= 0) { return 0; }
    
    int dp[triangleSize][triangleSize];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; j++) {
            dp[i][j] = fmin(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    int ret = dp[triangleSize - 1][0];
    for (int i = 1; i < triangleSize; i++) {
        ret = fmin(ret, dp[triangleSize - 1][i]);
    }
    
    return ret;
}
