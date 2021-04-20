//
//  T32-II_cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof.c
//  algorithm
//
//  Created by Ankui on 4/20/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/


#include "T32-II_cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof.h"
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) { return NULL; }
    int size = 10000;
    struct TreeNode* queue[size];
    int** list = malloc(sizeof(struct TreeNode*) * size);
    *returnColumnSizes = malloc(sizeof(int) * size);
    int front = 0, tail = 0;
    queue[tail++] = root;
    while (front != tail) {
        size = tail - front;
        (*returnColumnSizes)[*returnSize] = size;
        list[*returnSize] = malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            list[*returnSize][i] = node->val;
            if (node->left) {
                queue[tail++] = node->left;
            }
            if (node->right) {
                queue[tail++] = node->right;
            }
        }
        (*returnSize)++;
    }
    return list;
}



int** __levelOrder1(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) { return NULL; }
    int size = 10000;
    struct TreeNode* queue[size];
    int** list = malloc(sizeof(struct TreeNode*) * size);
    *returnColumnSizes = malloc(sizeof(int) * size);
    int head = 0, rear = 0;
    queue[rear++] = root;
    while (head != rear) {
        int preRear = rear;
        int k = 0;
        list[*returnSize] = malloc(sizeof(int) * (preRear - head));
        while (head < preRear) {
            struct TreeNode* p = queue[head];
            list[*returnSize][k++] = p->val;
            if (p->left) {
                queue[rear++] = p->left;
            }
            if (p->right) {
                queue[rear++] = p->right;
            }
            head++;
        }
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
    }
    return list;
}
