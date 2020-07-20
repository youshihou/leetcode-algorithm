//
//  T167-two-sum-ii-input-array-is-sorted.c
//  algorithm
//
//  Created by Ankui on 7/20/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/


#include "T167-two-sum-ii-input-array-is-sorted.h"
#include "algorithm-common.h"


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    if (numbers == NULL || numbersSize <= 0) { return NULL; }
    *returnSize = 2;

    int *result = malloc(sizeof(int) * (*returnSize));
    int left = 0;
    int right = numbersSize - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else {
            result[0] = left + 1;
            result[1] = right + 1;
            break;;
        }
    }
    
    return result;
}



int* twoSum1(int* numbers, int numbersSize, int target, int* returnSize) {
    if (numbers == NULL || numbersSize <= 0) { return NULL; }
    *returnSize = 2;
    
    int *result = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < numbersSize - 1; i++) { // CARE!!!
        int left = i + 1; // CARE!!!
        int right = numbersSize - 1; // CARE!!!
        while (left <= right) {
            int mid = (left + right) >> 1;
            int num = numbers[mid];
            int remaining = target - numbers[i];
            if (num < remaining) {
                left = mid + 1;
            } else if (num > remaining) {
                right = mid - 1; // CARE!!!
            } else {
                result[0] = i + 1;
                result[1] = mid + 1;
                break;
            }
        }
    }
    
   return result;
}
