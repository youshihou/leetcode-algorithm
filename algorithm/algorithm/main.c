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
#include "stack.h"
#include "T654-maximum-binary-tree.h"
#include "T01-09-string-rotation-lcci.h"
#include "T572-subtree-of-another-tree.h"
#include "T151-reverse-words-in-a-string.h"
#include "T3-longest-substring-without-repeating-characters.h"
#include "T62-unique-paths.h"

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
        
//        while (head != NULL) {
//            printf("%d->", head->val);
//            head = head->next;
//        }
//        printf("\n");

    }
    

    {
//        Stack *s = create();
//        push(s, 1);
//        printf("push value is 1\n");
//
//        int x = top(s);
//        printf("top value is %d\n", x);
//
//        x = pop(s);
//        printf("pop value is %d\n", x);
//
//        int i = 0;
//        while (i < 5) {
//            push(s, i++);
//        }
//        printf("top is stack value is %d\n", s->next->val);
    }
    
    {
//        int a[] = {3, 2, 1, 6, 0, 5};
//        parentIndexes(a, 6);
    }
    
    {
//        char *s1 = "aba";
//        char *s2 = "bab";
        
//        isFlipedString(s1, s2);
    }
    
    {
//        struct TreeNode* root = malloc(sizeof(struct TreeNode));
//        root->val = 3;
//        struct TreeNode* t5 = malloc(sizeof(struct TreeNode));
//        t5->val = 5;
//        t5->left = NULL;
//        t5->right = NULL;
//        struct TreeNode* t4 = malloc(sizeof(struct TreeNode));
//        t4->val = 4;
//        struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
//        t1->val = 1;
//        t1->left = NULL;
//        t1->right = NULL;
//        struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
//        t2->val = 2;
//        t2->left = NULL;
//        t2->right = NULL;
//
//        root->right = t5;
//        root->left = t4;
//        root->left->left = t1;
//        root->left->right = t2;
//
//        struct TreeNode* node = malloc(sizeof(struct TreeNode));
//        node->val = 4;
//        struct TreeNode* n1 = malloc(sizeof(struct TreeNode));
//        n1->val = 1;
//        n1->left = NULL;
//        n1->right = NULL;
//        struct TreeNode* n2 = malloc(sizeof(struct TreeNode));
//        n2->val = 2;
//        n2->left = NULL;
//        n2->right = NULL;
//        node->left = n1;
//        node->right = n2;
//
//        isSubtree(root, node);
    }
    
    
    
    {
//        reverseWords(" ");
    }
    
    {
        
//        lengthOfLongestSubstring("au");
    }
    
    {
        uniquePaths(3, 2);
    }
    
    
    
    return 0;
}
