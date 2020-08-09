//
//  T632-smallest-range-covering-elements-from-k-lists.cpp
//  algorithm
//
//  Created by Ankui on 8/1/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/


#include "T632-smallest-range-covering-elements-from-k-lists.hpp"
#include "cplulplus-common.h"

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        size_t n = nums.size();
        unordered_map<int, vector<int>> map;
        int minX = INT_MAX;
        int maxX = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (const int& x : nums[i]) {
                map[x].push_back(i);
                minX = min(minX, x);
                maxX = max(maxX, x);
            }
        }
        
        vector<int> result(n);
        int inside = 0;
        int left = minX;
        int right = minX - 1;
        int bl = minX;
        int br = maxX;
        while (right < maxX) {
            ++right;
            if (map.count(right)) {
                for (const int& x : map[right]) {
                    ++result[x];
                    if (result[x] == 1) {
                        ++inside;
                    }
                }
            }
            while (inside == n) {
                if (right - left < br - bl) {
                    bl = left;
                    br = right;
                }
                if (map.count(left)) {
                    for (const int& x : map[left]) {
                        --result[x];
                        if (result[x] == 0) {
                            --inside;
                        }
                    }
                }
                ++left;
            }
        }
        return {bl, br};
    }
};
