//
//  T3-longest-substring-without-repeating-characters.c
//  algorithm
//
//  Created by Ankui on 4/29/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

#include "T3-longest-substring-without-repeating-characters.h"
#include "string-common.h"
#include <limits.h>
#include <math.h>

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

int lengthOfLongestSubstring(char * s) {
    if (s == NULL) { return 0; }
    size_t len = strlen(s);
    if (len == 0) { return 0; }
    
    //"au"
    
    // every char last time appeared position
    int* preIdxes = malloc(sizeof(int) * 128); // why not need initilize -1
//    memset(preIdxes, -1, sizeof(int) * 128);
    
//    int preIdxes[128] = {}; // need initilize -1
//    for (int i = 0; i < 128; i++) {
//        preIdxes[i] = -1;
//    }
    preIdxes[s[0]] = 0; // CARE!!!
    
    // i - 1 position longest substring start index
    int li = 0;
    int max = 1;
    for (int i = 1; i < len; i++) {
        // i last time appeared position
        int pi = preIdxes[s[i]];
        if (li <= pi) { // CARE!!!
            li = pi + 1; // CARE!!!
        }
        // save the char appeared position
        preIdxes[s[i]] = i;
        
        max = MAX(max, i - li + 1);
    }

    free(preIdxes);
    
    return max;
}
