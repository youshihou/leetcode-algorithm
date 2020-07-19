//
//  T225-implement-stack-using-queues.c
//  algorithm
//
//  Created by Ankui on 7/19/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/implement-stack-using-queues/


#include "T225-implement-stack-using-queues.h"
#include "algorithm-common.h"

typedef struct {
    Queue* queue;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *s = malloc(sizeof(MyStack));
    s->queue = queue_create();
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    enqueue(obj->queue, x);
    int size = queue_size(obj->queue);
    while (size > 1) {
        enqueue(obj->queue, queue_front(obj->queue));
        dequeue(obj->queue);
        size--;
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return dequeue(obj->queue);;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return queue_front(obj->queue);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return queue_isEmpty(obj->queue);
}

void myStackFree(MyStack* obj) {
    while (!myStackEmpty(obj)) {
        myStackPop(obj);
//        queue_destroy(obj->queue); // ERROR!!!!!!
    }
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
