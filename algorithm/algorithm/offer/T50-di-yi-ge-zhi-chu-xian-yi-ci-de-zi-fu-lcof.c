//
//  T50-di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/


#include "T50-di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof.h"
#include "algorithm-common.h"


char firstUniqChar(char* s){
    int list[26] = {0};
    int len = (int)strlen(s);
    for (int i = 0; i < len; i++) {
        list[s[i] - 'a']++;
    }
    for (int i = 0; i < len; i++) {
        if (list[s[i] - 'a'] == 1) {
            return s[i];
        }
    }
            
    return ' ';
}
