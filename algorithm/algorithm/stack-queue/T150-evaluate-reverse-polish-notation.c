//
//  T150-evaluate-reverse-polish-notation.c
//  algorithm
//
//  Created by Ankui on 5/10/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/

#include "T150-evaluate-reverse-polish-notation.h"
#include "algorithm-common.h"
#include "stack.h"


int evalRPN(char ** tokens, int tokensSize) {
    if (tokens == NULL || tokensSize <= 0) { return 0; }
    
    Stack* stack = create();
    
    for (int i = 0; i < tokensSize; i++) {
        char* token = tokens[i];
        if (strcmp(token, "+") == 0) {
            push(stack, pop(stack) + pop(stack));
        } else if (strcmp(token, "-") == 0) {
            int right = pop(stack);
            push(stack, pop(stack) - right);
        } else if (strcmp(token, "*") == 0) {
            push(stack, pop(stack) * pop(stack));
        } else if (strcmp(token, "/") == 0) {
            int right = pop(stack);
            push(stack, pop(stack) / right);
        } else {
            push(stack, atoi(token));
        }
    }
    
    return pop(stack);
}




bool isOperator(char* op) {
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 ||
        strcmp(op, "*") == 0 || strcmp(op, "/") == 0) {
        return true;
    }
    return false;
}

int calculate(int left, int right, char* op) {
    if (strcmp(op, "+") == 0) {
        return left + right;
    } else if (strcmp(op, "-") == 0) {
        return left - right;
    } else if (strcmp(op, "*") == 0) {
        return left * right;
    } else {
        return left / right;
    }
}

int evalRPN1(char ** tokens, int tokensSize) {
    if (tokens == NULL || tokensSize <= 0) { return 0; }
    
    Stack* stack = create();
    
    for (int i = 0; i < tokensSize; i++) {
        char* token = tokens[i];
        if (isOperator(token)) {
            int right = pop(stack);
            int left = pop(stack);
            int res = calculate(left, right, token);
            push(stack, res);
        } else {
            push(stack, atoi(token));
        }
    }
    
    return pop(stack);
}
