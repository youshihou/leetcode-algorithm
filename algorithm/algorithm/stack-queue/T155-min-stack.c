//
//  T155-min-stack.c
//  algorithm
//
//  Created by Ankui on 4/24/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/min-stack/

#include "T155-min-stack.h"
#include "algorithm-common.h"

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

typedef struct Node_ {
    int val;
    int min;
    struct Node_* next;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* stack = malloc(sizeof(MinStack));
    stack->next = NULL;
    stack->min = INT_MAX;
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    MinStack* node = malloc(sizeof(MinStack));
    node->val = x;
    if (obj->next == NULL || obj->next->min >= x) {
        node->min = x;
    } else {
        node->min = obj->next->min;
    }
    node->next = obj->next;
    obj->next = node;
}

void minStackPop(MinStack* obj) {
    if (obj->next == NULL) { return; }

    MinStack *temp = obj->next;
    obj->next = obj->next->next;
    free(temp);
}

int minStackTop(MinStack* obj) {
    if (obj->next == NULL) { return -1; }
    return obj->next->val;
}

int minStackGetMin(MinStack* obj) {
    if (obj->next == NULL) { return -1; }
    return obj->next->min;
}

void minStackFree(MinStack* obj) {
    while (obj->next != NULL) {
        minStackPop(obj);
    }
}

