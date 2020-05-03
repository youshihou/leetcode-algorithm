//
//  T112-path-sum.c
//  algorithm
//
//  Created by Ankui on 5/3/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/path-sum/

#include "T112-path-sum.h"
#include "depth-first-search-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void dfs(struct TreeNode* root, int sum, bool *result) {
    if (root == NULL) { return; }
    
    sum -= root->val;
//    if (root->left == NULL && root->right == NULL) {
//        if (sum == 0) {
//            *result = true;
//        }
//        return;
//    }
    if (root->left == NULL && root->right == NULL && sum == 0) {
        *result = true;
    }
    
    dfs(root->left, sum, result);
    dfs(root->right, sum, result);
}

bool hasPathSum(struct TreeNode* root, int sum) {
    bool result = false;
    dfs(root, sum, &result);
    return result;
}
