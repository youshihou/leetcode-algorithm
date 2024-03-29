//
//  T68-II_er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof.c
//  algorithm
//
//  Created by Ankui on 5/2/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/

#include "T68-II_er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* lowestCommonAncestor1(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || p == root || q == root) { return root; }
    struct TreeNode* left = lowestCommonAncestor1(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor1(root->right, p, q);
    if (left && right) { return root; }
    return left ?: right;
}
