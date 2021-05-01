//
//  T136-single-number.c
//  algorithm
//
//  Created by Ankui on 5/1/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/single-number/


#include "T136-single-number.h"
#include "algorithm-common.h"

int singleNumber(int* nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        nums[0] = nums[0] ^ nums[i];
    }
    return nums[0];
}


//int singleNumber(int* nums, int numsSize) {
//    int result = 0;
//    for (int i = 0; i < numsSize; i++) {
//        result = result ^ nums[i];
//    }
//    return result;
//}
