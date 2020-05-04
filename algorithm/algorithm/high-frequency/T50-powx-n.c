//
//  T50-powx-n.c
//  algorithm
//
//  Created by Ankui on 5/4/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/powx-n/

#include "T50-powx-n.h"
#include "high-frequency-common.h"

double myPow(double x, int n) {
    if (n == 0) { return 1; }
    if (n == -1) { return 1/x; } // CARE!!!
    
    bool odd = (n & 1) == 1;
    double half = myPow(x, n >> 1);
    half *= half;

    return odd ? half * x : half;
}
