//
//  T58-II_zuo-xuan-zhuan-zi-fu-chuan-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/


#include "T58-II_zuo-xuan-zhuan-zi-fu-chuan-lcof.h"
#include "algorithm-common.h"


char* reverseLeftWords(char* s, int n) {
    if (s == NULL || n <= 0) { return s; }
    int len = (int)strlen(s);
    if (len == 0) { return s; }
    
    int i = 0;
    char* list = malloc(sizeof(char) * (len + 1));
    while (i < len) {
        *list = s[(n + i) % len];
        list++;
        i++;
    }
    *list = '\0';
    return list - len;
}

    
char* reverseLeftWords1(char* s, int n) {
    if (s == NULL || n <= 0) { return s; }
    int len = (int)strlen(s);
    if (len == 0) { return s; }
    
    char tmp[n];
    int i = 0;
    for (; i < n; i++) {
        tmp[i] = s[i];
    }
//    for (i = 0; i < len - n; i++) {
//        s[i] = s[i + n];
//    }
    for (i = n; i < len; i++) {
        s[i - n] = s[i];
    }
//    for (i = 0 ; i < n; i++) {
//        s[i + len - n] = tmp[i];
//    }
    for (i = len - n; i < len; i++) {
        s[i] = tmp[i - (len - n)];
    }
    return s;
}
