//
//  T714-best-time-to-buy-and-sell-stock-with-transaction-fee.c
//  algorithm
//
//  Created by Ankui on 5/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include "T714-best-time-to-buy-and-sell-stock-with-transaction-fee.h"
#include "algorithm-common.h"

int maxProfit5(int* prices, int pricesSize, int fee) {
    if (prices == NULL || pricesSize == 0) { return 0; }
    int buy = prices[0] + fee;
    int maxProfit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] + fee < buy) {
            buy = prices[i] + fee;
        } else if (prices[i] > buy) {
            maxProfit += prices[i] - buy;
            buy = prices[i];
        }
    }
    return maxProfit;
}
