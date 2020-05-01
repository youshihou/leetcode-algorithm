//
//  T62-unique-paths.c
//  algorithm
//
//  Created by Ankui on 5/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/unique-paths/

#include "T62-unique-paths.h"
#include "dynamic-programming-common.h"

int uniquePaths(int m, int n) {
    if (m <= 0 || n <= 0) { return 0; }
    
    int dp[n][m];
    dp[0][0] = 1;
    for (int col = 0; col < m; col++) {
        for (int row = 0; row < n; row++) {
            if (row == 0 || col == 0) {
                dp[row][col] = 1;
            } else {
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
                
//            if (row == 0 && col == 0) {
//                dp[0][0] = 1;
//            }
//            else if (row == 0 && col != 0) {
//                dp[0][col] = dp[0][col - 1];
//            }
//            else if (row != 0 && col == 0) {
//                dp[row][0] = dp[row - 1][0];
//            }
//            else {
//                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
//            }
        }
    }
    
    return dp[n - 1][m - 1];
}
