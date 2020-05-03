//
//  T22-generate-parentheses.c
//  algorithm
//
//  Created by Ankui on 5/3/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/generate-parentheses/

#include "T22-generate-parentheses.h"
#include "depth-first-search-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs4(int n, int* returnSize, int left, int right, char* string, char** list, int idx) {
    if (idx == (n << 1)) {
        list[*returnSize] = malloc(sizeof(char) * ((n << 1) + 1)); // CARE!!!
        strcpy(list[*returnSize], string);
        (*returnSize)++;
        return;
    }
    
    if (left > 0) {
        string[idx] = '(';
        dfs4(n, returnSize, left - 1, right, string, list, idx + 1);
    }
    
    if (right > 0 && left != right) {
        string[idx] = ')';
        dfs4(n, returnSize, left, right - 1, string, list, idx + 1);
    }
}

char ** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    if (n <= 0) { return NULL; }
    
    int len = n;
    for (int i = 1; i <= n; i++) {
        len *= i;
    }
    char** list = malloc(sizeof(char*) * len);
    memset(list, '\0', sizeof(char *) * len);
    
    char* string = malloc(sizeof(char) * ((n << 1) + 1));
    memset(string, '\0', sizeof(char) * ((n << 1) + 1));
    
    dfs4(n, returnSize, n, n, string, list, 0);
    
    return list;
}
