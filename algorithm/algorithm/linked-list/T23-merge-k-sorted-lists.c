//
//  T23-merge-k-sorted-lists.c
//  algorithm
//
//  Created by Ankui on 5/10/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/merge-k-sorted-lists/

#include "T23-merge-k-sorted-lists.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists_(struct ListNode* head, struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) { return l2; }
    if (l2 == NULL) { return l1; }
    
    head->next = NULL;
    struct ListNode* cur = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        } else {
            cur->next = l2;
            cur =cur->next;
            l2 = l2->next;
        }
    }
    
    if (l1 == NULL) {
        cur->next = l2;
    } else {
        cur->next = l1;
    }
    
    return head->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize <= 0) { return NULL; }
        
    struct ListNode* head = malloc(sizeof(struct ListNode));
    
    int step = 1;
    while (step < listsSize) {
        int next = step << 1;
        for (int i = 0; i + step < listsSize; i += next) {
            lists[i] = mergeTwoLists_(head, lists[i], lists[i + step]);
        }
        step = next;
    }
    
    return lists[0];
}




struct ListNode* mergeKLists4(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize <= 0) { return NULL; }
        
    struct ListNode* head = malloc(sizeof(struct ListNode));
    
    for (int i = 1; i < listsSize; i++) {
        lists[0] = mergeTwoLists_(head, lists[0], lists[i]);
    }
    
    return lists[0];
}





struct ListNode* mergeTwoLists3(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) { return l2; }
    if (l2 == NULL) { return l1; }
    
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* cur = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        } else {
            cur->next = l2;
            cur =cur->next;
            l2 = l2->next;
        }
    }
    
    if (l1 == NULL) {
        cur->next = l2;
    } else {
        cur->next = l1;
    }
    
    return head->next;
}


struct ListNode* mergeKLists3(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize <= 0) { return NULL; }
        
    for (int i = 1; i < listsSize; i++) { // CARE!!! i is 1 not 0
        lists[0] = mergeTwoLists3(lists[0], lists[i]); // CARE!!! is i not i + 1
    }
    
    return lists[0];
}


struct ListNode* mergeKLists2(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize <= 0) { return NULL; }
    
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* cur = head;
    while (true) {
        int minIdx = -1;
        for (int i = 0; i < listsSize; i++) {
            if (lists[i] == NULL) { continue; }
            if (minIdx == -1 || lists[i]->val < lists[minIdx]->val) {
                minIdx = i;
            }
        }
        if (minIdx == -1) { break; }
        
        cur->next = lists[minIdx];
        cur = cur->next;
        lists[minIdx] = lists[minIdx]->next; // CARE!!! MUST!!!
    }

    return head->next;
}


int t23cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

struct ListNode* mergeKLists1(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize <= 0) { return NULL; }
    
    int array[10240];
    int count = 0;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* list = lists[i];
        while (list != NULL) {
            array[count++] = list->val;
            list = list->next;
        }
    }
    qsort(array, count, sizeof(int), t23cmp);
    
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* cur = head;
    for (int i = 0; i < count; i++) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = array[i];
        node->next = NULL;
        cur->next = node;
        cur = cur->next;
    }
    
    return head->next;
}
