//
//  T203-remove-linked-list-elements.c
//  algorithm
//
//  Created by Ankui on 4/21/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/remove-linked-list-elements/

#include "T203-remove-linked-list-elements.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode* tmp = malloc(sizeof(struct ListNode));
    tmp->next = head;
    
    struct ListNode* cur = head;
    struct ListNode* prev = tmp;
    while (cur != NULL) {
        if (cur->val == val) {
            prev->next = cur->next;
        } else {
            prev = cur;
        }
        cur = cur->next;
    }
    head = tmp->next;
    free(tmp);
    
    return head;
}


struct ListNode* removeElements2(struct ListNode* head, int val) {
    if (head == NULL) { return head; }
    if (head->next == NULL && val == head->val) {
        return NULL;
    }
    
    struct ListNode* newHead = malloc(sizeof(struct ListNode));
    struct ListNode* newTail = newHead;
    
    while (head != NULL) {
        if (val != head->val) {
            newTail->next = head;
            newTail = head;
        }
        head = head->next;
    }

    newTail->next = NULL;
    
    return newHead->next;
}



struct ListNode* removeElements1(struct ListNode* head, int val) {
    if (head == NULL) { return head; }
    if (head->next == NULL && val == head->val) {
        return NULL;
    }
    
    struct ListNode* newHead = NULL;
    struct ListNode* newTail = NULL;
    
    while (head != NULL) {
        if (val != head->val) {
            if (newTail == NULL) { // first !!!
                newHead = head;
                newTail = head;
            } else { // other !!!
                newTail->next = head;
//                newTail = newTail->next;
                newTail = head;
            }
        }
        head = head->next;
    }
    
//    if (newTail == NULL) {
//        return NULL;
//    } else {
//        newTail->next = NULL;
//    }
    
    if (newTail) {
        newTail->next = NULL;
    }
    
    return newHead;
}
