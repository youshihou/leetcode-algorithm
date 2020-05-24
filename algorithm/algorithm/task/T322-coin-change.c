//
//  T322-coin-change.c
//  algorithm
//
//  Created by Ankui on 5/24/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/coin-change/

#include "T322-coin-change.h"
#include "algorithm-common.h"

int coinChange(int* coins, int coinsSize, int amount) {
    if (coins == NULL || coinsSize <= 0 || amount < 1) { return 0; }
    
    int* dp = calloc(amount + 1, sizeof(int));
    memset(dp, 0, sizeof(int) * (amount + 1));
    
    for (int i = 1; i <= amount; i++) {
        int min = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            int coin = coins[j];
            if (i < coin) { continue; }
            int value = dp[i - coin];
            if (value < 0 || value >= min) { continue; }
            min = value;
        }
        if (min == INT_MAX) {
            dp[i] = -1;
        } else {
            dp[i] = min + 1;
        }
    }
    
    return dp[amount];
}

int coinChange1(int* coins, int coinsSize, int amount) {
    if (coins == NULL || coinsSize <= 0 || amount < 1) { return 0; }
    
    int* dp = calloc(amount + 1, sizeof(int));
    memset(dp, 0, sizeof(int) * (amount + 1));
    
    for (int i = 1; i <= amount; i++) {
        int min = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            int coin = coins[j];
            if (i < coin || dp[i - coin] < 0) { continue; }
            min = MIN(min, dp[i - coin]);
        }
        if (min == INT_MAX) {
            dp[i] = -1;
        } else {
            dp[i] = min + 1;
        }
    }
    
    return dp[amount];
}
