//
//  T110-balanced-binary-tree.c
//  algorithm
//
//  Created by Ankui on 7/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/balanced-binary-tree/


#include "T110-balanced-binary-tree.h"
#include "algorithm-common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int height(struct TreeNode * root) {
    if (root == NULL) { return 0; }
    return 1 + fmax(height(root->left), height(root->right));
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) { return true; }
    
    return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
