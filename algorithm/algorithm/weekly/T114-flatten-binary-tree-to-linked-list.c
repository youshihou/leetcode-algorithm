//
//  T114-flatten-binary-tree-to-linked-list.c
//  algorithm
//
//  Created by Ankui on 5/13/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

#include "T114-flatten-binary-tree-to-linked-list.h"
#include "algorithm-common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



void flatten_(struct TreeNode* root, struct TreeNode** prev) {
    if (root == NULL) { return; }
    
    flatten_(root->right, prev);
    flatten_(root->left, prev);
    
    if (prev != NULL) {
        root->right = *prev;
        root->left = NULL;
    }
    
    *prev = root;
}


void flatten(struct TreeNode* root) {
    if (root == NULL) { return; }
    
    struct TreeNode* prev = NULL;
    flatten_(root, &prev);
}





void flatten3(struct TreeNode* root) {
    while (root != NULL) {
        if (root->left != NULL) {
            struct TreeNode* preRight = root->right;
            root->right = root->left;
            root->left = NULL;
            struct TreeNode* lastRight = root;
            while (lastRight->right != NULL) {
                lastRight = lastRight->right;
            }
            lastRight->right = preRight;
        }
        
        root = root->right;
    }
}




void flatten2(struct TreeNode* root) {
    while (root != NULL) {
        struct TreeNode* preRight = root->right;
        root->right = root->left;
        root->left = NULL;
        struct TreeNode* lastRight = root;
        while (lastRight->right != NULL) {
            lastRight = lastRight->right;
        }
        lastRight->right = preRight;
        
        root = root->right;
    }
}


void flatten1(struct TreeNode* root) {
    if (root == NULL) { return; }
    
    struct TreeNode* preRight = root->right;
    root->right = root->left;
    root->left = NULL;
    
    struct TreeNode* lastRight = root;
    while (lastRight->right != NULL) {
//        lastRight->right = lastRight->right->right; // ERROR!!!
        lastRight = lastRight->right;
    }
    lastRight->right = preRight;
    
    flatten(root->right);
}
