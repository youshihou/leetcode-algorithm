//
//  T27-er-cha-shu-de-jing-xiang-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/


#include "T27-er-cha-shu-de-jing-xiang-lcof.h"
#include "algorithm-common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mirrorTree(struct TreeNode* root) {
    if (root == NULL) { return root; }
    
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;
}

struct TreeNode* mirrorTree1(struct TreeNode* root) {
    if (root == NULL) { return root; }
    
    struct TreeNode* tmp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(tmp);
    return root;
}
