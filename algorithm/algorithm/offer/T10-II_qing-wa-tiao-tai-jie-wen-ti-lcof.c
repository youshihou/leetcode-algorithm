//
//  T10-II_qing-wa-tiao-tai-jie-wen-ti-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/


#include "T10-II_qing-wa-tiao-tai-jie-wen-ti-lcof.h"
#include "algorithm-common.h"

int numWays1(int n) {
    if (n <= 1) { return 1; }
    int a = 1, b = 1, sum = a + b;
    for (int i = 1; i < n; i++) {
        sum = (a + b) % 1000000007;
        a = b;
        b = sum;
    }
    return b;
}


int numWays(int n){
    if (n <= 1) { return 1; }
    return numWays(n - 1) + numWays(n - 2);
}
