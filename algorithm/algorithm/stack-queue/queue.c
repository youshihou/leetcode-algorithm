//
//  queue.c
//  algorithm
//
//  Created by Ankui on 7/19/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>
#include <assert.h>

Queue* queue_create(void) {
    Queue* q = malloc(sizeof(Queue));
    assert(q);
    q->head = q->tail = NULL;
    return q;
}

bool queue_isEmpty(Queue* q) {
    return q->head == NULL;
}

void enqueue(Queue* q, int value) {
    struct node* e = malloc(sizeof(struct node));
    assert(e);
    e->value = value;
    e->next = NULL;
    if (q->head == NULL) {
        q->head = e;
    } else {
        q->tail->next = e;
    }
    q->tail = e;
}

int dequeue(Queue* q) {
    assert(!queue_isEmpty(q));
    struct node* e = q->head;
    int ret = e->value;
    q->head = e->next;
    free(e);
    return ret;
}

void queue_destroy(Queue* q) {
    while (!queue_isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int queue_front(Queue* q) {
    assert(!queue_isEmpty(q));
    return q->head->value;
}

int queue_size(Queue* q) {
    int size = 0;
    struct node* e = q->head;
    while (e) {
        size++;
        e = e->next;
    }
    return size;
}













ObjectQueue* object_queue_create(void) {
    ObjectQueue *q = malloc(sizeof(ObjectQueue));
    assert(q);
    q->head = q->tail = NULL;
    return q;
}

bool object_queue_isEmpty(ObjectQueue* q) {
    return q->head == NULL;
}

void object_queue_enqueue(ObjectQueue* q, void* v) {
    ObjectNode* n = malloc(sizeof(ObjectNode));
    assert(n);
    n->value = v;
    n->next = NULL;
    if (q->head) {
        q->tail->next = n;
    } else {
        q->head = n;
    }
    q->tail = n;
}

void* object_queue_dequeue(ObjectQueue* q) {
    assert(!object_queue_isEmpty(q));
    ObjectNode* n = q->head;
    void* ret = n->value;
    q->head = q->head->next;
    free(n);
    return ret;
}

void* object_queue_front(ObjectQueue* q) {
    assert(!object_queue_isEmpty(q));
    return q->head->value;
}

int object_queue_size(ObjectQueue* q) {
    int size = 0;
    ObjectNode* n = q->head;
    while (n) {
        size++;
        n = n->next;
    }
    return size;
}

void object_queue_destroy(ObjectQueue* q) {
    while (!object_queue_isEmpty(q)) {
        object_queue_dequeue(q);
    }
    free(q);
}



