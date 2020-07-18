//
//  T97-interleaving-string.c
//  algorithm
//
//  Created by Ankui on 7/18/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/interleaving-string/


#include "T97-interleaving-string.h"
#include "algorithm-common.h"


bool isInterleave(char * s1, char * s2, char * s3) {
    size_t n = strlen(s1);
    size_t m = strlen(s2);
    size_t t = strlen(s3);
    if (n + m != t) { return false; }
    
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int p = i + j - 1;
            if (i > 0) {
                dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
            }
            if (j > 0) {
                dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
            }
        }
    }
    
    return dp[n][m];
}
