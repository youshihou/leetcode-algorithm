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


int fibonacci_(int n) {
    if (n <= 1) { return n; }
    
    // 0  1  2  3  4  5  6  7 ...n
    // 0, 1, 1, 2, 3, 5, 8, 13, ...
    int first = 0;
    int second = 1;
    for (int i = 0; i < n - 1; i++) {
        second = first + second;
        first = second - first;
        
//        int sum = first + second;
//        first = second;
//        second = sum;
    }
    return second;
}

