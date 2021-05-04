//
//  T171-excel-sheet-column-number.c
//  algorithm
//
//  Created by Ankui on 5/4/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/excel-sheet-column-number/


#include "T171-excel-sheet-column-number.h"
#include "algorithm-common.h"


int titleToNumber(char * columnTitle) {
    if (columnTitle == NULL) { return 0; }
    
    int res = 0;
    for (int i = 0; i < strlen(columnTitle); i++) {
        res = res * 26 + (columnTitle[i] - 'A' + 1);
    }
    return res;
}




int _titleToNumber(char * columnTitle) {
    if (columnTitle == NULL) { return 0; }
    
    int res = 0;
    for (int i = 0; columnTitle[i] != '\0'; i++) {
        int num = columnTitle[i] - 'A' + 1;
        res = res * 26 + num;
    }
    return res;
}
