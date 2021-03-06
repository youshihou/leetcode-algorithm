//
//  T36-valid-sudoku.c
//  algorithm
//
//  Created by Ankui on 5/16/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/valid-sudoku/

#include "T36-valid-sudoku.h"
#include "algorithm-common.h"

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    if (board == NULL) { return false; }
    
    short rows[9] = { false };
    short cols[9] = { false };
    short boxes[9] = { false };
    
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            char num = board[row][col];
            if (num == '.') { continue; }
//            num = (char)(1 << (num - '1')); // ERROR!!!
            short bit = 1 << (num - '1');
            
            if ((rows[row] & bit) != 0) { return false; }
            if ((cols[col] & bit) != 0) { return false; }
            int idx = (row / 3) * 3 + col / 3;
            if ((boxes[idx] & bit) != 0) { return false; }
            
            rows[row] |= bit;
            cols[col] |= bit;
            boxes[idx] |= bit;
        }
    }

    return true;
}



bool isValidSudoku1(char** board, int boardSize, int* boardColSize) {
    if (board == NULL) { return false; }
    
    bool rows[9][9] = { false };
    bool cols[9][9] = { false };
    bool boxes[9][9] = { false };
    
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            char num = board[row][col];
            if (num == '.') { continue; }
            num -= '1';
            if (rows[row][num]) { return false; }
            if (cols[col][num]) { return false; }
            int idx = (row / 3) * 3 + col / 3;
            if (boxes[idx][num]) { return false; }
            
            rows[row][num] = true;
            cols[col][num] = true;
            boxes[idx][num] = true;
        }
    }

    return true;
}
