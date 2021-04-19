//
//  T55-I_er-cha-shu-de-shen-du-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/


#include "T55-I_er-cha-shu-de-shen-du-lcof.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root) {
    if (root == NULL) { return 0; }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return fmax(left, right) + 1;
}
