//
//  T718-maximum-length-of-repeated-subarray.c
//  algorithm
//
//  Created by Ankui on 7/3/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/


#include "T718-maximum-length-of-repeated-subarray.h"
#include "algorithm-common.h"


int max_len(int* A, int* B, int addA, int addB, int len) {
    int ret = 0;
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (A[addA + i] == B[addB + i]) {
            k++;
        } else {
            k = 0;
        }
        ret = fmax(ret, k);
    }
    return ret;
}

int findLength(int* A, int ASize, int* B, int BSize) {
    if (A == NULL || B == NULL) { return 0; }

    int ret = 0;
    
    for (int i = 0; i < ASize; i++) {
        int len = fmin(BSize, ASize - i);
        int maxLen = max_len(A, B, i, 0, len);
        ret = fmax(ret, maxLen);
    }
    for (int i = 0; i < BSize; i++) {
        int len = fmin(ASize, BSize - i);
        int maxLen = max_len(A, B, 0, i, len);
        ret = fmax(ret, maxLen);
    }
    
    return ret;
}







int findLength1(int* A, int ASize, int* B, int BSize) {
    if (A == NULL || B == NULL) { return 0; }
    
    int dp[ASize + 1][BSize + 1];
    memset(dp, 0, sizeof(dp));
    int maxLength = 0;
    for (int i = 1; i <= ASize; i++) {
        for (int j = 1; j <= BSize; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }
            maxLength = MAX(maxLength, dp[i][j]);
        }
    }
    
    return maxLength;
}
