//
//  T206-reverse-linked-list.c
//  algorithm
//
//  Created by Ankui on 7/13/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/reverse-linked-list/

#include "T206-reverse-linked-list.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    
    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}
