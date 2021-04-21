//
//  T9-remove-nth-node-from-end-of-list.c
//  algorithm
//
//  Created by Ankui on 4/21/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/


#include "T9-remove-nth-node-from-end-of-list.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL || n <= 0) { return head; }
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* first = head;
    struct ListNode* second = dummy;
    while (n--) {
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}


struct MyStack {
    struct ListNode* val;
    struct MyStack* next;
};

struct ListNode* removeNthFromEnd2(struct ListNode* head, int n) {
    if (head == NULL || n <= 0) { return head; }
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* cur = dummy;
    struct MyStack* stack = NULL;
    while (cur) {
        struct MyStack* tmp = malloc(sizeof(struct MyStack));
        tmp->val = cur;
        tmp->next = stack;
        stack = tmp;
        cur = cur->next;
    }
    for (int i = 0; i < n; i++) {
        struct MyStack* tmp = stack->next;
        free(stack);
        stack = tmp;
    }
    struct ListNode* pre = stack->val;
    pre->next = pre->next->next;
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}


struct ListNode* removeNthFromEnd1(struct ListNode* head, int n) {
    if (head == NULL || n <= 0) { return head; }
    
    struct ListNode* newHead = malloc(sizeof(struct ListNode));
    newHead->next = head;
    struct ListNode* cur = newHead;
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    int i = 0;
    while (cur->next && i < count) {
        if (i == count - n - 1) {
            break;
        }
        cur = cur->next;
        i++;
    }
    if (cur->next) {
        cur->next = cur->next->next;
    }
    
    return newHead->next;
}
