//
//  T28-dui-cheng-de-er-cha-shu-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/


#include "T28-dui-cheng-de-er-cha-shu-lcof.h"
#include "algorithm-common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool t28dfs(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) { return true; }
    if (left == NULL || right == NULL || left->val != right->val) { return false; }
    return t28dfs(left->left, right->right) && t28dfs(left->right, right->left);
}

bool __isSymmetric(struct TreeNode* root){
    if (root == NULL) { return true; }
    return t28dfs(root->left, root->right);
}
