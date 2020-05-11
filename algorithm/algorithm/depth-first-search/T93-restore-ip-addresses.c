//
//  T93-restore-ip-addresses.c
//  algorithm
//
//  Created by Ankui on 5/3/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/restore-ip-addresses/

#include "T93-restore-ip-addresses.h"
#include "algorithm-common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isValid(char* s, int len) {
    if (len <= 0 || len > 3) { return false; }
    if (len > 1 && s[0] - '0' == 0) { return false; }
    
    int num = 0;
    for (int i = 0; i < len; i++) {
        num = num * 10 + s[i] - '0';
    }
    return num > 255 ? false : true;
}

// TODO: - 
//void dfs(char* s, int* returnSize, char** list, int num, int* points) {
//    int len = (int)strlen(s);
//    if (num == 3) {
//        if (isValid(s + points[2], len - points[2])) {
//            char* string = malloc(sizeof(char) * (len + 4));
//            memset(string, '\0', sizeof(char) * (len + 4));
//            int k = 0;
//            for (int i = 0; i < len; i++) {
//                for (int j = 0; j < 3; j++) {
//                    if (i == points[j]) {
//                        string[k++] = '.';
//                    }
//                }
//                string[k++] = s[i];
//            }
//            list[*returnSize] = string;
//            (*returnSize)++;
//        }
//        return;
//    }
//
//    int pos = num == 0 ? 0 : num - 1;
//    for (int i = pos + 1; i < len; i++) {
//        if (isValid(s + pos, i - pos)) {
//            points[num] = i;
//            num++;
//            dfs(s, returnSize, list, num, points);
//            num--;
//        }
//    }
//}
//
//char ** restoreIpAddresses(char * s, int* returnSize) {
//    *returnSize = 0;
//    if (s == NULL) { return NULL; }
//    size_t len = strlen(s);
//    if (len < 4 || len > 12) { return NULL; }
//
//    int maxLen = 1024;
//    char** list = malloc(sizeof(char*) * maxLen);
//    memset(list, '\0', sizeof(char*) * maxLen);
//
//    int* points = malloc(sizeof(int) * 3);
//    memset(points, 0, sizeof(int) * 3);
//
//    dfs(s, returnSize, list, 0, points);
//
//    return list;
//}






void dfs1111(char* s, int* returnSize, char* string, char** list, int idx, int start) {
    if (start > 4) { return; }
    if (s[0] == '\0' && start == 4) {
        list[*returnSize] = malloc(sizeof(char) * (strlen(string) + 1));
        strcpy(list[*returnSize], string);
        (*returnSize)++;
        return;
    }
    
    if (start > 0 && start < 4) {
        string[idx++] = '.';
    }
    for (int i = 1; i <= 3 && i <= strlen(s); i++) { // CARE!!!  && i <= strlen(s)
        if (isValid(s, i)) {
            for (int j = 0; j < i; j++) {
                string[idx + j] = s[j];
            }
            dfs1111(s + i, returnSize, string, list, idx + i, start + 1);
        }
    }
}

char ** restoreIpAddresses1(char * s, int* returnSize) {
    *returnSize = 0;
    if (s == NULL) { return NULL; }
    size_t len = strlen(s);
    if (len < 4 || len > 12) { return NULL; }
    
    int maxLen = 1024;
    char** list = malloc(sizeof(char*) * maxLen);
    memset(list, '\0', sizeof(char*) * maxLen);
    
    char* string = malloc(sizeof(char) * (len + 4));
    memset(string, '\0', sizeof(char) * (len + 4));

    dfs1111(s, returnSize, string, list, 0, 0);
    
    return list;
}
