//
//  T237-delete-node-in-a-linked-list.c
//  algorithm
//
//  Created by Ankui on 7/13/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/delete-node-in-a-linked-list/


#include "T237-delete-node-in-a-linked-list.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
