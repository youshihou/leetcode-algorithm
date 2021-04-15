//
//  T92-reverse-linked-list-ii.c
//  algorithm
//
//  Created by Ankui on 8/28/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/reverse-linked-list-ii/


#include "T92-reverse-linked-list-ii.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * reverseList(struct ListNode *head, struct ListNode *tail) {
    if (head == tail || head->next == tail) { return head; }
    struct ListNode *l = NULL;
    struct ListNode *r = tail;
    while (head != tail) {
        l = head->next;
        head->next = r;
        r = head;
        head = l;
    }
    return r;
}


struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *newHead = malloc(sizeof(struct ListNode));
    newHead->next = head;
    struct ListNode *cur = newHead;
    struct ListNode *l = NULL;
    struct ListNode *r = NULL;
    for (int i = 0; i <= n; i++) {
        if (i == m - 1) {
            l = cur;
        }
        cur = cur->next;
    }
    r = cur;
    l->next = reverseList(l->next, r);
    return newHead->next;
}
