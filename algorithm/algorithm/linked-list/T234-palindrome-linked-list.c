//
//  T234-palindrome-linked-list.c
//  algorithm
//
//  Created by Ankui on 4/23/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/palindrome-linked-list/

#include "T234-palindrome-linked-list.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode_(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    while (fast->next != NULL && fast->next->next != NULL) { // CARE!!! &&
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct ListNode* t234_reverseList(struct ListNode* head) {
    struct ListNode* newHead = NULL;
    while (head != NULL) {
        struct ListNode* temp = head->next;
        head->next = newHead;
        newHead = head;
        head = temp;
    }
    return newHead;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return true; }
    if (head->next->next == NULL) { return head->val == head->next->val; }
    
    struct ListNode* middle = middleNode_(head);
    struct ListNode* rHead = t234_reverseList(middle->next); // CARE!!!
    struct ListNode* lhead = head;
    struct ListNode* rOldHead = rHead;
    
    bool result = true;
    while (rHead != NULL) {
        if (lhead->val != rHead->val) {
            result = false;
            break;
        }
        lhead = lhead->next;
        rHead = rHead->next;
    }
    
    // restore list
    t234_reverseList(rOldHead);
    
    return result;
}

bool isPalindrome1(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return true; }
    if (head->next->next == NULL) { return head->val == head->next->val; }
    
    struct ListNode* middle = middleNode_(head);
    struct ListNode* rHead = t234_reverseList(middle->next); // CARE!!!
    struct ListNode* lhead = head;
    
    while (rHead != NULL) {
        if (lhead->val != rHead->val) { return false; }
        lhead = lhead->next;
        rHead = rHead->next;
    }
    
    return true;
}
