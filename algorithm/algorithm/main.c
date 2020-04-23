//
//  main.c
//  algorithm
//
//  Created by Ankui on 4/20/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include <stdio.h>
#include "T88-merge-sorted-array.h"
#include "T16-sub-sort-lcci.h"
#include "T234-palindrome-linked-list.h"



int main(int argc, const char * argv[]) {
    
    {   // T88
        int nums1[1] = {0};
        int nums2[1] = {1};
        merge(nums1, 1, 0, nums2, 1, 1);
    }
    
    {
        // T16
        int array[] = {};
        int size = 0;
        subSort(array, 0, &size);
        int array2[] = {1,2,4,7,10,11,7,12,6,7,16,18,19};
        subSort(array2, 13, &size);
    }
    
    {
        // T234
        struct ListNode* head = malloc(sizeof(struct ListNode));
        head->val = 1;
        struct ListNode* two = malloc(sizeof(sizeof(struct ListNode)));
        two->val = 2;
        head->next = two;
        struct ListNode* three = malloc(sizeof(sizeof(struct ListNode)));
        three->val = 3;
        head->next->next = three;
        struct ListNode* four = malloc(sizeof(sizeof(struct ListNode)));
        four->val = 2;
        head->next->next->next = four;
        struct ListNode* five = malloc(sizeof(sizeof(struct ListNode)));
        five->val = 1;
        five->next = NULL;
        head->next->next->next->next = five;
    
//        while (head != NULL) {
//            printf("%d->", head->val);
//            head = head->next;
//        }
//        printf("\n");
//        printf("------------------\n");

        isPalindrome(head);
        
        while (head != NULL) {
            printf("%d->", head->val);
            head = head->next;
        }
        printf("\n");

    }
    

    return 0;
}
