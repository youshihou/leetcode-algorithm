//
//  T108-convert-sorted-array-to-binary-search-tree.c
//  algorithm
//
//  Created by Ankui on 7/3/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

#include "T108-convert-sorted-array-to-binary-search-tree.h"
#include "algorithm-common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedToBST(int* nums, int left, int right) {
    if (left > right) { return NULL; }
    
    int mid = (left + right) >> 1;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = sortedToBST(nums, left, mid - 1);
    root->right = sortedToBST(nums, mid + 1, right);
    
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) { return NULL; }
    
    return sortedToBST(nums, 0, numsSize - 1);
}
