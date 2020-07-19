//
//  stack.c
//  algorithm
//
//  Created by Ankui on 4/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "stack.h"
#include <stdlib.h>
#include <assert.h>

Stack* create(void) {
    Stack* s = malloc(sizeof(Stack));
    assert(s);
    s->next = NULL;
    return s;
}

void push(Stack* s, int x) {
    Stack* n = malloc(sizeof(Stack));
    assert(n);
    n->val = x;
    n->next = s->next;
    s->next = n;    
}

bool isEmpty(Stack* s) {
    return s->next == NULL;
}

int pop(Stack* s) {
    assert(!isEmpty(s));
    Stack* e = s->next;
    int ret = e->val;
    s->next = s->next->next;
    free(e);
    return ret;
}

int top(Stack* s) {
    assert(!isEmpty(s));
    return s->next->val;
}

void stack_free(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
    free(s);
}













struct stack* stack_create(void) {
    struct stack* s = malloc(sizeof(struct stack));
    assert(s);
    s->head = NULL;
    return s;
}

bool stack_isEmpty(struct stack* s) {
    return s->head == NULL;
}

void stack_push(struct stack* s, int value) {
    struct node* e = malloc(sizeof(struct node));
    assert(e);
    e->value = value;
    e->next = s->head;
    s->head = e;
}

int stack_pop(struct stack* s) {
    assert(!stack_isEmpty(s));
    struct node* e = s->head;
    int ret = e->value;
    s->head = e->next;
    free(e);
    return ret;
}

int stack_top(struct stack* s) {
    assert(!stack_isEmpty(s));
    return s->head->value;
}

void stack_destroy(struct stack* s) {
    while (!stack_isEmpty(s)) {
        stack_pop(s);
    }
    free(s);
}

int stack_size(struct stack* s) {
    int size = 0;
    while (s->head) {
        size++;
        s->head = s->head->next;
    }
    return size;
}



