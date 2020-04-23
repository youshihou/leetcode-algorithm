//
//  T160-intersection-of-two-linked-lists.c
//  algorithm
//
//  Created by Ankui on 4/22/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "T160-intersection-of-two-linked-lists.h"
#include "linked-list-common.h"

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
        curA = curA == NULL ? headB : curA->next;
        curB = curB == NULL ? headA : curB->next;
        
        // when no intersection, then curA->next = NULL && curB->next == NULL, could not exit loop!!!
//        curA = curA->next == NULL ? headB : curA->next;
//        curB = curB->next == NULL ? headA : curB->next;
    }

    return curA;
}
