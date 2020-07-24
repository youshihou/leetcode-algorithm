//
//  T173-binary-search-tree-iterator.c
//  algorithm
//
//  Created by Ankui on 7/24/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/binary-search-tree-iterator/


#include "T173-binary-search-tree-iterator.h"
#include "algorithm-common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {

} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    return NULL;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) {
    return 0;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) {
    return false;
}

void bSTIteratorFree(BSTIterator* obj) {

}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
