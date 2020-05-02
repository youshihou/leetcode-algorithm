//
//  T236-lowest-common-ancestor-of-a-binary-tree.c
//  algorithm
//
//  Created by Ankui on 5/2/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include "T236-lowest-common-ancestor-of-a-binary-tree.h"
#include "binary-tree-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || p == root || q == root) { return root; }
    
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
//    if (left != NULL && right == NULL) {
//        return left;
//    }
//    if (left == NULL && right != NULL) {
//        return right;
//    }
//    return root; // Error!!!
    
    
//    if (left != NULL && right != NULL) {
//        return root;
//    }
//    if (left != NULL && right == NULL) {
//        return left;
//    }
//    if (left == NULL && right != NULL) {
//        return right;
//    }
//    return NULL;
    
    if (left != NULL && right != NULL) { return root; }
    return left != NULL ? left : right;
}
