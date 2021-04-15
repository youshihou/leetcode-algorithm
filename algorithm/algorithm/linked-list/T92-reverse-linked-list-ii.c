//
//  T92-reverse-linked-list-ii.cpp
//  algorithm
//
//  Created by Ankui on 8/28/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/reverse-linked-list-ii/


#include "T92-reverse-linked-list-ii.hpp"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * reverseList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) { return NULL; }
    struct ListNode *newHead = NULL;
    struct ListNode *tmp = NULL;
    while (head) {
        tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
    }
    return newHead;
}


struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *newHead = malloc(sizeof(struct ListNode));
    struct ListNode *
    
    return newHead->next;
}
