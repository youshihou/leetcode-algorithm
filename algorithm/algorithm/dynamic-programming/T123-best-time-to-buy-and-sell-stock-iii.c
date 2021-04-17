//
//  T123-best-time-to-buy-and-sell-stock-iii.c
//  algorithm
//
//  Created by Ankui on 5/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/

#include "T123-best-time-to-buy-and-sell-stock-iii.h"
#include "algorithm-common.h"

int maxProfit3(int* prices, int pricesSize) {
    if (prices == NULL || pricesSize <= 1) { return 0; }
    int buy1 = -prices[0];
    int buy2 = -prices[0];
    int sell1 = 0;
    int sell2 = 0;
    for (int i = 1; i < pricesSize; i++) {
        buy1 = fmax(buy1, 0 - prices[i]);
        sell1 = fmax(sell1, buy1 + prices[i]);
        buy2 = fmax(buy2, sell1 - prices[i]);
        sell2 = fmax(sell2, buy2 + prices[i]);
    }
    return sell2;
}
