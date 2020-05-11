//
//  T42-trapping-rain-water.c
//  algorithm
//
//  Created by Ankui on 5/6/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/trapping-rain-water/

#include "T42-trapping-rain-water.h"
#include "algorithm-common.h"

int trap(int* height, int heightSize) {
    if (height == NULL || heightSize <= 0) { return 0; }

    int l = 0;
    int r = heightSize - 1;
    int lowerMax = 0;
    int water = 0;
    
    while (l < r) {
        int min = height[l] <= height[r] ? height[l++] : height[r--];
        lowerMax = MAX(lowerMax, min);
        water += lowerMax - min;
    }
    
    return water;
}


int trap2(int* height, int heightSize) {
    if (height == NULL || heightSize <= 0) { return 0; }

    int lastIdx = heightSize - 2;
    int rightMaxes[heightSize];
    rightMaxes[heightSize - 1] = 0;
    for (int i = lastIdx; i >= 1; i--) {
        rightMaxes[i] = MAX(rightMaxes[i + 1], height[i + 1]);
    }

    int water = 0;
    int leftMax = 0;
    for (int i = 1; i <= lastIdx; i++) {
//        leftMax = MAX(leftMax, height[i]);
        leftMax = MAX(leftMax, height[i -1]); // CARE!!! is i-1 not i
        int min = MIN(leftMax, rightMaxes[i]);
        if (min <= height[i]) { continue; }
        water += min - height[i];
    }
    
    return water;
}


int trap1(int* height, int heightSize) {
    if (height == NULL || heightSize <= 0) { return 0; }

    int lastIdx = heightSize - 2;
    int leftMaxes[heightSize];
    leftMaxes[0] = 0;
    int rightMaxes[heightSize];
    rightMaxes[0] = 0;
    rightMaxes[heightSize - 1] = 0;
    for (int i = 1; i <= lastIdx; i++) {
        leftMaxes[i] = MAX(leftMaxes[i - 1], height[i - 1]);
    }
    for (int i = lastIdx; i >= 1; i--) {
        rightMaxes[i] = MAX(rightMaxes[i + 1], height[i + 1]);
    }

    int water = 0;
    for (int i = 1; i <= lastIdx; i++) {
        // int min = MAX(leftMaxes[i - 1], rightMaxes[i + 1]); // ERROR!!!
        // int min = MAX(leftMaxes[i], rightMaxes[i]); // ERROR!!!
        int min = MIN(leftMaxes[i], rightMaxes[i]);
        if (min <= height[i]) { continue; }
        water += min - height[i];
    }
    
    return water;
}
