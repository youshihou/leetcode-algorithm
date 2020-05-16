//
//  T347-top-k-frequent-elements.c
//  algorithm
//
//  Created by Ankui on 5/15/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/top-k-frequent-elements/

#include "T347-top-k-frequent-elements.h"
#include "algorithm-common.h"


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


struct Item {
    int value;
    int count;
};

int cmp(const void* a, const void* b) {
    return ((struct Item*)a)->count - ((struct Item*)b)->count;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = 0;
    if (nums == NULL || numsSize <= 0 || k <= 0) { return NULL; }
    
    struct Item* list = malloc(sizeof(struct Item) * numsSize);
    memset(list, 0, sizeof(struct Item) * numsSize);
    
    int offset = 1024; // magic number
    for (int i = 0; i < numsSize; i++) {
        int value = nums[i];
        int idx = (value + offset) % numsSize; // CARE!!! (value + offset), idx must > 0
        list[idx].value = value;
        list[idx].count++;
    }
    
    int size = 0;
    for (int i = 0; i < numsSize; i++) {
        if (list[i].count == 0) { continue; }
        
        list[size].value = list[i].value;
        list[size].count = list[i].count;
        size++;
    }
    
    qsort(list, size, sizeof(list[0]), cmp);
    
    int* result = malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        result[i] = list[size - 1 - i].value;
    }
    
    *returnSize = k;
    return result;
}
