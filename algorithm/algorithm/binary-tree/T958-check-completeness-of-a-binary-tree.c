//
//  T958-check-completeness-of-a-binary-tree.c
//  algorithm
//
//  Created by Ankui on 7/22/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree/


#include "T958-check-completeness-of-a-binary-tree.h"
#include "algorithm-common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isCompleteTree(struct TreeNode* root) {
    if (root == NULL) { return root; }
    
    struct TreeNode* queue[200];
    memset(queue, 0, sizeof(queue));
    
    int front = 0;
    int rear = 0;
    queue[rear] = root;
    rear++;
    
    struct TreeNode* prev = root;
    struct TreeNode* curr;
    while (front != rear) {
        curr = queue[front];
        front++;
        
        if (prev == NULL && curr != NULL) { return false; }
        
        if (curr != NULL) {
            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
        
        prev = curr;
    }
    return true;
}


bool isCompleteTree1(struct TreeNode* root) {
    if (root == NULL) { return root; }
    
    bool leaf = false;
    ObjectQueue *q = object_queue_create();
    object_queue_enqueue(q, root);
    while (!object_queue_isEmpty(q)) {
        struct TreeNode* node = object_queue_dequeue(q);
        bool is_leaf = node->left == NULL && node->right == NULL;
        if (leaf && !is_leaf) { return false; }
        
        if (node->left) {
            object_queue_enqueue(q, node->left);
        } else if (node->right) {
            return false;
        }
        
        if (node->right) {
            object_queue_enqueue(q, node->right);
        } else {
            leaf = true;
        }
    }
    object_queue_destroy(q);
    
    return true;
}
