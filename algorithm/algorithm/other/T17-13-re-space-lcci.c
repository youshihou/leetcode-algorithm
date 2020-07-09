//
//  T17-13-re-space-lcci.c
//  algorithm
//
//  Created by Ankui on 7/9/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/re-space-lcci/

#include "T17-13-re-space-lcci.h"
#include "algorithm-common.h"

int str_cmp(const void* a, const void* b) {
    return strcmp(*(const char**)b, *(const char**)a);
}

bool str_start(const char* a, const char* b, int* len) {
    const char* begin = b;
    while (*b != '\0') {
        if (*a != *b) {
            *len = (int)(b - begin);
            return false;
        }
        a++;
        b++;
    }
    *len = (int)(b - begin);
    return true;
}


typedef int (*comparator)(const void*, const void*);

typedef struct {
    void* key;
    void* head;
    int size;
    comparator cmp;
} BsearchArg;

int bsearch_cmp(const void* _a, const void* _b) {
    BsearchArg* arg = (BsearchArg*)_a;
    const void* b = _b;
    const void* a = b - arg->size;
    if (b == arg->head) {
        return arg->cmp(arg->key, b) <= 0 ? 0 : 1;
    } else if (arg->cmp(arg->key, a) <= 0) {
        return -1;
    } else {
        return arg->cmp(arg->key, b) <= 0 ? 0 :1;
    }
}

void* search(void* key, void* data, int num, int size, comparator cmp) {
    BsearchArg arg = { key, data, size, cmp };
    return bsearch(&arg, data, num, size, bsearch_cmp);
}

int respace(char** dictionary, int dictionarySize, char* sentence) {
    size_t len = strlen(sentence);
    if (len == 0) { return 0; }
    int dp[len + 1];
    dp[len] = 0;
    qsort(dictionary, dictionarySize, sizeof(void*), str_cmp);
    for (int i = (int)(len - 1); i >= 0; i--) {
        char *target = sentence + i;
        char** find;
        int min = dp[i + 1] + 1;
        int cut = -1;
        int tmp;
        char store = '\0';
        bool matched;
        while (true) {
            find = search(&target, dictionary, dictionarySize, sizeof(void*), str_cmp);
            if (cut != -1) {
                target[cut] = store;
            }
            if (find == NULL) { break; }
            matched = str_start(target, *find, &tmp);
            if (matched) {
                int update = dp[i + tmp];
                min = update < min ? update : min;
                cut = tmp - 1;
            } else {
                cut = tmp;
            }
            if (cut == 0) { break; }
            store = target[cut];
            target[cut] = '\0';
        }
        dp[i] = min;
    }
    
    return dp[0];
}
