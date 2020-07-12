//
//  T174-dungeon-game.c
//  algorithm
//
//  Created by Ankui on 7/12/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/dungeon-game/


#include "T174-dungeon-game.h"
#include "algorithm-common.h"


int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    if (dungeon == NULL || dungeonSize <= 0) { return 0; }
    
    int n = dungeonSize;
    int m = *dungeonColSize;
    int dp[n + 1][m + 1];
     memset(dp, 0xf, sizeof(dp)); // why not 0?
    
    dp[n][m - 1] = dp[n - 1][m] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int min = fmin(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = fmax(min - dungeon[i][j], 1);
        }
    }
    
    return dp[0][0];
}
