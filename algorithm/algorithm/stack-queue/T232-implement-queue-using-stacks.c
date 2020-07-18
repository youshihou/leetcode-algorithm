//
//  T232-implement-queue-using-stacks.c
//  algorithm
//
//  Created by Ankui on 7/18/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/implement-queue-using-stacks/


#include "T232-implement-queue-using-stacks.h"
#include "algorithm-common.h"


typedef struct {
    Stack* inStack;
    Stack* outStack;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *q = malloc(sizeof(MyQueue));
    q->inStack = create();
    q->outStack = create();
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    push(obj->inStack, x);
}

void checkOutStack(MyQueue* obj) {
    if (isEmpty(obj->outStack)) {
        while (!isEmpty(obj->inStack)) {
            push(obj->outStack, pop(obj->inStack));
        }
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
//    if (isEmpty(obj->outStack)) {
//        while (!isEmpty(obj->inStack)) {
//            push(obj->outStack, pop(obj->inStack));
//        }
//    }
    checkOutStack(obj);
    return pop(obj->outStack);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
//    if (isEmpty(obj->outStack)) {
//        while (!isEmpty(obj->inStack)) {
//            push(obj->outStack, pop(obj->inStack));
//        }
//    }
    checkOutStack(obj);
    return top(obj->outStack);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->inStack) && isEmpty(obj->outStack);
}

void myQueueFree(MyQueue* obj) {
    while (!myQueueEmpty(obj)) {
//        myQueuePop(obj);
        stack_free(obj->inStack);
        stack_free(obj->outStack);
    }
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
