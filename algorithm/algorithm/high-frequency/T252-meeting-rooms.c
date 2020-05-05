//
//  T252-meeting-rooms.c
//  algorithm
//
//  Created by Ankui on 5/5/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/meeting-rooms/

#include "T252-meeting-rooms.h"
#include "high-frequency-common.h"


int compare(const void* a, const void* b) {
    int* aa = *(int**)a;
    int* bb = *(int**)b;
    
    return *aa - *bb;
    return *(*(int**)a) - *(*(int**)b);
}

bool canAttendMeetings(int** intervals, int intervalsSize, int* intervalsColSize) {
//    *intervalsColSize = 0; // ERROR!!!
    if (intervals == NULL || intervalsSize <= 1) { return true; }

    qsort(intervals, intervalsSize, sizeof(intervals[0]), compare);
    
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < intervals[i - 1][1]) { // CARE!!! [1]
            return false;
        }
    }
    
    return true;
}
