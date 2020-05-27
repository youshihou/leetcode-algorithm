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
    
    char* rowsText = text1;
    char* colsText = text2;
    if (strlen(text1) < strlen(text2)) {
        rowsText = text2;
        colsText = text1;
    }
    
    size_t rows = strlen(rowsText);
    size_t cols = strlen(colsText);
    
    int dp[cols + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= rows; i++) {
        for (size_t j = cols; j >= 1; j--) {
            if (rowsText[i - 1] == colsText[j - 1]) { // CARE!!! right --> left
                dp[j] = dp[cols - 1] + 1; // CARE!!!
            } else {
                dp[j] = MAX(dp[j], dp[j - 1]);
            }
        }
    }
    
    return dp[cols];
}





int longestCommonSubsequence6(char * text1, char * text2) {
    if (text1 == NULL || text2 == NULL) { return 0; }
    
    char* rowsText = text1;
    char* colsText = text2;
    if (strlen(text1) < strlen(text2)) {
        rowsText = text2;
        colsText = text1;
    }
    
    size_t rows = strlen(rowsText);
    size_t cols = strlen(colsText);
    
    int dp[cols + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= rows; i++) {
        int cur = 0; // CARE!!!
        for (int j = 1; j <= cols; j++) {
            int leftTop = cur; // CARE!!!
            cur = dp[j]; // CARE!!!
            if (rowsText[i - 1] == colsText[j - 1]) {
                dp[j] = leftTop + 1; // CARE!!!
            } else {
                dp[j] = MAX(dp[j], dp[j - 1]);
            }
        }
    }
    
    return dp[cols];
}






int longestCommonSubsequence5(char * text1, char * text2) {
    if (text1 == NULL || text2 == NULL) { return 0; }
    
    size_t len1 = strlen(text1);
    size_t len2 = strlen(text2);
    int dp[len2 + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= len1; i++) {
        int cur = 0; // CARE!!!
        for (int j = 1; j <= len2; j++) {
            int leftTop = cur; // CARE!!!
            cur = dp[j]; // CARE!!!
            if (text1[i - 1] == text2[j - 1]) {
                dp[j] = leftTop + 1; // CARE!!!
            } else {
                dp[j] = MAX(dp[j], dp[j - 1]);
            }
        }
    }
    
    return dp[len2];
}



int longestCommonSubsequence4(char * text1, char * text2) {
    if (text1 == NULL || text2 == NULL) { return 0; }
    
    size_t len1 = strlen(text1);
    size_t len2 = strlen(text2);
    int dp[2][len2 + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= len1; i++) {
        int row = i & 1; // CARE!!!
        int preRow = (i - 1) & 1; // CARE!!!
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[row][j] = dp[preRow][j - 1] + 1; // CARE!!!
            } else {
                dp[row][j] = MAX(dp[preRow][j], dp[row][j - 1]); // CARE!!!
            }
        }
    }
    
    return dp[len1 & 1][len2]; // CARE!!!
}


int longestCommonSubsequence3(char * text1, char * text2) {
    if (text1 == NULL || text2 == NULL) { return 0; }
    
    size_t len1 = strlen(text1);
    size_t len2 = strlen(text2);
    int dp[2][len2 + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= len1; i++) {
        int row = i % 2; // CARE!!!
        int preRow = (i - 1) % 2; // CARE!!!
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[row][j] = dp[preRow][j - 1] + 1; // CARE!!!
            } else {
                dp[row][j] = MAX(dp[preRow][j], dp[row][j - 1]); // CARE!!!
            }
        }
    }
    
    return dp[len1 % 2][len2]; // CARE!!!
}




int longestCommonSubsequence2(char * text1, char * text2) {
    if (text1 == NULL || text2 == NULL) { return 0; }
    
    size_t len1 = strlen(text1);
    size_t len2 = strlen(text2);
    int dp[len1 + 1][len2 + 1];
    memset(dp, 0, sizeof(dp)); // MUST!!!
//    dp[0][0] = 0;

    for (int i = 1; i <= len1; i++) { // CARE!!! i <= len1
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) { // CARE!!! j <= len2
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
