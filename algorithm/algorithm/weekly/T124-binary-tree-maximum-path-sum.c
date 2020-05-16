//
//  T124-binary-tree-maximum-path-sum.c
//  algorithm
//
//  Created by Ankui on 5/12/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

#include "T124-binary-tree-maximum-path-sum.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int value(struct TreeNode* node, int* sum) {
    if (node == NULL) { return 0; }
    
    int lv = value(node->left, sum);
    lv = MAX(lv, 0);
    int rv = value(node->right, sum);
    rv = MAX(rv, 0);
    
    *sum = MAX(*sum, node->val + lv + rv);
    
    return node->val + MAX(lv, rv);
}

int maxPathSum(struct TreeNode* root) {
    int sum = INT_MIN;
    value(root, &sum);
    return sum;
}
