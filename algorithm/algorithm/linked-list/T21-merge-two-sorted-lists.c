//
//  T21-merge-two-sorted-lists.c
//  algorithm
//
//  Created by Ankui on 5/10/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/merge-two-sorted-lists/

#include "T21-merge-two-sorted-lists.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) { return l2; }
    if (l2 == NULL) { return l1; }
    
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
//        l2->next = mergeTwoLists(l2->next, l1);
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}



struct ListNode* mergeTwoLists2(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) { return l2; }
    if (l2 == NULL) { return l1; }
    
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->next = NULL;
    
    struct ListNode* cur = head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            cur->next = l1;
            cur = cur->next; // CARE!!!
            l1 = l1->next; // CARE!!!
        } else {
            cur->next = l2;
            cur = cur->next; // CARE!!!
            l2 = l2->next; // CARE!!!
        }
    }
    
    if (l1 == NULL) {
        cur->next = l2;
    } else if (l2 == NULL) {
        cur->next = l1;
    }
    
    return head->next;
}


struct ListNode* mergeTwoLists1(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) { return l2; }
    if (l2 == NULL) { return l1; }
    
    struct ListNode* head = NULL;
    
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2= l2->next;
    }
    
    struct ListNode* cur = head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        } else {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
    }
    
    if (l1 == NULL) {
        cur->next = l2;
    } else if (l2 == NULL) {
        cur->next = l1;
    }
    
    return head;
}
