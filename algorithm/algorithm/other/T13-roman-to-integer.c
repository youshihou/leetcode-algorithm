//
//  T13-roman-to-integer.c
//  algorithm
//
//  Created by Ankui on 5/2/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/roman-to-integer/


#include "T13-roman-to-integer.h"
#include "algorithm-common.h"

int valueWithKey(char key) {
    int res = 1000;
    switch (key) {
        case 'I':
            res = 1;
            break;
        case 'V':
            res = 5;
            break;
        case 'X':
            res = 10;
            break;
        case 'L':
            res = 50;
            break;
        case 'C':
            res = 100;
            break;
        case 'D':
            res = 500;
            break;
//        case 'M':
//            res = 1000;
//            break;
        default:
            break;
    }
    return res;
}

int romanToInt(char * s) {
    int len = (int)strlen(s);
    int res = 0;
    for (int i = 0; i < len - 1; i++) {
        int first = valueWithKey(s[i]);
        int second = valueWithKey(s[i + 1]);
        if (first >= second) {
            res += first;
        } else {
            res -= first;
        }
    }
    res += valueWithKey(s[len - 1]);
    return res;
}
