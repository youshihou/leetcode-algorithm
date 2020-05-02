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
    if (len <= 1) { return s; }
    
    int maxLen = 1;
    int begin = 0;
    int i = 0;
    while (i < len) {
        int l = i - 1;
        int r = i;
        while (++r < len && s[r] == s[i]) ;
        i = r;
        while (l >= 0 && r < len && s[l] == s[r]) {
            l--;
            r++;
        }
        int le = r - ++l;
        if (le > maxLen) {
            maxLen = le;
            begin = l;
        }
    }
    
    s[begin + maxLen] = '\0';
    return s + begin;
}



int palindromeLength(char * s, int l, int r) {
    while (l >= 0 && r < strlen(s) && s[l] == s[r]) {
        l--;
        r++;
    }
    return r - l - 1;
}

char * longestPalindrome2(char * s) {
    if (s == NULL) { return NULL; }
    int len = (int)strlen(s);
    if (len <= 1) { return s; }
    
    int maxLen = 1;
    int begin = 0;
    for (int i = len - 2; i >= 1; i--) {
        int len1 = palindromeLength(s, i - 1, i + 1);
        int len2 = palindromeLength(s, i, i + 1);
        len1 = MAX(len1, len2);
        if (len1 > maxLen) {
            maxLen = len1;
            begin = i - ((len1 - 1) >> 1);
        }
    }
    
    if (s[0] == s[1] && maxLen < 2) {
        maxLen = 2;
        begin = 0;
    }
    
    s[begin + maxLen] = '\0';
    return s + begin;
}

char * longestPalindrome1(char * s) {
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
