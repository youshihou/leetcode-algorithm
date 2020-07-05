//
//  T44-wildcard-matching.c
//  algorithm
//
//  Created by Ankui on 7/5/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/wildcard-matching/

#include "T44-wildcard-matching.h"
#include "algorithm-common.h"


bool isMatch(char * s, char * p) {
    if (s == NULL || p == NULL) { return false; }
    size_t slen = strlen(s);
    size_t plen = strlen(p);
    int dp[slen + 1][plen + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    
    for (int i = 1; i <= plen; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = true;
        } else {
            break;
        }
    }
    
    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= plen; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    return dp[slen][plen];
}
