//
//  T53-II-que-shi-de-shu-zi-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/


#include "T53-II_que-shi-de-shu-zi-lcof.h"
#include "algorithm-common.h"


int ____missingNumber(int* nums, int numsSize) {
    int l = 0, r = numsSize, m = 0;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (nums[m] == m) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}



int missingNumber2(int* nums, int numsSize) {
    if (nums[0] == 1) { return 0; }
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i) {
            return i;
        }
    }
    return numsSize;
}

int missingNumber1(int* nums, int numsSize) {
    if (nums[0] != 0 ) { return 0; }
    
    int i = 0;
    for (; i < numsSize - 1; i++) {
        if (nums[i + 1] != nums[i] + 1) {
            break;
        }
    }
    return i + 1;
}
