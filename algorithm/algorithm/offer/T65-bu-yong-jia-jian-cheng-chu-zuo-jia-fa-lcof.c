//
//  T65-bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/


#include "T65-bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof.h"
#include "algorithm-common.h"


int add(int a, int b) {
    while (b) {
        int c = (unsigned int)(a & b) << 1;
        a ^= b;
        b = c;
    }
    return a;
}
