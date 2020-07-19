//
//  queue.h
//  algorithm
//
//  Created by Ankui on 7/19/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdbool.h>

struct node {
    int value;
    struct node* next;
};

typedef struct queue {
    struct node* head;
    struct node* tail;
} Queue;

Queue* queue_create(void);
bool queue_isEmpty(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);
void queue_destroy(Queue*);
int queue_front(Queue*);
int queue_size(Queue*);

#endif /* queue_h */
