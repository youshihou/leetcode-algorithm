//
//  T392-is-subsequence.cpp
//  algorithm
//
//  Created by Ankui on 7/27/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/is-subsequence/


#include "T392-is-subsequence.hpp"
#include "cplulplus-common.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t n = s.length();
        size_t m = t.length();
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
};
