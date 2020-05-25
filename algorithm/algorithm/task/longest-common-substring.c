//
//  longest-common-substring.c
//  algorithm
//
//  Created by Ankui on 5/24/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "longest-common-substring.h"
#include "algorithm-common.h"


int longestCommonSubstring(char * text1, char * text2) {
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
    int max = dp[0];
    
    for (int row = 1; row <= rows; row++) {
        int cur = 0;
        for (int col = 1; col <= cols; col++) {
            int leftTop = cur;
            cur = dp[col];
            if (text1[row - 1] == text2[col - 1]) {
                dp[col] = leftTop + 1;
                max = MAX(max, dp[col]);
            } else {
                dp[col] = 0; // MUST!!!
            }
        }
    }
    
    return max;
}


int longestCommonSubstring2(char * text1, char * text2) {
    if (text1 == NULL || text2 == NULL) { return 0; }
    
    size_t len1 = strlen(text1);
    size_t len2 = strlen(text2);
    
    int dp[2][len2 + 1];
    memset(dp, 0, sizeof(dp));
    int max = dp[0][0];
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + 1;
            }
            
            max = MAX(max, dp[i & 1][j]);
        }
    }
    
    return max;
}




int longestCommonSubstring1(char * text1, char * text2) {
    if (text1 == NULL || text2 == NULL) { return 0; }
    
    size_t len1 = strlen(text1);
    size_t len2 = strlen(text2);
    
    int dp[len1 + 1][len2 + 1];
    memset(dp, 0, sizeof(dp));
    int max = dp[0][0];
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            
            max = MAX(max, dp[i][j]);
        }
    }
    
    return max;
}
