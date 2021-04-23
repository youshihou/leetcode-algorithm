//
//  T70-climbing-stairs.c
//  algorithm
//
//  Created by Ankui on 4/23/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/climbing-stairs/


#include "T70-climbing-stairs.h"
#include "algorithm-common.h"

int climbStairs(int n) {
    if (n <= 2) { return n; }
    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}



int climbStairs2(int n) {
    if (n <= 2) { return n; }
    
    int first = 1;
    int second = 2;
    int sum = first + second;
    for (int i = 2; i < n; i++) {
        sum = first + second;
        first = second;
        second = sum;
    }
    return second;
}


int climbStairs1(int n) {
    if (n <= 2) { return n; }
    return climbStairs(n - 1) + climbStairs(n - 2);
}
