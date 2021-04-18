//
//  T10-I_fei-bo-na-qi-shu-lie-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/


#include "T10-I_fei-bo-na-qi-shu-lie-lcof.h"
#include "algorithm-common.h"

// 0, 1, 1, 2, 3, 5, 8
int fib2(int n) {
    if (n <= 1) { return n; }
    int first = 0;
    int second = 1;
    int sum = first + second;
    for (int i = 1; i < n; i++) {
        sum = (first + second) % 1000000007;
        first = second;
        second = sum;
    }
    return second;
}

int fib1(int n) {
    if (n <= 1) { return n; }
    int first = 0;
    int second = 1;
    for (int i = 1; i < n; i++) {
        second = first + second;
        first = second - first;
    }
    return second;
}


int fib(int n) {
    if (n <= 1) { return n; }
    return fib(n - 2) + fib(n - 1);
}
