//
//  T295-find-median-from-data-stream.c
//  algorithm
//
//  Created by Ankui on 4/28/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/find-median-from-data-stream/


#include "T295-find-median-from-data-stream.h"
#include "algorithm-common.h"

typedef struct {
    int num;
    int* p;
} MedianFinder;

#define M_MAX 100000

int bigHeap[M_MAX] = {0};
int smallHeap[M_MAX] = {0};
int bigSize = 0;
int smallSize = 0;

/** initialize your data structure here. */

MedianFinder* medianFinderCreate() {
    MedianFinder* m = malloc(sizeof(MedianFinder));
    m->num = 0;
    m->p = bigHeap;
    bigSize = 0;
    smallSize = 0;
    return m;
}

void updateHeap(int* heap, int size, int flag) {
    int idx = size - 1;
    int childIdx = 0;
    int val = heap[idx];
    while (idx >= 0) {
        childIdx = ((idx + 1) >> 1) - 1;
        if (childIdx < 0 || val * flag < heap[childIdx] * flag) {
            break;
        }
        heap[idx] = heap[childIdx];
        idx = childIdx;
    }
    heap[idx] = val;
}

void _bigHeap(int num) {
    bigHeap[bigSize++] = num;
    updateHeap(bigHeap, bigSize, 1);
}

void _smallHeap(int num) {
    smallHeap[smallSize++] = num;
    updateHeap(smallHeap, smallSize, -1);
}

void adjustHead(int index, int size, int* heap, int flag) {
    int childIdx = 0;
    int mid = size >> 1;
    int max = 0;
    int val = heap[index];

    while (index < mid) {
        childIdx = 2 * index + 1;
        max = heap[childIdx];
        if ((childIdx + 1 < size) && (flag * max < flag * heap[childIdx + 1])) {
            childIdx = childIdx + 1;
            max = heap[childIdx];
        }
        
        if (flag * val > flag * max) {
            break;
        }
        
        heap[index] = heap[childIdx];
        index = childIdx;
    }
    heap[index] = val;
}

void deleteBigHeapHead() {
    bigHeap[0] = bigHeap[--bigSize];
    adjustHead(0, bigSize, bigHeap, 1);
}

void deleteSmallHeapHead() {
    smallHeap[0] = smallHeap[--smallSize];
    adjustHead(0, smallSize, smallHeap, -1);
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (smallSize == 0 || num > smallHeap[0]) {
        _smallHeap(num);
        if (smallSize > bigSize + 1) {
            _bigHeap(smallHeap[0]);
            deleteSmallHeapHead();
        }
    } else {
        _bigHeap(num);
        if (bigSize > smallSize + 1) {
            _smallHeap(bigHeap[0]);
            deleteBigHeapHead();
        }
    }
    obj->num = bigSize + smallSize;
}

double medianFinderFindMedian(MedianFinder* obj) {
    double temp;
    if (bigSize > smallSize) {
        temp = bigHeap[0];
    } else if (smallSize > bigSize) {
        temp = smallHeap[0];
    } else {
        temp = (bigHeap[0] + smallHeap[0]) / 2.0;
    }
    return temp;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/
