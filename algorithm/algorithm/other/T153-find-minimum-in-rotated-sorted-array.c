//
//  T153-find-minimum-in-rotated-sorted-array.c
//  algorithm
//
//  Created by Ankui on 7/22/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/


#include "T153-find-minimum-in-rotated-sorted-array.h"
#include "algorithm-common.h"

int findMin(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return -1; }
    
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int mid = ((right - left) >> 1) + left;
        if (nums[mid] < nums[right]) {
            right = mid;
        } else if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right--;
        }
    }
    
    return nums[left];
}
