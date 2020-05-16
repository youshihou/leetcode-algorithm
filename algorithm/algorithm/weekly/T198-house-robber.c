//
//  T198-house-robber.c
//  algorithm
//
//  Created by Ankui on 5/15/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/house-robber/

#include "T198-house-robber.h"
#include "algorithm-common.h"



int rob(int* nums, int numsSize) {
    if (nums == NULL) { return 0; }
    
    int first = 0, second = 0;
    for (int i = 0; i < numsSize; i++) {
        int tmp = second;
        second = MAX(second, first + nums[i]);
        first = tmp;
    }
    
    return second;
}



int rob4(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    if (numsSize == 1) { return nums[0]; }
    if (numsSize == 2) { return MAX(nums[0], nums[1]); }
    
    int first = nums[0];
    int second = MAX(nums[0], nums[1]);
    
    for (int i = 2; i < numsSize; i++) {
        int tmp = second;
//        second = second + first;
        second = MAX(second, first + nums[i]);
        first = tmp;
    }
    
    return second;
}




int rob3(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    if (numsSize == 1) { return nums[0]; }
    if (numsSize == 2) { return MAX(nums[0], nums[1]); }
    
    int sums[numsSize];
    sums[0] = nums[0];
    sums[1] = MAX(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) { // CARE!!! is i < numsSize not i < numsSize - 2
        sums[i] = MAX(sums[i - 1], sums[i - 2] + nums[i]); // is + nums[i] not + sums[i] !!!
    }
    
    return sums[numsSize - 1];
}



int rob_end(int* nums, int size, int end) {
    if (end == 0) { return nums[0]; }
    if (end == 1) { return MAX(nums[1], nums[0]); }

    int cur = nums[end] + rob_end(nums, size, end - 2);
    int pre = rob_end(nums, size, end - 1);
    
    return MAX(cur, pre);
}

int rob2(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    return rob_end(nums, numsSize, numsSize - 1);
}



int rob_begin(int* nums, int size, int begin) {
    if (begin == size - 1) { return nums[begin]; }
    if (begin == size - 2) { return MAX(nums[begin], nums[begin + 1]); }
    
    int cur = nums[begin] + rob_begin(nums, size, begin + 2); // CARE!!! nums[begin]
    int next = rob_begin(nums, size, begin + 1);
    
    return MAX(cur, next);
}

int rob1(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    return rob_begin(nums, numsSize, 0);
}
