//
//  T112-path-sum.c
//  algorithm
//
//  Created by Ankui on 7/7/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/path-sum/


#include "T112-path-sum.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs_t112(struct TreeNode* root, int sum, bool *result) {
    if (root == NULL) { return; }
    
    sum -= root->val;
    if (root->left == NULL && root->right == NULL && sum == 0) {
        *result = true;
    }
    
    dfs_t112(root->left, sum, result);
    dfs_t112(root->right, sum, result);
}

bool hasPathSum_(struct TreeNode* root, int sum) {
    bool result = false;
    dfs_t112(root, sum, &result);
    return result;
}
