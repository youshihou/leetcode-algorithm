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
