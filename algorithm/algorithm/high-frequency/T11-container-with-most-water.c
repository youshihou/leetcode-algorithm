//
//  T11-container-with-most-water.c
//  algorithm
//
//  Created by Ankui on 5/5/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/container-with-most-water/

#include "T11-container-with-most-water.h"
#include "dynamic-programming-common.h"

int maxArea(int* height, int heightSize) {
    if (height == NULL || heightSize <= 0) { return 0; }
    int l = 0;
    int r = heightSize - 1;
    int water = 0;
    
    while (l < r) {
        if (height[l] <= height[r]) {
            int min = height[l];
            water = MAX(water, min * (r - l));
            while (l < r && height[l] <= min) {
                l++;
            }
        } else {
            int min = height[r];
            water = MAX(water, min * (r - l));
            while (l < r && height[r] <= min) {
                r--;
            }
        }
    }
    
    return water;
}


int maxArea1(int* height, int heightSize) {
    if (height == NULL || heightSize <= 0) { return 0; }
    int l = 0;
    int r = heightSize - 1;
    int water = 0;
    
    while (l < r) {
        if (height[l] <= height[r]) {
            water = MAX(water, height[l] * (r - l));
            l++;
        } else {
            water = MAX(water, height[r] * (r - l));
            r--;
        }
    }
    
    return water;
}
