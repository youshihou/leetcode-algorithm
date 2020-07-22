//
//  algorithm-common.h
//  algorithm
//
//  Created by Ankui on 5/11/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef algorithm_common_h
#define algorithm_common_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "stack.h"
#include "queue.h"

struct node {
    int value;
    struct node* next;
};

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) (((a) > (b)) ? (b) : (a))
#endif


#endif /* algorithm_common_h */
