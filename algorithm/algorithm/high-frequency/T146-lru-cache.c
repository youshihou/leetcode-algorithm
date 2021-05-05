//
//  T146-lru-cache.c
//  algorithm
//
//  Created by Ankui on 5/5/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/lru-cache/

#include "T146-lru-cache.h"
#include "algorithm-common.h"

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/

struct LinkedListNode {
    int key;
    int value;
    struct LinkedListNode* prev;
    struct LinkedListNode* next;
};

struct LinkedListNode* createLinkedListNode(int key, int value) {
    struct LinkedListNode* n = malloc(sizeof(struct LinkedListNode));
    memset(n, 0, sizeof(struct LinkedListNode));
    n->key = key;
    n->value = value;
    return n;
}

void linkedListAddAfterFirst(struct LinkedListNode* head, struct LinkedListNode* node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
}

void linkedListRemove(struct LinkedListNode* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    free(node);
}

void linkedListMove(struct LinkedListNode* from, struct LinkedListNode* to) {
    from->prev->next = from->next;
    from->next->prev = from->prev;
    from->next = to->next;
    from->prev = to;
    to->next->prev = from;
    to->next = from;
}




#define HashMapSize 1024
struct HashMapNode {
    int key;
    struct LinkedListNode* value;
    struct HashMapNode* next;
};

struct HashMapNode* createHashMapNode(int key, struct LinkedListNode* value, struct HashMapNode* next) {
    struct HashMapNode* n = malloc(sizeof(struct HashMapNode));
    n->key = key;
    n->value = value;
    n->next = next;
    return n;
}


struct HashMapNode** hashMapInit(void) {
    struct HashMapNode** m = malloc(sizeof(struct HashMapNode*) * HashMapSize);
    for (int i = 0; i < HashMapSize; i++) {
        m[i] = createHashMapNode(-1, 0, NULL);
    }
    return m;
}

int hashMapCode(int key) {
    if (key == INT_MIN) {
        key = INT_MAX;
    } else if (key < 0) {
        key = -key;
    }
    return key % HashMapSize;
}

bool hashMapPut(struct HashMapNode** hashMap, int key, struct LinkedListNode* value) {
    int code = hashMapCode(key);
    struct HashMapNode *node = hashMap[code];
    if (node->key == -1) {
        node->key = key;
        node->value = value;
        return true;
    }
    
    while (true) {
        if (node->key == key) {
            node->value = value;
            return false;
        }
        
        if (node->next == NULL) { break; }
        node = node->next;
    }
    
    node->next = createHashMapNode(key, value, NULL);
    
    return true;
}

bool hashMapGet(struct HashMapNode** hashMap, int key, struct LinkedListNode** value) {
    int code = hashMapCode(key);
    struct HashMapNode* node = hashMap[code];
    while (node != NULL && node->key != - 1) {
        if (node->key == key) {
            *value = node->value;
            return true;
        }
        node = node->next;
    }
    
    value = NULL; // why?

    return false;
}

bool hashMapRemove(struct HashMapNode** hashMap, int key) {
    int code = hashMapCode(key);
    struct HashMapNode* node = hashMap[code];
    if (node->key == key) {
        if (node->next == NULL) {
            node->key = -1;
            node->value = NULL;
//            return true;
        } else {
            struct HashMapNode* tmp = node->next;
            node->value = node->next->value;
            node->key = node->next->key;
            node->next = node->next->next;
            free(tmp);
//            return true;
        }
        return true;
    }
    
    while (node->next != NULL) {
        struct HashMapNode* tmp = node->next;
        if (tmp->key == key) {
            node->next = tmp->next;
            free(tmp);
            return true;
        }
        node = node->next;
    }
    
    return false;
}







typedef struct {
    int size;
    int capacity;
    struct HashMapNode** hashMap;
    struct LinkedListNode* first;
    struct LinkedListNode* last;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *c = malloc(sizeof(LRUCache));
    c->hashMap = hashMapInit();
    c->capacity = capacity;
    c->size = 0;
    c->first = createLinkedListNode(-1, 0);
    c->last = createLinkedListNode(-1, 0);
    c->first->next = c->last;
    c->last->prev = c->first;
    return c;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if (obj->capacity <= 0) { return -1; }
    
    struct LinkedListNode* node = NULL;
    hashMapGet(obj->hashMap, key, &node);
    if (node == NULL) { return -1; }
    
    linkedListMove(node, obj->first);
    
    return node->value;
}

void lRUCacheRemoveLast(LRUCache* obj) {
    if (obj->size < obj->capacity) {
        obj->size++;
        return;
    }
    
    struct LinkedListNode* node = obj->last->prev;
    hashMapRemove(obj->hashMap, node->key);
    linkedListRemove(node);
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (obj->capacity <= 0) { return; }
    
    struct LinkedListNode* node = NULL;
    hashMapGet(obj->hashMap, key, &node);
    if (node != NULL) {
        node->value = value;
        linkedListMove(node, obj->first);
        return;
    }
    
    lRUCacheRemoveLast(obj);
    node = createLinkedListNode(key, value);
    linkedListAddAfterFirst(obj->first, node);
    hashMapPut(obj->hashMap, key, node);
}

void lRUCacheFree(LRUCache* obj) {
    free(obj->hashMap);
    free(obj->first);
    free(obj->last);
    free(obj);
}


