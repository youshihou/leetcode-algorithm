//
//  T572-subtree-of-another-tree.c
//  algorithm
//
//  Created by Ankui on 4/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/subtree-of-another-tree/

#include "T572-subtree-of-another-tree.h"
#include "algorithm-common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void serialize(struct TreeNode* s, char* r) {
    if (s->left == NULL) {
        strcat(r, "#!");
    } else {
        serialize(s->left, r);
    }
    if (s->right == NULL) {
        strcat(r, "#!");
    } else {
        serialize(s->right, r);
    }
    
    char val[128]; // CARE!!!
    sprintf(val, "%d!", s->val);
    strcat(r, val);
}

char* post_serialize(struct TreeNode* s) {
    char *r = malloc(sizeof(char) * 102400); // CARE!!!
    memset(r, 0, sizeof(char) * 102400); // CARE!!!
    serialize(s, r);
    return r;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (s == NULL || t == NULL) { return false; }
    
    char* rs = post_serialize(s);
    char* ts = post_serialize(t);
    return strstr(rs, ts);
}
