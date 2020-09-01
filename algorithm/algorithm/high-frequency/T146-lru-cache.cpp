//
//  T146-lru-cache.cpp
//  algorithm
//
//  Created by Ankui on 9/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "T146-lru-cache.hpp"
#include "cplulplus-common.h"


struct DLinkedNode {
    int key;
    int value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int key, int value): key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;
public:
    LRUCache(int capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
        size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.count(key)) { return -1; }
        DLinkedNode *n = cache[key];
        moveToHead(n);
        return n->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                DLinkedNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        } else {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
    
    void removeNode(DLinkedNode * node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToHead(DLinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void moveToHead(DLinkedNode * node) {
        removeNode(node);
        addToHead(node);
    }
    
    DLinkedNode* removeTail(void) {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
