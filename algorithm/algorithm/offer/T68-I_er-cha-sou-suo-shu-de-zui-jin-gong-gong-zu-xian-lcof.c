//
//  T68-I_er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/


#include "T68-I_er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* _lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* result = root;
    while (true) {
        if (p->val < result->val && q->val < result->val) {
            result = result->left;
        } else if (p->val > result->val && q->val > result->val) {
            result = result->right;
        } else {
            break;;
        }
    }
    return result;
}
