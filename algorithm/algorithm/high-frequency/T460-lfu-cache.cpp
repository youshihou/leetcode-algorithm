//
//  T460-lfu-cache.cpp
//  algorithm
//
//  Created by Ankui on 9/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "T460-lfu-cache.hpp"
#include "cplulplus-common.h"


struct Node {
    int key, val, freq;
    Node(int key, int val, int freq): key(key), val(val), freq(freq) {}
};

class LFUCache {
    int minfreq;
    int capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
public:
    LFUCache(int capacity) {
        minfreq = 0;
        this->capacity = capacity;
        key_table.clear();
        freq_table.clear();
    }
    
    int get(int key) {
        if (capacity == 0) { return -1; }
        auto it = key_table.find(key);
        if (it == key_table.end()) { return -1; }
        list<Node>::iterator node = it->second;
        int val = node->val;
        int freq = node->freq;
        freq_table[freq].erase(node);
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) {
                minfreq += 1;
            }
        }
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) { return; }
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            if (key_table.size() == capacity) {
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            }
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            list<Node>::iterator node = it->second;
            int freq = node->freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) {
                    minfreq += 1;
                }
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
