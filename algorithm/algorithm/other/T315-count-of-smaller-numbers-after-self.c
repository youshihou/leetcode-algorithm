//
//  T315-count-of-smaller-numbers-after-self.c
//  algorithm
//
//  Created by Ankui on 7/11/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/


#include "T315-count-of-smaller-numbers-after-self.h"
#include "algorithm-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int low_bit(int x) {
    return x & (-x);
}

void update(int* c, int n, int pos) {
    while (pos < n) {
        c[pos] += 1;
        pos += low_bit(pos);
    }
}

int query(int* c, int n, int pos) {
    int res = 0;
    while (pos > 0) {
        res += c[pos];
        pos -= low_bit(pos);
    }
    return res;
}

int low_bound(int* a, int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int discretization(int* a, int* nums, int n) {
    memcpy(a, nums, sizeof(int) * n);
    qsort(a, n, sizeof(int), cmp);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[m]) {
            a[++m] = a[i];
        }
    }
    return m + 1;
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (nums == NULL || numsSize <= 0) { return NULL; }
    
    int *result = malloc(sizeof(int) * numsSize);
    memset(result, 0, sizeof(int) * numsSize);
    int *list = malloc(sizeof(int) * numsSize);
    memset(list, 0, sizeof(int) * numsSize);
    int *array = malloc(sizeof(int) * (numsSize + 1));
    memset(array, 0, sizeof(int) * (numsSize + 1));
    
    int m = discretization(list, nums, numsSize);
    for (int i = numsSize - 1; i >= 0; --i) {
        int id = low_bound(list, m, nums[i]) + 1;
        result[i] = query(array, m + 1, id - 1);
        update(array, m + 1, id);
    }
    free(list);
    free(array);
    return result;
}


int* countSmaller1(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (nums == NULL || numsSize <= 0) { return NULL; }
    
    int *result = malloc(sizeof(int) * numsSize);
    memset(result, 0, sizeof(int) * numsSize);
    int *list = malloc(sizeof(int) * numsSize);
    memset(list, 0, sizeof(int) * numsSize);
    
    int sortIndex = 0;
    list[sortIndex] = nums[numsSize - 1];
    int j = 0;
    
    for (int i = numsSize - 2; i >= 0; i--) {
        j = sortIndex;
        while (j >= 0 && nums[i] <= list[j]) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = nums[i];
        sortIndex++;
        result[i] = j + 1;
    }
    
    return result;
}
