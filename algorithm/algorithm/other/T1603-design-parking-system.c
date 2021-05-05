//
//  T1603-design-parking-system.c
//  algorithm
//
//  Created by Ankui on 5/5/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/design-parking-system/


#include "T1603-design-parking-system.h"
#include "algorithm-common.h"

typedef struct {
    int* nums;
} ParkingSystem;

#define MAX_PARK_NUM 4
#define PARK_BIG 1
#define PARK_MEDIUM 2
#define PARK_SMALL 3


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *p = malloc(sizeof(ParkingSystem));
    p->nums = malloc(sizeof(int) * MAX_PARK_NUM);
    p->nums[PARK_BIG] = big;
    p->nums[PARK_MEDIUM] = medium;
    p->nums[PARK_SMALL] = small;
    return p;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if (obj->nums[carType] == 0) {
        return false;
    }
    
    obj->nums[carType]--;
    return true;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj->nums);
    free(obj);
}



typedef struct {
    int big;
    int medium;
    int small;
} ParkingSystem_;


ParkingSystem_* _parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem_ *p = malloc(sizeof(ParkingSystem_));
    p->big = big;
    p->medium = medium;
    p->small = small;
    return p;
}

bool _parkingSystemAddCar(ParkingSystem_* obj, int carType) {
    if (carType == 1) {
        if (obj->big > 0) {
            obj->big--;
            return true;
        }
    } else if (carType == 2) {
        if (obj->medium > 0) {
            obj->medium--;
            return true;
        }
    } else if (carType == 3) {
        if (obj->small > 0) {
            obj->small--;
            return true;
        }
    }
    return false;
}

void _parkingSystemFree(ParkingSystem_* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/
