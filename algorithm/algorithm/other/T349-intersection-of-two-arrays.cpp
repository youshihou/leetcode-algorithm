//
//  T349-intersection-of-two-arrays.cpp
//  algorithm
//
//  Created by Ankui on 7/29/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "T349-intersection-of-two-arrays.hpp"

#include <iostream>
//#include <string>
//#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for (int i : nums2) {
            if (nums1_set.count(i) == 1) {
                set.insert(i);
            }
        }
        return vector<int>(set.begin(), set.end());
    }
};
