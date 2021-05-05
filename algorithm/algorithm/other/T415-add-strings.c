//
//  T415-add-strings.c
//  algorithm
//
//  Created by Ankui on 5/5/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/add-strings/


#include "T415-add-strings.h"
#include "algorithm-common.h"

char * addStrings(char * num1, char * num2) {
    int i = (int)strlen(num1);
    int j = (int)strlen(num2);
    char* res = malloc(sizeof(char) * (fmax(i, j) + 3));
    int add = 0;
    int len = 0;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int sum = x + y + add;
        res[len++] = '0' + sum % 10;
        add = sum / 10;
        i--;
        j--;
    }
    for (int i = 0; i * 2 < len; i++) {
        int t = res[i];
        res[i] = res[len - i -1];
        res[len - i -1] = t;
    }
    res[len++] = 0;
    return res;
}
