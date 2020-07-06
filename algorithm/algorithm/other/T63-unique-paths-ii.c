//
//  T63-unique-paths-ii.c
//  algorithm
//
//  Created by Ankui on 7/6/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/unique-paths-ii/


#include "T63-unique-paths-ii.h"
#include "algorithm-common.h"

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    if (obstacleGrid == NULL) { return 0; }
    if (obstacleGrid[0][0]) { return 0; }
    int rows = obstacleGridSize;
    int cols = *obstacleGridColSize;
    if (rows <= 0 || cols <= 0) { return 0; }
    
    int dp[rows][cols];
    memset(dp, 0, sizeof(dp));
    
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (obstacleGrid[row][col]) {
                continue;
            }
            
            if (row == 0 && col == 0) {
                dp[row][col] = 1;
            }
            else if (row == 0) {
                dp[0][col] += dp[0][col - 1];
            }
            else if (col == 0) {
                dp[row][0] += dp[row - 1][0];
            }
            else {
                dp[row][col] += (dp[row][col - 1] + dp[row - 1][col]);
            }
        }
    }

    return dp[rows - 1][cols - 1];
}
