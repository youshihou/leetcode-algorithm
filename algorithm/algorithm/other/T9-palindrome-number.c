//
//  T9-palindrome-number.c
//  algorithm
//
//  Created by Ankui on 5/2/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/palindrome-number/


#include "T9-palindrome-number.h"
#include "algorithm-common.h"


bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) { return false; }
    
    int result = 0;
    while (x > result) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return x == result || x == result / 10;
}
