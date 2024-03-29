//
//  T14-longest-common-prefix.c
//  algorithm
//
//  Created by Ankui on 5/3/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/longest-common-prefix/


#include "T14-longest-common-prefix.h"
#include "algorithm-common.h"

bool isCommonPrefix(char** strs, int strsSize, int len) {
    char str0[len + 1];
    memset(str0, '\0', sizeof(str0));
    strncpy(str0, strs[0], len);
    for (int i = 1; i < strsSize; i++) {
        char *str1 = strs[i];
        for (int j = 0; j < len; j++) {
            if (str0[j] != str1[j]) {
                return false;
            }
        }
    }
    return true;
}

char * longestCommonPrefix(char ** strs, int strsSize) {
    if (strs == NULL || strsSize <= 0) return "";
    int len = INT_MAX;
    for (int i = 0; i < strsSize; i++) {
        len = fmin(len, strlen(strs[i]));
    }
 
    int l = 0;
    int r = len;
    while (l < r) {
        int mid = l + ((r - l + 1) >> 1);
        // int mid = l + ((r - l) >> 1); // ERROR!!!
        if (isCommonPrefix(strs, strsSize, mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    char* res = malloc(sizeof(char) * (l + 1));
    memset(res, '\0', sizeof(char) * (l + 1));
    res = strncpy(res, strs[0], l);
    return res;
}





char * _longestCommonPrefix(char ** strs, int strsSize) {
    if (strs == NULL || strsSize == 0) { return ""; }
    int len = (int)strlen(strs[0]);
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[0][i] != strs[j][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}













char* commonPrefix(char* left, char* right) {
    int min = fmin(strlen(left), strlen(right));
    for (int i = 0; i < min; i++) {
        if (left[i] != right[i]) {
            char* res = malloc(sizeof(char) * (i + 1));
            memset(res, '\0', sizeof(char) * (i + 1));
            res = strncpy(res, left, i);
            return res;
        }
    }
    char* res = malloc(sizeof(char) * (min + 1));
    memset(res, '\0', sizeof(char) * (min + 1));
    res = strncpy(res, left, min);
    return res;
}

char* longestCommonPrefix_(char** strs, int begin, int end) {
    if (begin == end) {
        return strs[begin];
    }
    
    int mid = begin + ((end - begin) >> 1);
    char* left = longestCommonPrefix_(strs, begin, mid);
    char* right = longestCommonPrefix_(strs, mid + 1, end);
    return commonPrefix(left, right);
}

char * __longestCommonPrefix(char ** strs, int strsSize) {
    if (strs == NULL || strsSize == 0) { return ""; }
    return longestCommonPrefix_(strs, 0, strsSize - 1);
}
