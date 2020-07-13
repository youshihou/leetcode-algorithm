//
//  T141-linked-list-cycle.c
//  algorithm
//
//  Created by Ankui on 7/13/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/linked-list-cycle/

#include "T141-linked-list-cycle.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) { return false; }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    
    while (fast != NULL && fast->next != NULL) { // CARE!!! 
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { return true; }
    }
    
    return false;
}
