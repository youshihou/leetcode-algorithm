//
//  T7-reverse-integer.c
//  algorithm
//
//  Created by Ankui on 5/5/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/reverse-integer/

#include "T7-reverse-integer.h"
#include <limits.h>

//int reverse(int x) {
//    int result = 0;
//    while (x != 0) {
//        int prev = result;
//        int mod = x % 10;
//        result = prev * 10 + mod;
//        if ((result - mod) / 10 != prev) {
//            return 0;
//        }
//        x /= 10;
//    }
//
//    return result;
//}


int reverse(int x) {
    long result = 0;
    while (x != 0) {
        result = result * 10 + x % 10;
        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        x /= 10;
    }
    
    return (int)result;
}
