//
//  T75-sort-colors.c
//  algorithm
//
//  Created by Ankui on 4/19/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/sort-colors/

#include "T75-sort-colors.h"

void t75_swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void t75_sortColors(int* nums, int numsSize){
    int i = 0;
    int l = 0;
    int r = numsSize - 1;

    while (i <= r) {
        int n = nums[i];
        if (n == 0) {
            t75_swap(&nums[i++], &nums[l++]);
        } else if (n == 1) {
            i++;
        } else {
            t75_swap(&nums[i], &nums[r--]);
        }
    }
}






void t75swap(int* nums, int i, int j) {
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
            t75swap(nums, i++, l++);
        } else if (v == 1) {
            i++;
        } else {
            t75swap(nums, i, r--);
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

