//
//  T22-lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.c
//  algorithm
//
//  Created by Ankui on 4/18/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/


#include "T22-lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.h"
#include "algorithm-common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
    if (head == NULL || k <= 0) { return head; }
    
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (k--) {
        fast = fast->next;
    }
    
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
