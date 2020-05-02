//
//  T99-recover-binary-search-tree.c
//  algorithm
//
//  Created by Ankui on 5/2/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/recover-binary-search-tree/

#include "T99-recover-binary-search-tree.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void findNode(struct TreeNode* root, struct TreeNode** prev, struct TreeNode** first, struct TreeNode** second) {
    if (root == NULL) { return; }
    
    findNode(root->left, prev, first, second);
    if (*prev != NULL && (*prev)->val > root->val) {
        *second = root;
        
//        if (*first != NULL) return;
//        *first = *prev;
        
        if (*first == NULL) {
            *first = *prev;
        }
        
        
//        *prev = root;
    }
    *prev = root; // CARE!!!
    findNode(root->right, prev, first, second);
}


void recoverTree(struct TreeNode* root) {
    if (root == NULL) { return; }
    
//    findWrongNode(root);
//    struct TreeNode* tmp = first; // ERROR!!!
//    first->val = second->val;
//    second->val = tmp->val;
    
    struct TreeNode* prev = NULL;
    struct TreeNode* first = NULL;
    struct TreeNode* second = NULL;

    findNode(root, &prev, &first, &second);
    
    int val = first->val;
    first->val = second->val;
    second->val = val;
}





struct TreeNode* prev = NULL;
struct TreeNode* first = NULL;
struct TreeNode* second = NULL;

void findWrongNode(struct TreeNode* root) {
    if (root == NULL) { return; }

    printf("%d\n", root->val);
    findWrongNode(root->left);
    if (prev != NULL && prev->val > root->val) {
        printf("pre-prev-%d\n", prev->val);
        second = root;
        printf("second-%d\n", second->val);
        if (first != NULL) { return; }
        first = prev;
    }
    prev = root;
    printf("prev-%d\n", prev->val);

    findWrongNode(root->right);
}

void recoverTree1(struct TreeNode* root) {
    if (root == NULL) { return; }
    /*
     [3,1,4,null,null,2]
       3
      / \
     1   4
        /
       2
    */

    
    /*
     3
     1
     prev-1
     prev-3
     4
     2
     pre-prev-3
     second-2
     first-3
     prev-2
     prev-4

     ---------------------------
     3
     1
     pre-prev-2
     second-1
     prev-3
     4
     2
     pre-prev-3
     second-2
     prev-4
     */
    
    
    
    /*
     3
     1
     prev-1
     prev-3
     4
     2
     pre-prev-3
     second-2
     first-3
     prev-2
     prev-4
     
     -----------------------
     3
     1
     pre-prev-3
     second-1
     prev-1
     prev-3
     4
     2
     pre-prev-3
     second-2
     prev-2
     prev-4
     */
    
    
    
    
    
    
    /*
     3
     1
     prev-1
     prev-3
     4
     2
     second-2
     first-3
     prev-2
     prev-4
     
     -------------------------
     3
     1
     second-1
     prev-1
     prev-3
     4
     2
     second-2
     prev-2
     prev-4
     */
    
        
    /*
     3
     1
     4
     2
     second-2
     first-3
     */
    
    /*
     3
     1
     second-1
     4
     2
     second-2
     */
    
    findWrongNode(root);
    int val = first->val;
    first->val = second->val;
    second->val = val;

//    struct TreeNode* tmp = first; // ERROR!!!
//    first->val = second->val;
//    second->val = tmp->val;
}
