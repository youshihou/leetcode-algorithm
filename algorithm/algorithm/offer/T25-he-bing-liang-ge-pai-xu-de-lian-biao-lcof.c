//
//  T25-he-bing-liang-ge-pai-xu-de-lian-biao-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/


#include "T25-he-bing-liang-ge-pai-xu-de-lian-biao-lcof.h"
#include "algorithm-common.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* __mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL || l2 == NULL) { return NULL; }
    struct ListNode* newHead = malloc(sizeof(struct ListNode));
    struct ListNode* cur = newHead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ?: l2;
    return newHead->next;
}
