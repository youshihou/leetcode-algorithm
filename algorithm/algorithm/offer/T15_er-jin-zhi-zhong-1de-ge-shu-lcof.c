//
//  T15_er-jin-zhi-zhong-1de-ge-shu-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/


#include "T15_er-jin-zhi-zhong-1de-ge-shu-lcof.h"
#include "algorithm-common.h"

int hammingWeight(uint32_t n) {
    int result = 0;
    while (n != 0) {
        n &= (n - 1);
        result++;
    }
    return result;
}
