//
//  T64-qiu-12n-lcof.c
//  algorithm
//
//  Created by Ankui on 5/10/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/qiu-12n-lcof/


#include "T64-qiu-12n-lcof.h"
#include "algorithm-common.h"


int sumNums(int n) {
    n && (n += sumNums(n - 1));
    return n;
}

int _sumNums(int n) {
    if (n == 0) { return 0; }
    return n + _sumNums(n - 1);
}
