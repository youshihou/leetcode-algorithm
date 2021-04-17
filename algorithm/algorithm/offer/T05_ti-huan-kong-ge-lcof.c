//
//  T05_ti-huan-kong-ge-lcof.c
//  algorithm
//
//  Created by Ankui on 4/17/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/


#include "T05_ti-huan-kong-ge-lcof.h"
#include "algorithm-common.h"


char* replaceSpace(char* s) {
    int size = sizeof(char) * (int)strlen(s) * 3 + 1;
    char* result = malloc(size);
    memset(result, '\0', size);
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        if (s[i] != ' ') {
            result[j++] = s[i];
        } else {
            result[j++] = '%';
            result[j++] = '2';
            result[j++] = '0';
        }
        i++;
    }
    return result;
}
