//
//  T54-er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/


#include "T54-er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof.h"
#include "algorithm-common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getCount(struct TreeNode* root) {
    if (root == NULL) { return 0; }
    int leftCount = getCount(root->left);
    int rightCount = getCount(root->right);
    return leftCount + rightCount + 1;
}

void t54dfs(struct TreeNode* root, int* list, int* count) {
    if (root == NULL) { return; }
    t54dfs(root->left, list, count);
    list[(*count)++] = root->val;
    t54dfs(root->right, list, count);
}

int kthLargest(struct TreeNode* root, int k) {
    int size = getCount(root);
    // int* list = malloc(sizeof(int) * size);
    int list[size];
    int count = 0;
    t54dfs(root, list, &count);
    return list[size - k];
}
