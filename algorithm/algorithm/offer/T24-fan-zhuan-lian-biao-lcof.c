//
//  T24-fan-zhuan-lian-biao-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/


#include "T24-fan-zhuan-lian-biao-lcof.h"
#include "algorithm-common.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* __reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    struct ListNode* newHead = NULL;
    struct ListNode* tmp = NULL;
    while (head) {
        tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
    }
    return newHead;
}


struct ListNode* _reverseList1(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    struct ListNode* newHead = _reverseList1(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
