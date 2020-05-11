//
//  T253-meeting-rooms-ii.c
//  algorithm
//
//  Created by Ankui on 5/5/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/meeting-rooms-ii/

#include "T253-meeting-rooms-ii.h"
#include "algorithm-common.h"

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervals == NULL || intervalsSize <= 0) { return 0; }
    
    int begins[intervalsSize];
    int ends[intervalsSize];
    for (int i = 0; i < intervalsSize; i++) {
        begins[i] = intervals[i][0];
        ends[i] = intervals[i][1];
    }
    
    qsort(begins, intervalsSize, sizeof(int), cmp);
    qsort(ends, intervalsSize, sizeof(int), cmp);
    
    int room = 0;
    int endIdx = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (begins[i] >= ends[endIdx]) { // CARE!!! is endIdx not i
            endIdx++;
        } else {
            room++;
        }
    }
    
    return room;
}
