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

    int height = 0;
    int level_size = 1;
    ObjectQueue *q = object_queue_create();
    object_queue_enqueue(q, root);
    while (!object_queue_isEmpty(q)) {
        struct TreeNode* node = object_queue_dequeue(q);
        level_size--;
        if (node->left) {
            object_queue_enqueue(q, node->left);
        }
        if (node->right) {
            object_queue_enqueue(q, node->right);
        }
        if (level_size == 0) {
            level_size = object_queue_size(q);
            height++;
        }
    }
    
    object_queue_destroy(q);
    
    return height;
}




int maxDepth1(struct TreeNode* root) {
    if (root == NULL) { return 0; }
    
    return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
}
