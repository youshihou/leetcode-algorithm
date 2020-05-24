//
//  T1143-longest-common-subsequence.c
//  algorithm
//
//  Created by Ankui on 5/24/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/longest-common-subsequence/

#include "T1143-longest-common-subsequence.h"
#include "algorithm-common.h"

int longestCommonSubsequence(char * text1, char * text2) {
    if (text1 == NULL || text2 == NULL) { return 0; }
    
    size_t len1 = strlen(text1);
    size_t len2 = strlen(text2);
    int dp[len1 + 1][len2 + 1];
    memset(dp, 0, sizeof(dp)); // MUST!!!
//    dp[0][0] = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[len1][len2];
}






int longestCommonSubsequence_(char * text1, size_t i, char * text2, size_t j) {
    if (i == 0 || j == 0) { return 0; }
    
    if (text1[i - 1] == text2[j - 1]) {
        return longestCommonSubsequence_(text1, i - 1, text2, j - 1) + 1;
    }
    
    int l = longestCommonSubsequence_(text1, i - 1, text2, j);
    int r = longestCommonSubsequence_(text1, i, text2, j - 1);
    return MAX(l, r);
}

int longestCommonSubsequence1(char * text1, char * text2) {
    if (text1 == NULL || text2 == NULL) { return 0; }
    
    size_t len1 = strlen(text1);
    size_t len2 = strlen(text2);
    return longestCommonSubsequence_(text1, len1, text2, len2);
}
