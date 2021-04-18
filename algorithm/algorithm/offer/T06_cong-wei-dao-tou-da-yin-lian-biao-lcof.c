//
//  T06_cong-wei-dao-tou-da-yin-lian-biao-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//


// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/


#include "T06_cong-wei-dao-tou-da-yin-lian-biao-lcof.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize) {
    struct ListNode* newHead = NULL;
    struct ListNode* tmp = NULL;
    int count = 0;
    while (head) {
        tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
        count++;
    }
    *returnSize = count;
    int* result = malloc(sizeof(int) *(*returnSize));
    int i = 0;
    while (newHead) {
        result[i++] = newHead->val;
        newHead = newHead->next;
    }
    return result;
}
