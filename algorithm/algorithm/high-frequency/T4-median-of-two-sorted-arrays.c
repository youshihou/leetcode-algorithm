//
//  T4-median-of-two-sorted-arrays.c
//  algorithm
//
//  Created by Ankui on 5/6/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

#include "T4-median-of-two-sorted-arrays.h"
#include "algorithm-common.h"

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int left = 0;
    int right = nums1Size;
    int median1 = 0;
    int median2 = 0;
    while (left <= right) {
        int i = left + ((right - left) >> 1);
        int j = ((nums1Size + nums2Size + 1) >> 1) - i;
        int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums_i = (i == nums1Size ? INT_MAX : nums1[i]);
        int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums_j = (j == nums2Size ? INT_MAX : nums2[j]);
        if (nums_im1 <= nums_j) {
            median1 = fmax(nums_im1, nums_jm1);
            median2 = fmin(nums_i, nums_j);
            left = i + 1;
        } else {
            right = i - 1;
        }
    }
    return (((nums1Size + nums2Size) & 1) == 0) ? (median1 + median2) / 2.0 : median1;
}
