//
//  T16-sub-sort-lcci.c
//  algorithm
//
//  Created by Ankui on 4/19/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/sub-sort-lcci/


#include "T16-sub-sort-lcci.h"
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* subSort(int* array, int arraySize, int* returnSize) {
    int* result = (int *)malloc(sizeof(int) * 2);
    result[0] = result[1] = -1;
    *returnSize = 2;

    if (array == NULL || arraySize == 0) {
        return result;
    }
    
    // from left to right, find min
    int max = array[0];
    int r = -1;
    for (int i = 1; i < arraySize; i++) {
        int v = array[i];
        if (v < max) {
            r = i;
        } else {
            max = v;
        }
    }
    
    // no need sort
    if (r == -1) {
        return result;
    }
    
    // from right to left, find max
    int min = array[arraySize - 1];
    int l = - 1;
    for (int i = arraySize - 2; i >= 0; i--) {
        int v = array[i];
        if (v > min) {
            l = i;
        } else {
            min = v;
        }
    }

    result[0] = l;
    result[1] = r;
    
    return result;
}
