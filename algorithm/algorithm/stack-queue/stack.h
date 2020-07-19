//
//  stack.h
//  algorithm
//
//  Created by Ankui on 4/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include "algorithm-common.h"

typedef struct stack_ {
    int val;
    struct stack_* next;
} Stack;

Stack* create(void);
bool isEmpty(Stack*);
void push(Stack*, int);
int pop(Stack*);
int top(Stack*);
void stack_free(Stack*);


struct stack {
    struct node* head;
};

struct stack* stack_create(void);
bool stack_isEmpty(struct stack*);
void stack_push(struct stack*, int);
int stack_pop(struct stack*);
int stack_top(struct stack*);
void stack_destroy(struct stack*);
int stack_size(struct stack*);


#endif /* stack_h */
