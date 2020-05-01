//
//  T47-li-wu-de-zui-da-jie-zhi-lcof.c
//  algorithm
//
//  Created by Ankui on 5/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/

#include "T47-li-wu-de-zui-da-jie-zhi-lcof.h"
#include "dynamic-programming-common.h"


int maxValue(int** grid, int gridSize, int* gridColSize) {
    if (grid == NULL) { return 0; }
    int rows = gridSize;
    int cols = *gridColSize;
    if (cols == 0 || rows == 0) { return 0; }
        
    for (int col = 1; col < cols; col++) {
        grid[0][col] += grid[0][col - 1];
    }
    for (int row = 1; row < rows; row++) {
        grid[row][0] += grid[row - 1][0];
    }
    
    for (int row = 1; row < rows; row++) {
        for (int col = 1; col < cols; col++) {
            grid[row][col] += MAX(grid[row - 1][col], grid[row][col - 1]);
        }
    }
    
    return grid[rows - 1][cols - 1];
}


int maxValue1(int** grid, int gridSize, int* gridColSize) {
    if (grid == NULL) { return 0; }
    int rows = gridSize;
    int cols = *gridColSize;
    if (cols == 0 || rows == 0) { return 0; }
    
    int dp[200][200] = {0};
    
    dp[0][0] = **grid;
    for (int col = 1; col < cols; col++) {
        dp[0][col] = dp[0][col - 1] + grid[0][col];
    }
    for (int row = 1; row < rows; row++) {
        dp[row][0] = dp[row - 1][0] + grid[row][0];
    }
    
    for (int row = 1; row < rows; row++) {
        for (int col = 1; col < cols; col++) {
            dp[row][col] = MAX(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
        }
    }
    
    return dp[rows - 1][cols - 1];
}
