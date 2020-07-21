//
//  T95-unique-binary-search-trees-ii.c
//  algorithm
//
//  Created by Ankui on 7/21/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/


#include "T95-unique-binary-search-trees-ii.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode* insert_tree(int n) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    memset(node, 0, sizeof(struct TreeNode));
    if (node == NULL) { return NULL; }
    node->val = n;
    return node;
}

struct TreeNode** build_tree(int left, int right, int level, int* total)  {
    struct TreeNode** root = NULL;
    struct TreeNode** left_node = NULL;
    struct TreeNode** right_node = NULL;
    int left_count = 0;
    int right_count = 0;
    int node_count = 0;
    int total_count = 0;
    int i, j, k;
    
    if (left > right) {
        total_count++;
        root = realloc(root, sizeof(struct TreeNode**) * total_count);
        root[total_count - 1] = NULL;
        *total = total_count;
        return root;
    }
    
    for (i = left; i <= right; i++) {
        node_count = left_count = right_count = 0;
        left_node = build_tree(left, i - 1, level + 1, &left_count);
        right_node = build_tree(i + 1, right, level + 1, &right_count);
        
        node_count += left_count * right_count;
        root = realloc(root, sizeof(struct TreeNode**) * (total_count + node_count));
        for (k = 0; k < left_count; k++) {
            for (j = 0; j < right_count; j++) {
                int idx = total_count + (k * right_count + j);
                root[idx] = insert_tree(i);
                root[idx]->left = left_node[k];
                root[idx]->right = right_node[j];
            }
        }
        free(left_node);
        free(right_node);
        total_count += node_count;
        if (level == 0) {
            printf("done %d\n", total_count);
        }
    }
    *total = total_count;
    return root;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    *returnSize = 0;
    if (n <= 0) { return NULL; }
    
    return build_tree(1, n, 0, returnSize);
}
