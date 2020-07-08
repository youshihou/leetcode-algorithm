//
//  T16-11-diving-board-lcci.c
//  algorithm
//
//  Created by Ankui on 7/8/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/diving-board-lcci/


#include "T16-11-diving-board-lcci.h"
#include "algorithm-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* divingBoard(int shorter, int longer, int k, int* returnSize) {
    if (k == 0) {
        *returnSize = 0;
        return NULL;
    }

    if (shorter == longer) {
        int *p = malloc(sizeof(int));
        *p = shorter * k;
        *returnSize = 1;
        return p;
    }
    
    *returnSize = k + 1;
    int *lengths = malloc(sizeof(int) * (k + 1));
    for (int i = 0; i <= k; i++) {
        lengths[i] = shorter * (k - i) + longer * i;
    }
    
    return lengths;
}
