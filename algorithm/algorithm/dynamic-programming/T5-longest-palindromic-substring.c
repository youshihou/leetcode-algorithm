//
//  T5-longest-palindromic-substring.c
//  algorithm
//
//  Created by Ankui on 5/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/longest-palindromic-substring/

#include "T5-longest-palindromic-substring.h"
#include "dynamic-programming-common.h"

char * longestPalindrome(char * s) {
    if (s == NULL) { return NULL; }
    int len = (int)strlen(s);
    if (len == 0) { return s; }
    
    bool dp[len][len];
    int maxLen = 1;
    int begin = 0;
    for (int i = len - 1; i >= 0; i--) {
        // from bottom to top
        for (int j = i; j < len; j++) {
            // from let to right

//            if (l <= 2) {
//                dp[i][j] = s[i] == s[j];
//            } else {
//                dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
//            }
            
            int l = j - i + 1;
            dp[i][j] = (s[i] == s[j]) && (l <= 2 || dp[i+1][j-1]);
            if (dp[i][j] && l > maxLen) {
                maxLen = l;
                begin = i;
            }
        }
    }
    
    s[begin + maxLen] = '\0';
    return s + begin;
}
