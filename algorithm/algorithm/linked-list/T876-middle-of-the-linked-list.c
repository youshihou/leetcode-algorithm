//
//  T876-middle-of-the-linked-list.c
//  algorithm
//
//  Created by Ankui on 7/14/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/middle-of-the-linked-list/


#include "T876-middle-of-the-linked-list.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
