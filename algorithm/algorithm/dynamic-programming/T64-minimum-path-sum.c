//
//  T64-minimum-path-sum.c
//  algorithm
//
//  Created by Ankui on 5/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/minimum-path-sum/

#include "T64-minimum-path-sum.h"
#include "dynamic-programming-common.h"

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    if (grid == NULL) { return 0; }
    int rows = gridSize;
    int cols = *gridColSize;
    if (rows <= 0 || cols <= 0) { return 0; }
    
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (row == 0 && col == 0) {
                grid[row][col] = grid[0][0];
            }
            else if (row == 0 && col != 0) {
                grid[0][col] += grid[0][col - 1];
            }
            else if (row != 0 && col == 0) {
                grid[row][0] += grid[row - 1][0];
            }
            else {
                grid[row][col] += MIN(grid[row][col - 1], grid[row - 1][col]);
            }
        }
    }
    
    return grid[rows - 1][cols - 1];
}

int minPathSum2(int** grid, int gridSize, int* gridColSize) {
    if (grid == NULL) { return 0; }
    int rows = gridSize;
    int cols = *gridColSize;
    if (rows <= 0 || cols <= 0) { return 0; }
    
    for (int col = 1; col < cols; col++) {
        grid[0][col] += grid[0][col - 1];
    }
    for (int row = 1; row < rows; row++) {
        grid[row][0] += grid[row - 1][0];
    }
    for (int row = 1; row < rows; row++) {
        for (int col = 1; col < cols; col++) {
            grid[row][col] += MIN(grid[row][col - 1], grid[row - 1][col]);
        }
    }
    
    return grid[rows - 1][cols - 1];
}
