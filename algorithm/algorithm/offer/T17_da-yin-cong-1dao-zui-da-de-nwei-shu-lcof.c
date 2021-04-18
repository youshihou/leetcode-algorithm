//
//  T17_da-yin-cong-1dao-zui-da-de-nwei-shu-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/

#include "T17_da-yin-cong-1dao-zui-da-de-nwei-shu-lcof.h"
#include "algorithm-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize) {
    int len = 0;
    while (n--) {
        len = len * 10 + 9;
    }
    *returnSize = len;
    int *result = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        result[i] = i + 1;
    }
    return result;
}
