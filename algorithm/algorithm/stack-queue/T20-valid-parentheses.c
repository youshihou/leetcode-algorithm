//
//  T20-valid-parentheses.c
//  algorithm
//
//  Created by Ankui on 7/18/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/valid-parentheses/

#include "T20-valid-parentheses.h"
#include "algorithm-common.h"

bool isValid(char * s) {
    if (*s == 0) { return true; }
    size_t len = strlen(s);
    if (len & 1) { return false; }
    int size = (int)(len >> 1);
    char stack[size + 1];
    for (int i = 0, top = -1; i < len && top < size; i++) {
        char c = s[i];
        if (c == '{' || c == '[' || c == '(') {
            stack[++top] = c;
        } else if (top == -1) {
            return false;
        } else if (c == stack[top] + 1 || c == stack[top] + 2) {
            stack[top--] = 0;
        } else {
            return false;
        }
    }
    
    return !stack[0];
}



bool isValid1(char * s) {
    if (s == NULL) { return false; }
    size_t len = strlen(s);
    
    Stack* stack = create();
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '{' || c == '[' || c == '(') {
            push(stack, c);
        } else {
            if (isEmpty(stack)) { return false; }
            
            char left = pop(stack);
            if (left == '{' && c != '}') { return false; }
            if (left == '[' && c != ']') { return false; }
            if (left == '(' && c != ')') { return false; }
        }
    }
    
    return isEmpty(stack);
}
