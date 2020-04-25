//
//  stack.h
//  algorithm
//
//  Created by Ankui on 4/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdbool.h>


typedef struct Node {
    int val;
    struct Node* next;
} Stack;


Stack* create(void);
bool isEmpty(Stack*);
void push(Stack*, int);
int pop(Stack*);
int top(Stack*);
void stack_free(Stack*);

#endif /* stack_h */
