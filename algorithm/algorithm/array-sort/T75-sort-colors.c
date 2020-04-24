//
//  T75-sort-colors.c
//  algorithm
//
//  Created by Ankui on 4/19/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/sort-colors/

#include "T75-sort-colors.h"

void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void sortColors(int* nums, int numsSize) {
    int i = 0;
    int l = 0;
    int r = numsSize - 1;
    
    while (i <= r) {
        int v = nums[i];
        if (v == 0) {
            swap(nums, i++, l++);
        } else if (v == 1) {
            i++;
        } else {
            swap(nums, i, r--);
        }
    }
}

void sortColors1(int* nums, int numsSize){
    int i = 0;
    int l = 0;
    int r = numsSize - 1;
    
    while (i <= r) {
        int v = nums[i];
        if (v == 0) {
            int temp = nums[i];
            nums[i] = nums[l];
            nums[l] = temp;
            i++;
            l++;
        } else if (v == 1) {
            i++;
        } else {
            int temp = nums[i];
            nums[i] = nums[r];
            nums[r] = temp;
            r--;
        }
    }

}

