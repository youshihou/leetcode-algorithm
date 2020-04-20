//
//  main.c
//  algorithm
//
//  Created by Ankui on 4/20/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include <stdio.h>
#include "T88-merge-sorted-array.h"
#include "T16-sub-sort-lcci.h"

int main(int argc, const char * argv[]) {
    
    {   // T88
        int nums1[1] = {0};
        int nums2[1] = {1};
        merge(nums1, 1, 0, nums2, 1, 1);
    }
    
    {
        // T16
        int array[] = {};
        subSort(array, 0, NULL);
        int array2[] = {1,2,4,7,10,11,7,12,6,7,16,18,19};
        subSort(array2, 13, NULL);
    }

    return 0;
}
