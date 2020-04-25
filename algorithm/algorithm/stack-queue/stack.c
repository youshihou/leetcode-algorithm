//
//  stack.c
//  algorithm
//
//  Created by Ankui on 4/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "stack.h"
#include <stdlib.h>


Stack* create(void) {
    Stack* s = malloc(sizeof(Stack));
    if (s == NULL) {
        printf("malloc failed\n");
        return NULL;
    }
    s->next = NULL;
    return s;
}

void push(Stack* s, int x) {
    Stack* n = malloc(sizeof(Stack));
    if (n == NULL) {
        printf("malloc failed\n");
        return;
    }
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

//void free(Stack* s) {
//    while (@isEmpty(s)) {
//        pop(s);
//    }
//}
