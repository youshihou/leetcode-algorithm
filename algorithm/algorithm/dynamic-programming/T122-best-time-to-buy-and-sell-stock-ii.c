//
//  T122-best-time-to-buy-and-sell-stock-ii.c
//  algorithm
//
//  Created by Ankui on 5/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

#include "T122-best-time-to-buy-and-sell-stock-ii.h"
#include "algorithm-common.h"

int maxProfit2(int* prices, int pricesSize) {
    if (prices == NULL || pricesSize <= 1) { return 0; }
    int maxProfit = 0;
    for (int i = 1; i < pricesSize; i++) {
        maxProfit += fmax(0, prices[i] - prices[i - 1]);
    }
    return maxProfit;
}
