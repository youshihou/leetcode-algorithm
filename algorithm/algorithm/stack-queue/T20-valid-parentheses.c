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
