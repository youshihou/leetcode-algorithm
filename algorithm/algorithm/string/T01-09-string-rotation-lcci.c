//
//  T01-09-string-rotation-lcci.c
//  algorithm
//
//  Created by Ankui on 4/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/string-rotation-lcci/

#include "T01-09-string-rotation-lcci.h"
#include "string-common.h"

bool isFlipedString(char* s1, char* s2) {
    if (s1 == NULL || s2 == NULL) { return false; }
    size_t l1 = strlen(s1);
    size_t l2 = strlen(s2);
    if (l1 != l2) { return false; }
    
    char* s = malloc(sizeof(char) * (l1 + l2 + 1));
    strcpy(s, s1);
    strcat(s, s1);
    return strstr(s, s2);
}
