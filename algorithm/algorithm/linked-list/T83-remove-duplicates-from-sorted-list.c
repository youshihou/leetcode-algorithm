//
//  T83-remove-duplicates-from-sorted-list.c
//  algorithm
//
//  Created by Ankui on 7/14/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/


#include "T83-remove-duplicates-from-sorted-list.h"
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
    
    struct ListNode* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val == curr->val) {
            struct ListNode *tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
        } else {
            curr = curr->next;
        }
    }
    
    return head;
}
