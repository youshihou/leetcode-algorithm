//
//  T52-liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof.c
//  algorithm
//
//  Created by Ankui on 4/19/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/


#include "T52-liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof.h"
#include "algorithm-common.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) { return NULL; }
    
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    while (curA != curB) {
        curA = curA ? curA->next : headB;
        curB = curB ? curB->next : headA;
    }
    return curA;
}
