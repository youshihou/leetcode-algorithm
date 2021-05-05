//
//  T09_yong-liang-ge-zhan-shi-xian-dui-lie-lcof.c
//  algorithm
//
//  Created by Ankui on 4/20/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/


#include "T09_yong-liang-ge-zhan-shi-xian-dui-lie-lcof.h"
#include "algorithm-common.h"

typedef struct {
    int* stackA;
    int topA;
    int* stackB;
    int topB;
} CQueue;


#define MAX_SIZE 1000

CQueue* cQueueCreate(void) {
    CQueue* q = malloc(sizeof(CQueue));
    q->stackA = malloc(sizeof(int) * MAX_SIZE);
    q->topA = 0;
    q->stackB = malloc(sizeof(int) * MAX_SIZE);
    q->topB = 0;
    return q;
}

void cQueueAppendTail(CQueue* obj, int value) {
    obj->stackA[obj->topA++] = value;
}

int cQueueDeleteHead(CQueue* obj) {
    if (obj->topB == 0) {
        if (obj->topA == 0) { return -1; }
        while (obj->topA != 0) {
            obj->stackB[obj->topB++] = obj->stackA[--obj->topA];
        }
    }
    return obj->stackB[--obj->topB];
}

void cQueueFree(CQueue* obj) {
    obj->topA = obj->topB = 0;
    free(obj->stackA);
    free(obj->stackB);
    free(obj);
}



//typedef struct {
//    int stack1[1000];
//    int top1;
//    int stack2[1000];
//    int top2;
//} CQueue;
//
//
//CQueue* cQueueCreate() {
//    CQueue* q = malloc(sizeof(CQueue));
//    q->top1 = -1;
//    q->top2 = -1;
//    return q;
//}
//
//void cQueueAppendTail(CQueue* obj, int value) {
//    obj->stack1[++obj->top1] = value;
//}
//
//int cQueueDeleteHead(CQueue* obj) {
//    if (obj->top2 == -1 && obj->top1 == -1) {
//        return -1;
//    } else if (obj->top2 == -1) {
//        while (obj->top1 > 0) {
//            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
//        }
//        return obj->stack1[obj->top1--];
//    } else {
//        return obj->stack2[obj->top2--];
//    }
//}
//
//void cQueueFree(CQueue* obj) {
//    free(obj);
//}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
