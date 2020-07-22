//
//  T11-xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof.c
//  algorithm
//
//  Created by Ankui on 7/22/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/


#include "T11-xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof.h"
#include "algorithm-common.h"

int minArray(int* numbers, int numbersSize) {
    if (numbers == NULL || numbersSize <= 0) { return 0; }
    
    int begin = 0;
    int end = numbersSize - 1;
    
    while (begin < end) {
//        int mid = (begin + end) >> 1;
        int mid = begin + ((end - begin) >> 1);
        if (numbers[mid] < numbers[end]) {
            end = mid;
        } else if (numbers[mid] > numbers[end]) {
            begin = mid + 1;
        } else {
            end--;
        }
    }
    return numbers[begin];
}




int t11_cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minArray1(int* numbers, int numbersSize) {
    if (numbers == NULL || numbersSize <= 0) { return 0; }
    
    qsort(numbers, numbersSize, sizeof(int), t11_cmp);
    
    return numbers[0];
}
