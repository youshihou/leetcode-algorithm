//
//  T1-two-sum.c
//  algorithm
//
//  Created by Ankui on 5/4/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/two-sum/

#include "T1-two-sum.h"
#include "hash_table.h"
#include "high-frequency-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;
    if (nums == NULL || numsSize <= 0) { return NULL; }
    
    int* result = malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    struct hash_table table;
    hash_init(&table, 37); // magic number
    for (int i = 0; i < numsSize; i++) {
        int key = target - nums[i];
        struct hash_data* data = hash_find(table, key);
        if (data != NULL && data->value != i) {
            result[0] = data->value;
            result[1] = i;
        }
        hash_insert(table, nums[i], i);
    }
    hash_free(table);

    return result;
}
