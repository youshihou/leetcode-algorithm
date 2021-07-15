//
//  T2-add-two-numbers.c
//  algorithm
//
//  Created by Ankui on 4/22/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/add-two-numbers/

#include "T2-add-two-numbers.h"
#include "algorithm-common.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) { return l2; }
    if (l2 == NULL) { return l1; }
    
    struct ListNode* virtualHead = malloc(sizeof(struct ListNode));
//    virtualHead->next = NULL; // MUST!!!
    struct ListNode* last = virtualHead;
    
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
        int v1 = 0;
        if (l1) {
            v1 = l1->val;
            l1 = l1->next;
        }
        int v2 = 0;
        if (l2) {
            v2 = l2->val;
            l2 = l2->next;
        }
        
        int sum = v1 + v2 + carry;
        carry = sum / 10;
        
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL; // MUST!!!
        last->next = node;
        last = node;
    }
    
    if (carry) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL; // MUST!!!
        last->next = node;
//        last = node;
    }
    
    return virtualHead->next;
}
