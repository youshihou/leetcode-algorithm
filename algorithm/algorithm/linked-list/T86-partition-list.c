//
//  T86-partition-list.c
//  algorithm
//
//  Created by Ankui on 4/23/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "T86-partition-list.h"
#include "linked-list-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL) { return NULL; }
    
    struct ListNode* lHead = malloc(sizeof(struct ListNode));
    lHead->next = NULL;
    struct ListNode* lLast = lHead;
    
    struct ListNode* rHead = malloc(sizeof(struct ListNode));
    rHead->next = NULL;
    struct ListNode* rLast = rHead;
    
    while (head != NULL) {
        if (x > head->val) {
            lLast->next = head;
            lLast = head;
        } else {
            rLast->next = head;
            rLast = head;
        }
        head = head->next;
    }
    
    // MUST!!!
    // if the last of the origin list A node's val >= x, A->next node's val always < x; so rLast->next = A->next
    rLast->next = NULL;
    
    lLast->next = rHead->next;
    
    return lHead->next;
}
