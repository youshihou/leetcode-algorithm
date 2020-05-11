//
//  T654-maximum-binary-tree.c
//  algorithm
//
//  Created by Ankui on 4/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/maximum-binary-tree/

#include "T654-maximum-binary-tree.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* findRoot(int* nums, int l, int r) {
    if (l == r) { return NULL; }
    
    int maxIndex = l;
    for (int i = l + 1; i < r; i++) {
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }
    
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = nums[maxIndex];
    root->left = findRoot(nums, l, maxIndex);
    root->right = findRoot(nums, maxIndex + 1, r);
    return root;
}


struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) { return NULL; }

    return findRoot(nums, 0, numsSize);
}


#include "stack.h"

int* parentIndexes(int* nums, int numberSize) {
    if (nums == NULL || numberSize == 0) { return NULL; }
    
    int* lis = malloc(sizeof(int) * numberSize);
    int* ris = malloc(sizeof(int) * numberSize);
    for (int i = 0; i < numberSize; i++) {
        lis[i] = ris[i] = -1;
    }
    
    
    Stack *s = create();
    for (int i = 0; i < numberSize; i++) {
        while (!isEmpty(s) && nums[top(s)] < nums[i]) {
            ris[pop(s)] = i;
        }
        
//        lis[i] = isEmpty(s) ? -1 : top(s);
        if (!isEmpty(s)) {
            lis[i] = top(s);
        }
        push(s, i);
    }
    
    printf("\n========================\n");
    for (int i = 0; i < numberSize; i++) {
        printf("%d ", lis[i]);
    }
    printf("\n========================\n");
    for (int i = 0; i < numberSize; i++) {
        printf("%d ", ris[i]);
    }
    printf("\n========================\n");

    int *pis = malloc(sizeof(int) * numberSize);
    for (int i = 0; i < numberSize; i++) {
        if (lis[i] == -1 && ris[i] == -1) {
            // i root
            pis[i] = -1;
            continue;
        }
        
        if (lis[i] == -1) {
            pis[i] = ris[i];
        } else if (ris[i] == -1) {
            pis[i] = lis[i];;
        } else if (nums[lis[i]] < nums[ris[i]]) {
            pis[i] = lis[i];
        } else {
            pis[i] = ris[i];
        }
    }
    
    for (int i = 0; i < numberSize; i++) {
        printf("%d ", pis[i]);
    }
    printf("\n========================\n");
    free(lis);
    free(ris);
    
    return pis;
}
