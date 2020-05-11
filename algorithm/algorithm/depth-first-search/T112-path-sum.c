//
//  T112-path-sum.c
//  algorithm
//
//  Created by Ankui on 5/3/20.
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


void t112dfs(struct TreeNode* root, int sum, bool *result) {
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
    
    t112dfs(root->left, sum, result);
    t112dfs(root->right, sum, result);
}

bool hasPathSum(struct TreeNode* root, int sum) {
    bool result = false;
    t112dfs(root, sum, &result);
    return result;
}
