//
//  T55-ping-heng-er-cha-shu-lcof.c
//  algorithm
//
//  Created by Ankui on 7/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/


#include "T55-ping-heng-er-cha-shu-lcof.h"
#include "algorithm-common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode* root) {
    if (root == NULL) { return 0; }
    return 1 + fmax(height(root->left), height(root->right));
}

bool t55_isBalanced(struct TreeNode* root) {
    if (root == NULL) { return true; }
    
    return abs(height(root->left) - height(root->right)) <= 1 && t55_isBalanced(root->left) && t55_isBalanced(root->right);
}
