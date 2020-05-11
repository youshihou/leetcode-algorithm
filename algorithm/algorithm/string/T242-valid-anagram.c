//
//  T242-valid-anagram.c
//  algorithm
//
//  Created by Ankui on 4/27/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/valid-anagram/

#include "T242-valid-anagram.h"
#include "algorithm-common.h"

bool isAnagram(char * s, char * t) {
    if (s == NULL || t == NULL) { return false; }
    size_t l1 = strlen(s);
    size_t l2 = strlen(t);
    if (l1 != l2) { return false; }
        
    int counts[26] = {0}; // CARE!!! int not char !!!!!
    for (int i = 0; i < l1; i++) {
        counts[s[i] - 'a']++;
    }

    for (int i = 0; i < l2; i++) {
        if (--counts[t[i] - 'a'] < 0) {
            return false;
        }
    }
    
    return true;
}

bool isAnagram1(char * s, char * t) {
    if (s == NULL || t == NULL) { return false; }
    size_t l1 = strlen(s);
    size_t l2 = strlen(t);
    if (l1 != l2) { return false; }
    
    char cs[26] = {0};
    char ct[26] = {0};
    for (int i = 0; i < l1; i++) {
        cs[s[i] - 'a']++;
        ct[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cs[i] != ct[i]) {
            return false;
        }
    }
        
    return true;
}
