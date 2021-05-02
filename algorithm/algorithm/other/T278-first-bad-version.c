//
//  T278-first-bad-version.c
//  algorithm
//
//  Created by Ankui on 5/2/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/first-bad-version/



#include "T278-first-bad-version.h"
#include "algorithm-common.h"

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int l = 1;
    int r = n;
    int m = 0;
    while (l < r) {
        m = l + ((r - l) >> 1);
//        if (isBadVersion(m)) {
//            r = m;
//        } else {
//            l = m + 1;
//        }
    }
    return l;
}
