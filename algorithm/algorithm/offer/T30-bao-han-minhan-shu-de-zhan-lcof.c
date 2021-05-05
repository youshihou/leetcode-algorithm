//
//  T30-bao-han-minhan-shu-de-zhan-lcof.c
//  algorithm
//
//  Created by Ankui on 4/20/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/


#include "T30-bao-han-minhan-shu-de-zhan-lcof.h"
#include "algorithm-common.h"

typedef struct {
    int* min;
    int* val;
    int min_top;
    int val_top;
} MinStack;

#define MAX_LEN 10000

/** initialize your data structure here. */

MinStack* _minStackCreate(void) {
    MinStack *s = malloc(sizeof(MinStack));
    s->min = malloc(sizeof(int) * MAX_LEN);
    s->val = malloc(sizeof(int) * MAX_LEN);
    s->min_top = s->val_top = 0;
    return s;
}

void _minStackPush(MinStack* obj, int x) {
    obj->val[obj->val_top++] = x;
    if (obj->min_top > 0 && obj->min[obj->min_top - 1] <= x) {
        obj->min[obj->min_top++] = obj->min[obj->min_top - 1];
    } else {
        obj->min[obj->min_top++] = x;
    }
}

void _minStackPop(MinStack* obj) {
    if (obj->val_top > 0) {
        obj->val_top--;
    }
    if (obj->min_top > 0) {
        obj->min_top--;
    }
}

int _minStackTop(MinStack* obj) {
    return obj->val[obj->val_top - 1];
}

int _minStackMin(MinStack* obj) {
    return obj->min[obj->min_top - 1];
}

void _minStackFree(MinStack* obj) {
    free(obj->val);
    free(obj->min);
    free(obj);
}





//typedef struct {
//    int* stack;
//    int top;
//    int *min_stack;
//    int min_top;
//} MinStack;
//
//#define MAX_LEN 10000
//
///** initialize your data structure here. */
//
//MinStack* minStackCreate() {
//    MinStack *s = malloc(sizeof(MinStack));
//    s->stack = malloc(sizeof(int) * MAX_LEN);
//    s->min_stack = malloc(sizeof(int) * MAX_LEN);
//    s->top = s->min_top = -1;
//    return s;
//}
//
//void minStackPush(MinStack* obj, int x) {
//    obj->stack[++obj->top] = x;
//    if (obj->min_top == -1) {
//        obj->min_stack[++obj->min_top] = x;
//    } else if (obj->min_stack[obj->min_top] >= x) {
//        obj->min_stack[++obj->min_top] = x;
//    }
//}
//
//void minStackPop(MinStack* obj) {
//    if (obj->stack[obj->top] == obj->min_stack[obj->min_top]) {
//        obj->top--;
//        obj->min_top--;
//    } else {
//        obj->top--;
//    }
//}
//
//int minStackTop(MinStack* obj) {
//    return obj->stack[obj->top];
//}
//
//int minStackMin(MinStack* obj) {
//    return obj->min_stack[obj->min_top];
//}
//
//void minStackFree(MinStack* obj) {
//    free(obj->stack);
//    free(obj->min_stack);
//    free(obj);
//}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/
