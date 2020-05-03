//
//  T113-path-sum-ii.c
//  algorithm
//
//  Created by Ankui on 5/3/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/path-sum-ii/

#include "T113-path-sum-ii.h"
#include "depth-first-search-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes, int* array, int** list, int idx) {
    if (root == NULL) { return; }
    sum -= root->val;
    array[idx++] = root->val;
    if (root->left == NULL && root->right == NULL) {
        if (sum == 0) {
            list[*returnSize] = malloc(sizeof(int) * idx);
            memcpy(list[*returnSize], array, sizeof(int) * idx);
            (*returnColumnSizes)[*returnSize] = idx;
            (*returnSize)++;
            return;
        }
        return;
    }
    
    dfs(root->left, sum, returnSize, returnColumnSizes, array, list, idx);  // ERROR!!! idx + 1
    dfs(root->right, sum, returnSize, returnColumnSizes, array, list, idx); // ERROR!!! idx + 1
}


int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    (*returnColumnSizes)[0] = 0;
    if (root == NULL) { return NULL; }
        
    int len = 1024; // magic number
    int** list = malloc(sizeof(int*) * len);
    memset(list, 0, sizeof(int*) * len);
    *returnColumnSizes = malloc(sizeof(int) * len);
    
    int* array = malloc(sizeof(int) * len);
    memset(array, 0, sizeof(int) * len);
    
    dfs(root, sum, returnSize, returnColumnSizes, array, list, 0);
    
    return list;
}
