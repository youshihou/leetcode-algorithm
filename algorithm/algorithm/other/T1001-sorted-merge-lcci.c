//
//  T1001-sorted-merge-lcci.c
//  algorithm
//
//  Created by Ankui on 5/1/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/sorted-merge-lcci/


#include "T1001-sorted-merge-lcci.h"
#include "algorithm-common.h"


void merge(int* A, int ASize, int m, int* B, int BSize, int n) {
    int rA = m - 1;
    int rB = n - 1;
    int cur = m + n - 1;
  
    while (rA >= 0 || rB >= 0) {
        if (rA == -1) {
            A[cur] = B[rB--];
        } else if (rB == -1) {
            rA--;
//            A[cur] = A[rA--];
        } else if (A[rA] > B[rB]) {
            A[cur] = A[rA--];
        } else {
            A[cur] = B[rB--];
        }
        cur--;
    }
}
