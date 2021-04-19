//
//  T39-shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/


#include "T39-shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof.h"
#include "algorithm-common.h"

int majorityElement(int* nums, int numsSize) {
    int result = 0;
    int vote = 0;
    for (int i = 0; i < numsSize; i++) {
        if (vote == 0) {
            result = nums[i];
        }
        
        if (nums[i] == result) {
            vote += 1;
        } else {
            vote -= 1;
        }
    }
    return result;
}



int majorityElement1(int* nums, int numsSize) {
    int count = 0;
    int result = 0;
    int v = 0;
    for (int i = 0; i < numsSize; i++) {
        v = nums[i];
        if (count == 0) {
            result = v;
            count++;
        } else if (result == v) {
            count++;
        } else {
            count--;
        }
    }
    return result;
}
