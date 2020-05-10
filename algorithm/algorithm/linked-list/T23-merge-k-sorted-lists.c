//
//  T23-merge-k-sorted-lists.c
//  algorithm
//
//  Created by Ankui on 5/10/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/merge-k-sorted-lists/

#include "T23-merge-k-sorted-lists.h"
#include "linked-list-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int t23cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize <= 0) { return NULL; }
    
    return NULL;
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
