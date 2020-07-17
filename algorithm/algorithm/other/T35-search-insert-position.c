//
//  T35-search-insert-position.c
//  algorithm
//
//  Created by Ankui on 7/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/search-insert-position/


#include "T35-search-insert-position.h"
#include "algorithm-common.h"

int searchInsert(int* nums, int numsSize, int target) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    int begin = 0;
    int end = numsSize;
    while (begin < end) {
        int mid = (begin + end) >> 1;
        int num = nums[mid];
        if (num == target) {
            return mid;
        } else if (num > target) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }
    
    return end;
}


int searchInsert1(int* nums, int numsSize, int target) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    int begin = 0;
    int end = numsSize - 1; // CARE!!!
    while (begin <= end) { // CARE!!!
        int mid = (begin + end) >> 1;
        int num = nums[mid];
        if (num == target) {
            return mid;
        } else if (num > target) {
            end = mid - 1; // CARE!!!
        } else {
            begin = mid + 1;
        }
    }
    
    return begin; // CARE!!!
}
