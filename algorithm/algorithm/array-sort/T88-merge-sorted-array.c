//
//  T88-merge-sorted-array.c
//  algorithm
//
//  Created by Ankui on 4/19/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "T88-merge-sorted-array.h"

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i1 = m - 1;
    int i2 = n - 1;
    int cur = m + n - 1;

    while (i2 >= 0) {
        if (i1 >= 0 && nums2[i2] < nums1[i1]) {
            nums1[cur--] = nums1[i1--];
        } else {
             // i < 0 || nums2[i2] >= nums1[i1]
            nums1[cur--] = nums2[i2--];
        }
    }

    
    // [0]
    // 0
    // [1]
    // 1
//     int i1 = m - 1;
//     int i2 = n - 1;
//     int cur = m + n - 1;
//     while (i2 >= 0) {
//         if (i1 >= 0 && nums1[i1] < nums2[i2]) {
//             // when nums1 = [0], m = 0, then i2 == 0 unable to exit the loop ！！！
//             nums1[cur--] = nums2[i2--];
//         } else {
//             nums1[cur--] = nums1[i1--];
//         }
//     }
    
}
