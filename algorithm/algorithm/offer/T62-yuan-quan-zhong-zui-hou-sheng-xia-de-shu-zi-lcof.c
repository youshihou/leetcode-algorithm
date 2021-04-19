//
//  T62-yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof.c
//  algorithm
//
//  Created by Ankui on 5/4/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/

#include "T62-yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof.h"

int lastRemaining(int n, int m) {
    int f = 0;
    for (int i = 2; i != n + 1; i++) {
        f = (m + f) % i;
    }
    return f;
}


int lastRemaining2(int n, int m) {
    if (n <= 0 || m <= 0) { return 0; }
    
    // f(1, 3) = 0;
    // f(2, 3) = (f(1, 3) + 3) % 2;
    // f(8, 3) = (f(7, 3) + 3) % 6;
    // f(9, 3) = (f(8, 3) + 3) % 9;
    // f(10, 3) = (f(9, 3) + 3) % 10;
    int result = 0;
//    for (int i = 2; i <= n; i++) { // CARE!!! i = 2, maybe i = 1
    for (int i = 1; i <= n; i++) {
        result = (result + m) % i;
    }
    
    return result;}


int lastRemaining1(int n, int m) {
    if (n <= 0 || m <= 0) { return 0; }

    // f(n, m) = (f(n - 1, m) + m) % n;
    if (n == 1) { return 0; }
    return (lastRemaining(n - 1, m) + m) % n;
}
