//
//  T82-remove-duplicates-from-sorted-list-ii.c
//  algorithm
//
//  Created by Ankui on 7/14/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/


#include "T82-remove-duplicates-from-sorted-list-ii.h"
#include "algorithm-common.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
 
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* curr = dummy;
    while (curr->next && curr->next->next) {
        if (curr->next->val == curr->next->next->val) {
            struct ListNode* tmp = curr->next;
            while (tmp && tmp->next && tmp->val == tmp->next->val) {
                tmp = tmp->next;
            }
            curr->next = tmp->next;
        } else {
            curr = curr->next;
        }
    }
    return dummy->next;
}


struct ListNode* deleteDuplicates2(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* curr = &dummy;

    while (curr->next != NULL && curr->next->next != NULL) {
        if (curr->next->val == curr->next->next->val) {
            struct ListNode* tmp = curr->next;
            while (tmp && tmp->next && tmp->val == tmp->next->val) {
                tmp = tmp->next;
            }
            curr->next = tmp->next;
        } else {
            curr = curr->next;
        }
    }
    
    return dummy.next;
}
