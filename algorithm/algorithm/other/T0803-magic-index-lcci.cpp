//
//  T0803-magic-index-lcci.cpp
//  algorithm
//
//  Created by Ankui on 7/31/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/magic-index-lcci/


#include "T0803-magic-index-lcci.hpp"
#include "cplulplus-common.h"


class Solution {
public:
    int _search(vector<int>& nums, int left, int right) {
        if (left > right) { return -1; }
        int mid = left + ((right - left) >> 1);
        int left_num = _search(nums, left, mid - 1);
        if (left_num != -1) {
            return left_num;
        } else if (nums[mid] == mid) {
            return mid;
        }
        return _search(nums, mid + 1, right);
    }
    
    int findMagicIndex(vector<int>& nums) {
        return _search(nums, 0, (int)(nums.size() - 1));
    }
    
    int findMagicIndex1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums[i]) {
                return i;
            }
        }
        return -1;
    }
};
