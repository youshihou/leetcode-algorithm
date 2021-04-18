//
//  T18_shan-chu-lian-biao-de-jie-dian-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/


#include "T18_shan-chu-lian-biao-de-jie-dian-lcof.h"
#include "algorithm-common.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteNode(struct ListNode* head, int val) {
    if (head == NULL) { return head; }
    if (head->val == val) { return head->next; }
        
    struct ListNode* cur = head;
    while (cur->next && cur->next->val != val) {
        cur = cur->next;
    }
    if (cur->next) {
        cur->next = cur->next->next;
    }
    return head;
}


struct ListNode* deleteNode3(struct ListNode* head, int val) {
    if (head == NULL) { return head; }
    if (head->val == val) { return head->next; }
        
    struct ListNode* newHead = malloc(sizeof(struct ListNode));
    newHead->next = head;
    struct ListNode* cur = newHead;
    while (cur->next->val != val) {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    return newHead->next;
}


struct ListNode* deleteNode1(struct ListNode* head, int val) {
    if (head == NULL) { return head; }
    if (head->val == val) { return head->next; }
        
    struct ListNode* pre = head;
    struct ListNode* cur = head->next;
    while (cur && cur->val != val) {
        pre = cur;
        cur = cur->next;
    }
    if (pre) {
        pre->next = cur->next;
    }
    return head;
}

