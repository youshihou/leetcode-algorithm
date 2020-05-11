//
//  T333-largest-bst-subtree.c
//  algorithm
//
//  Created by Ankui on 5/2/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/largest-bst-subtree/

#include "T333-largest-bst-subtree.h"
#include "algorithm-common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct Info {
    struct TreeNode* root;
    int size;
    int max;
    int min;
};


struct Info* getInfo(struct TreeNode* root) {
    if (root == NULL) { return NULL; }
    
    struct Info* li = getInfo(root->left);
    
    
    struct Info* ri = getInfo(root->right);
    
    
    /*
     1. li != NULL && ri != NULL
        && li->root == root->left && root->val > li->max
        && ri->root == root->right && root->val < ri->min
     2. li != NULL && ri == NULL
        && li->root == roo->left && root->val > li->max
     3. li == NULL && ri != NULL
        && ri->root == root->right && root->val < ri->min
     4. li == NULL && ri == NULL
     */
    
    int leftSize = -1;
    int rightSize = -1;
    int max = root->val;
    int min = root->val;
    
    if (li == NULL) {
        leftSize = 0;
    } else if (li->root == root->left && root->val > li->max) {
        leftSize = li->size;
        min = li->min;
    }
    if (ri == NULL) {
        rightSize = 0;
    } else if (ri->root == root->right && root->val < ri->min) {
        rightSize = ri->size;
        max = ri->max;
    }
    
    if (leftSize >= 0 && rightSize >= 0) {
        struct Info* info = malloc(sizeof(struct Info));
        info->root = root;
        info->size = 1 + leftSize + rightSize;
        info->max = max;
        info->min = min;
        return info;
    }
    
    
    if (li != NULL && ri != NULL) {
        return li->size > ri->size ? li : ri;
    }
    
    return li != NULL ? li : ri;
}

int largestBSTSubtree(struct TreeNode* root) {
    return root == NULL ? 0 : getInfo(root)->size;
}
