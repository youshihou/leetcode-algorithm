//
//  T72-edit-distance.c
//  algorithm
//
//  Created by Ankui on 5/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/edit-distance/

#include "T72-edit-distance.h"
#include "algorithm-common.h"

int minDistance(char * word1, char * word2) {
    return 0;
    
//    if (word1 == NULL || word2 == NULL) { return 0; }
//    size_t len1 = strlen(word1);
//    size_t len2 = strlen(word2);
//
//    size_t rows = len1;
//    size_t cols = len2;
//    if (len1 < len2) {
//        rows = len2;
//        cols = len1;
//    }
//    // TODO: use int[]
//    int dp[cols + 1];
//    for (int i = 0; i <= cols; i++) {
//        dp[i] = i;
//    }
//    for (int row = 1; row <= rows; row++) {
//        int cur = 0;
//        for (int col = 1; col <= cols; col++) {
//            int leftTop = cur;
//            cur = dp[col];
//            int top = dp[col - 1] + 1;
//            int left = dp[col] + 1;
//            if (word1[row - 1] != word2[col - 1]) {
//                leftTop++;
//            }
//            dp[col] = MIN(leftTop, MIN(top, left));
//        }
//    }
//    return dp[cols];
}

int minDistance1(char * word1, char * word2) {
    if (word1 == NULL || word2 == NULL) { return 0; }
    size_t len1 = strlen(word1);
    size_t len2 = strlen(word2);

    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 && j == 0) {
                dp[0][0] = 0;
            }
            else if (i == 0 && j != 0) {
                dp[0][j] = dp[0][j - 1] + 1; //j;
            }
            else if (i != 0 && j == 0) {
                dp[i][0] = dp[i - 1][0] + 1; // i;
            }
            else {
                int top = dp[i][j - 1] + 1;
                int left = dp[i - 1][j] + 1;
                int leftTop = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) {
                    leftTop += 1;
                }
                dp[i][j] = MIN(leftTop, MIN(top, left));
            }
        }
    }
    
    return dp[len1][len2];
}
