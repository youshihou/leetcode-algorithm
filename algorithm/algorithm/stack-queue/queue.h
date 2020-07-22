//
//  queue.h
//  algorithm
//
//  Created by Ankui on 7/19/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include "algorithm-common.h"

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




typedef struct object_queue ObjectQueue;

ObjectQueue* object_queue_create(void);
bool object_queue_isEmpty(ObjectQueue*);
void object_queue_enqueue(ObjectQueue*, void*);
void* object_queue_dequeue(ObjectQueue*);
void object_queue_destroy(ObjectQueue*);
void* object_queue_front(ObjectQueue*);
int object_queue_size(ObjectQueue*);


#endif /* queue_h */
