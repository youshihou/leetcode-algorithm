//
//  T977-squares-of-a-sorted-array.c
//  algorithm
//
//  Created by Ankui on 4/21/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/squares-of-a-sorted-array/


#include "T977-squares-of-a-sorted-array.h"
#include <stdlib.h>


int t977cmp(const void * v1, const void * v2) {
    return *(int *)v1 - *(int *)v2;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize) {
    int* result = malloc(sizeof(int) * ASize);
    *returnSize = ASize;
    
    for (int i = 0; i < ASize; i++) {
        result[i] = A[i] * A[i];
    }
        
    qsort(result, ASize, sizeof(int), t977cmp);
    
    return result;
}
