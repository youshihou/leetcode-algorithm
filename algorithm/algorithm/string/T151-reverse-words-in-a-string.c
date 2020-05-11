//
//  T151-reverse-words-in-a-string.c
//  algorithm
//
//  Created by Ankui on 4/28/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/reverse-words-in-a-string/

#include "T151-reverse-words-in-a-string.h"
#include "algorithm-common.h"


void reverse(char* s, int li, int ri) {
    ri--;
    while (li < ri) {
        char temp = s[li];
        s[li] = s[ri];
        s[ri] = temp;
        li++;
        ri--;
    }
}

char * reverseWords(char * s) {
    if (s == NULL ) { return s; }
    size_t l = strlen(s);
    if (l == 0) { return s; }
    
    char* chars = malloc(sizeof(char) * (l + 1)); // CARE!!!

    int cur = 0;
    bool space = true;
    for (int i = 0; i < l; i++) {
        if (s[i] != ' ') {
            chars[cur++] = s[i];
            space = false;
        } else if (space == false) {
            chars[cur++] = ' ';
            space = true;
        }
    }
    int len = space ? cur - 1: cur;
    if (len <= 0) { // CARE!!!
        free(chars);
        return "";
    } else { // CARE!!!
        chars[len] = '\0';
    }


    reverse(chars, 0, len);
    int preSpaceIdx = -1;
    for (int i = 0; i < len; i++) {
        if (chars[i] != ' ') { continue; }
        reverse(chars, preSpaceIdx + 1, i);
        preSpaceIdx = i;
    }
    
    reverse(chars, preSpaceIdx + 1, len);
    
    return chars;
}
