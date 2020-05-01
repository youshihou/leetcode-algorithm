//
//  T63-gu-piao-de-zui-da-li-run-lcof.c
//  algorithm
//
//  Created by Ankui on 5/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/

#include "T63-gu-piao-de-zui-da-li-run-lcof.h"
#include "dynamic-programming-common.h"

int maxProfit6(int* prices, int pricesSize) {
    if (prices == NULL || pricesSize == 0) { return 0; }
    
    int max = 0;
    int min = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < min) {
            min = prices[i];
        } else {
            max = MAX(max, prices[i] - min);
        }
    }
    
    return max;
}
