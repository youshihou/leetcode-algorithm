//
//  T154-find-minimum-in-rotated-sorted-array-ii.c
//  algorithm
//
//  Created by Ankui on 7/22/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/


#include "T154-find-minimum-in-rotated-sorted-array-ii.h"
#include "algorithm-common.h"


int findMin(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return -1; }
    
    int l = 0;
    int r = numsSize - 1;
    int m;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (nums[m] < nums[r]) {
            r = m;
        } else if (nums[m] > nums[r]) {
            l = m + 1;
        } else {
            r--;
        }
    }
    
    return nums[l];
}
