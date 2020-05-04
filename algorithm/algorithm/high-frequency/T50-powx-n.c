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
    double result = 1.0;
//    int y = n < 0 ? -n : n; //CARE!!! when n = -2^31, -n overflow
    long y = n < 0 ? -((long)n) : n;
    while (y > 0) {
        if ((y & 1) == 1) {
            result *= x;
        }
        x *= x;
         
        y >>= 1;
    }
    
    return n < 0 ? (1/result) : result;
}

double myPow1(double x, int n) {
    if (n == 0) { return 1; }
    if (n == -1) { return 1/x; } // CARE!!!
    
    double half = myPow(x, n >> 1);
    half *= half;

    return ((n & 1) == 1) ? half * x : half;
}
