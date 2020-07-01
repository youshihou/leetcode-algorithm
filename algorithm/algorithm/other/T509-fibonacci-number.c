//
//  T509-fibonacci-number.c
//  algorithm
//
//  Created by Ankui on 7/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/fibonacci-number/

#include "T509-fibonacci-number.h"

int fib(int N) {
    if (N <= 1) { return N; }

    int first = 0, second = 1;
    for (int i = 0; i < N - 1; i++) {
        second = first + second;
        first = second - first;
    }

    return second;
}

int fib_(int N) {
    if (N <= 1) { return N; }
    
    return fib(N - 1) + fib(N - 2);
}
