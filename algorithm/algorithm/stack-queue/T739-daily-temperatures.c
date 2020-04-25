//
//  T739-daily-temperatures.c
//  algorithm
//
//  Created by Ankui on 4/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/daily-temperatures/

#include "T739-daily-temperatures.h"
#include "stack-queue-common.h"
#include "stack.h"
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize) {
    if (T == NULL || TSize == 0) { return NULL; }
    *returnSize = TSize;
    
    int* result = malloc(sizeof(int) * TSize);
//    memset(result, 0, sizeof(int) * TSize);
    result[TSize - 1] = 0;
    
    for (int i = TSize - 2; i >= 0; i--) {
        int j = i + 1;
        while (true) {
            if (T[i] < T[j]) {
                result[i] = j - i;
                break;
            } else if (result[j] == 0) {
                result[i] = 0;
                break;
            } else if (T[i] == T[j]) {
                result[i] = result[j] + j - i;
                break;
            } else {
                j = result[j] + j;
            }
        }
    }
    
    return result;
}



int* dailyTemperatures1(int* T, int TSize, int* returnSize) {
    if (T == NULL || TSize == 0) { return NULL; }
    *returnSize = TSize;
    int* result = malloc(sizeof(int) * TSize);
    memset(result, 0, sizeof(int) * TSize);
    
    Stack* s = create();
    for (int i = 0; i < TSize; i++) {
        while (!isEmpty(s) && T[i] > T[top(s)]) { // CARE!!! >
            result[pop(s)] = i - top(s);
        }
        
        push(s, i);
    }
    stack_free(s);
    
    return result;
}
