//
//  T14-flatten-binary-tree-to-linked-list.c
//  algorithm
//
//  Created by Ankui on 5/13/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

#include "T14-flatten-binary-tree-to-linked-list.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void flatten(struct TreeNode* root) {
    if (root == NULL) { return; }
    
    struct TreeNode* preRight = root->right;
    root->right = root->left;
    root->left = NULL;
    
    struct TreeNode* lastRight = root;
    while (lastRight->right != NULL) {
//        lastRight->right = lastRight->right->right; // ERROR!!!
        lastRight = lastRight->right;
    }
    lastRight->right = preRight;
    
    flatten(root->right);
}
