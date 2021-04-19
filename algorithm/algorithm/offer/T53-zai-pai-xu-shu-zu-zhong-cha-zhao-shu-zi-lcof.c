//
//  T53-zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/


#include "T53-zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof.h"
#include "algorithm-common.h"




int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize;
    int mid = 0;
    int count = 0;
    while (left < right) {
        mid = left + ((right - left) >> 1);
        if (target == nums[mid]) {
            for (int i = left; i < mid; i++) {
                if (nums[i] == target) {
                    count++;
                }
            }
            
            for (int i = mid; i < numsSize; i++) {
                if (nums[i] == target) {
                    count++;
                }
            }
            break;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return count;
}



int helper(int* nums, int size, int target) {
    int l = 0, r = size - 1, m = 0;
    while (l <= r) {
        m = l + ((r - l) >> 1);
        if (nums[m] <= target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int search2(int* nums, int numsSize, int target) {
    return helper(nums, numsSize, target) - helper(nums, numsSize, target - 1);
}



int search1(int* nums, int numsSize, int target) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (target == nums[i]) {
            count++;
        }
    }
    return count;
}
