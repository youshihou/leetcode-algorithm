//
//  T226-invert-binary-tree.c
//  algorithm
//
//  Created by Ankui on 7/22/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/invert-binary-tree/


#include "T226-invert-binary-tree.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) { return root; }
    
    struct TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

struct TreeNode* invertTree1(struct TreeNode* root) {
    if (root == NULL) { return root; }
    
    invertTree(root->left);
    invertTree(root->right);
    
    struct TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    return root;
}

struct TreeNode* invertTree2(struct TreeNode* root) {
    if (root == NULL) { return root; }
    
    invertTree(root->left);
    
    struct TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
    invertTree(root->left); // CARE!!!
    
    return root;
}



struct TreeNode* invertTree3(struct TreeNode* root) {
    if (root == NULL) { return root; }
    
    ObjectQueue *q = object_queue_create();
    object_queue_enqueue(q, root);
    while (!object_queue_isEmpty(q)) {
        struct TreeNode* node = object_queue_dequeue(q);
        struct TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;

        if (node->left) {
            object_queue_enqueue(q, node->left);
        }
        if (node->right) {
            object_queue_enqueue(q, node->right);
        }
    }
    object_queue_destroy(q);
    
    return root;
}
