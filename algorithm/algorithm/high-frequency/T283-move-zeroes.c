//
//  T283-move-zeroes.c
//  algorithm
//
//  Created by Ankui on 5/4/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/move-zeroes/

#include "T283-move-zeroes.h"

void moveZeroes(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) { return; }
    
    for (int i = 0, cur = 0; i < numsSize; i++) {
        if (nums[i] == 0) { continue; }
        if (cur != i) {
//            nums[cur++] = nums[i]; //ERROR!!!
            nums[cur] = nums[i];
            nums[i] = 0;
        }
        cur++; // CARE!!!
    }
}
