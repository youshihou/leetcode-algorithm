//
//  T56-II_shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof.c
//  algorithm
//
//  Created by Ankui on 5/12/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/


#include "T56-II_shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof.h"
#include "algorithm-common.h"

int __singleNumber(int* nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            count += (nums[j] >> i) & 1;
        }
        if (count % 3 == 1) {
            res |= 1 << i;
        }
    }
    return res;
}



int _singleNumber(int* nums, int numsSize) {
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones;
}
