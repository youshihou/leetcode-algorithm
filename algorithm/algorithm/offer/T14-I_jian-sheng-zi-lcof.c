//
//  T14-I_jian-sheng-zi-lcof.c
//  algorithm
//
//  Created by Ankui on 4/24/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/


#include "T14-I_jian-sheng-zi-lcof.h"
#include "algorithm-common.h"


int cuttingRope(int n) {
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            dp[i] = fmax(dp[i], fmax(j * (i - j), j * dp[i - j]));
        }
    }
    return dp[n];
}
