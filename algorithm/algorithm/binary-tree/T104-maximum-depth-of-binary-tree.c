//
//  T104-maximum-depth-of-binary-tree.c
//  algorithm
//
//  Created by Ankui on 7/22/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/


#include "T104-maximum-depth-of-binary-tree.h"
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
    
    return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
}
