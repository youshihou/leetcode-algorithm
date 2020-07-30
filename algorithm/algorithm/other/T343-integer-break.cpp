//
//  T343-integer-break.cpp
//  algorithm
//
//  Created by Ankui on 7/30/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/integer-break/


#include "T343-integer-break.hpp"
#include "cplulplus-common.h"


class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = max(max(2 * (i - 2), 2 * dp[i - 2]), max(3 * (i - 3), 3 * dp[i - 3]));
        }
        return dp[n];
    }
    
    
    int integerBreak1(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++) {
            int cur = 0;
            for (int j = 1; j < i; j++) {
                cur = max(cur, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = cur;
        }
        return dp[n];
    }
    
};
