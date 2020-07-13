//
//  T350-intersection-of-two-arrays-ii.c
//  algorithm
//
//  Created by Ankui on 7/13/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/


#include "T350-intersection-of-two-arrays-ii.h"
#include "algorithm-common.h"


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp_t350(const void* a, const void* b) {
    int *_a = (int*)a;
    int *_b = (int*)b;
    if (*_a == *_b) {
        return 0;
    } else if (*_a > *_b) {
        return 1;
    } else {
        return -1;
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = 0;
    if (nums1 == NULL || nums1Size <= 0 || nums2 == NULL || nums2Size <= 0) { return NULL; }
    
    qsort(nums1, nums1Size, sizeof(int), cmp_t350);
    qsort(nums2, nums2Size, sizeof(int), cmp_t350);
    int *result = malloc(sizeof(int) * fmin(nums1Size, nums2Size));
    
    int idx1 = 0, idx2 = 0;
    while (idx1 < nums1Size && idx2 < nums2Size) {
        if (nums1[idx1] < nums2[idx2]) {
            idx1++;
        } else if (nums1[idx1] > nums2[idx2]) {
            idx2++;
        } else {
            result[(*returnSize)++] = nums1[idx1];
            idx1++;
            idx2++;
        }
    }
    
    return result;
}
