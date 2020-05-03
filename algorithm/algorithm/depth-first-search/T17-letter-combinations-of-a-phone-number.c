//
//  T17-letter-combinations-of-a-phone-number.c
//  algorithm
//
//  Created by Ankui on 5/2/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

#include "T17-letter-combinations-of-a-phone-number.h"
#include "depth-first-search-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(char** letters, char* digits, char* string, char** list, int* returnSize, int idx) {
    size_t len = strlen(digits);
    if (idx == len) {
        list[*returnSize] = malloc(sizeof(char) * (len + 1)); // CARE!!!
        strcpy(list[*returnSize], string);
        (*returnSize)++;
        return;
    }
    
    char* letter = letters[digits[idx] - '2'];
    for (size_t i = 0; i < strlen(letter); i++) {
        string[idx] = letter[i];
        dfs(letters, digits, string, list, returnSize, idx + 1);
    }
}

char ** letterCombinations(char * digits, int* returnSize) {
    *returnSize = 0;
    if (digits == NULL) { return NULL; }
    size_t len = strlen(digits);
    if (len == 0) { return NULL; }
    
    char *letters[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    char* string = malloc(sizeof(char) * (len + 1));
    memset(string, '\0', sizeof(char) * (len + 1));

    char* letter = letters[digits[0] - '2'];
    size_t listLen = strlen(letter);
    for (size_t i = 1; i < len; i++) {
        letter = letters[digits[i] - '2'];
        listLen *= strlen(letter);
    }
    char** list = malloc(sizeof(char *) * listLen);
    memset(list, '\0', sizeof(char*) * listLen); // CARE!!! is list not *list

    dfs(letters, digits, string, list, returnSize, 0);

    return list;
}
