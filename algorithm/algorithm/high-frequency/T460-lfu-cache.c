//
//  T460-lfu-cache.c
//  algorithm
//
//  Created by Ankui on 9/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/lfu-cache/

#include "T460-lfu-cache.h"
#include "algorithm-common.h"

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/

typedef struct LFUCache {
    int key;
    int value;
    int freq;
    int time;
    struct LFUCache *next;
} LFUCache;


LFUCache* lFUCacheCreate(int capacity) {
    LFUCache *o = malloc(sizeof(LFUCache));
    o->key = 0;
    o->value = capacity;
    o->next = NULL;
    LFUCache *cur = o;
    for (int i = 0; i < capacity; i++) {
        LFUCache *n = malloc(sizeof(LFUCache));
        n->next = NULL;
        cur->next = n;
        cur = n;
    }
    return o;
}

int lFUCacheGet(LFUCache* obj, int key) {
    int value = -1;
    LFUCache *cur = obj;
    for (int i = 0; i < obj->key; i++) {
        cur->next->time += 1;
        if (key == cur->next->key) {
            value = cur->next->value;
            cur->next->freq += 1;
            cur->next->time = 0;
        }
        cur = cur->next;
    }
    return value;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    int flag = 0;
    LFUCache *cur = obj;
    for (int i = 0; i < obj->key; i++) {
        cur->next->time += 1;
        if (cur->next->key == key) {
            cur->next->value = value;
            cur->next->freq += 1;
            cur->next->time = 0;
            flag = 1;
        }
        cur = cur->next;
    }
    
    if (flag == 0 && obj->value > 0) {
        if (obj->key < obj->value) {
            obj->key += 1;
            cur = cur->next;
        } else {
            LFUCache *sel = obj->next;
            cur = obj;
            for (int i = 0; i < obj->key; i++) {
                if (cur->next->freq < sel->freq) {
                    sel = cur->next;
                } else if ((cur->next->freq == sel->freq) && (cur->next->time > sel->time)) {
                    sel = cur->next;
                }
                cur = cur->next;
            }
            cur = sel;
        }
        cur->key = key;
        cur->value = value;
        cur->freq = 1;
        cur->time = 0;
    }
}

void lFUCacheFree(LFUCache* obj) {
    LFUCache *n;
    while (obj->next) {
        n = obj->next;
        obj->next = n->next;
        free(n);
    }
    free(obj);
}
