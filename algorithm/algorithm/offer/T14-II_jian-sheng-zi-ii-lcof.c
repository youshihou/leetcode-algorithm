//
//  T14-II_jian-sheng-zi-ii-lcof.c
//  algorithm
//
//  Created by Ankui on 4/25/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/


#include "T14-II_jian-sheng-zi-ii-lcof.h"
#include "algorithm-common.h"

int __cuttingRope(int n) {
    if (n < 4) { return n - 1; }
    long long result = 1;
    while (n > 4) {
        result = result * 3 % 1000000007;
        n -= 3;
    }
    return (int)(result * n % 1000000007);
}
