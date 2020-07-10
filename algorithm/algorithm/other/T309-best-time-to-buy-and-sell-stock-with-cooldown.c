//
//  T309-best-time-to-buy-and-sell-stock-with-cooldown.c
//  algorithm
//
//  Created by Ankui on 7/10/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/


#include "T309-best-time-to-buy-and-sell-stock-with-cooldown.h"
#include "algorithm-common.h"

int maxProfit(int* prices, int pricesSize) {
    int dp_0 = 0;
    int dp_1 = INT_MIN;
    int dp_pre = 0;
    int tmp = 0;
    
    for (int i = 0; i < pricesSize; i++) {
        tmp = dp_0;
        dp_0 = fmax(dp_0, dp_1 + prices[i]);
        dp_1 = fmax(dp_1, dp_pre - prices[i]);
        dp_pre = tmp;
    }

    return dp_0;
}
