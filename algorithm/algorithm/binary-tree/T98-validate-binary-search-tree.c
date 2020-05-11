//
//  T98-validate-binary-search-tree.c
//  algorithm
//
//  Created by Ankui on 5/11/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/validate-binary-search-tree/

#include "T98-validate-binary-search-tree.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



bool isValidBST_(struct TreeNode* root, struct TreeNode** min, struct TreeNode** max) {
    if (root == NULL) { return true; }
    
    if (*min && root->val <= (*min)->val) { return false; }
    if (*max && root->val >= (*max)->val) { return false; }
    
    if (!isValidBST_(root->left, min, &root)) { return false; }
    if (!isValidBST_(root->right, &root, max)) { return false; }
    
    return true;
}

bool isValidBST(struct TreeNode* root) {
    struct TreeNode* min = NULL;
    struct TreeNode* max = NULL;
    return isValidBST_(root, &min, &max);
}






bool inorder(struct TreeNode* root, struct TreeNode** pre) { //CARE!!! **
    if (root == NULL) { return true; }
    
    if (!inorder(root->left, pre)) { return false; }
    
    if (*pre != NULL && root->val <= (*pre)->val) { return false; } // CARE!!!
    *pre = root;
    
    if (!inorder(root->right, pre)) { return false; }
    
    return true;
}

bool isValidBST1(struct TreeNode* root) {
    struct TreeNode* pre = NULL;
    return inorder(root, &pre);
}
