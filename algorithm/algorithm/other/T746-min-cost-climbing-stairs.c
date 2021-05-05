//
//  T746-min-cost-climbing-stairs.c
//  algorithm
//
//  Created by Ankui on 5/5/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/min-cost-climbing-stairs/


#include "T746-min-cost-climbing-stairs.h"
#include "algorithm-common.h"

int minCostClimbingStairs(int* cost, int costSize) {
    int pre = 0;
    int cur = 0;
    for (int i = 2; i <= costSize; i++) {
        int next = fmin(cur + cost[i - 1], pre + cost[i - 2]);
        pre = cur;
        cur = next;
    }
    return cur;
}




int _minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize + 1];
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= costSize; i++) {
        dp[i] = fmin(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[costSize];
}
