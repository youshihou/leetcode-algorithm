//
//  T58-I_fan-zhuan-dan-ci-shun-xu-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/


#include "T58-I_fan-zhuan-dan-ci-shun-xu-lcof.h"
#include "algorithm-common.h"


char* __reverseWords(char* s) {
    int len = (int)strlen(s);
    if (!s || !len) { return ""; }
    
    int l = 0, r = len - 1;
    while (s[l] == ' ' && l <= r) {
        l++;
    }
    while (s[r] == ' ' && l <= r) {
        r--;
    }
    if (l > r) { return ""; }
    char* list = malloc(sizeof(char) * (len + 1));
    int head = l;
    l = r;
    int i = 0, j = 0;
    while (true) {
        while (l >= 0 && s[l] != ' ') {
            l--;
        }
        for (i = l + 1; i <= r; i++) {
            list[j++] = s[i];
        }
        if (l + 1 == head) {
            break;
        }
        list[j++] = ' ';
        while (s[l] == ' ') {
            l--;
        }
        r = l;
    }
    list[j] = '\0';
    return list;
}
