//
//  T32-longest-valid-parentheses.c
//  algorithm
//
//  Created by Ankui on 7/4/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/longest-valid-parentheses/

#include "T32-longest-valid-parentheses.h"
#include "algorithm-common.h"


int longestValidParentheses(char * s) {
    if (s == NULL) { return 0; }
    size_t len = strlen(s);
    if (len == 0) { return 0; }
    int maxlen = 0;
    int stack[len + 1];
    int top = -1;
    stack[++top] = -1;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            --top;
            if (top == -1) {
                stack[++top] = i;
            } else {
                maxlen = fmax(maxlen, i - stack[top]);
            }
        }
    }
    
    return maxlen;
}



int longestValidParentheses1(char * s) {
    if (s == NULL) { return 0; }
    size_t len = strlen(s);
    if (len == 0) { return 0; }
    int dp[len];
    memset(dp, 0, sizeof(dp));
    int maxlen = 0;
    
    for (int i = 1; i < len; i++) { // CARE!!! i = 1 not i = 0
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            maxlen = fmax(maxlen, dp[i]);
        }
    }
    
    return maxlen;
}
