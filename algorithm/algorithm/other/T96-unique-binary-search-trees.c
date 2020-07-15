//
//  T96-unique-binary-search-trees.c
//  algorithm
//
//  Created by Ankui on 7/15/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/unique-binary-search-trees/


#include "T96-unique-binary-search-trees.h"
#include "algorithm-common.h"

int numTrees(int n) {
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    
    return dp[n];
}
