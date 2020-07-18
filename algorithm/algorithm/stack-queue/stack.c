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
    if (isEmpty(s)) {
        return - 1;
    }
    
    Stack* n = s->next;
    int x = n->val;
    s->next = s->next->next;
    free(n);
    return x;
}

int top(Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }

    return s->next->val;
}

void stack_free(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}
