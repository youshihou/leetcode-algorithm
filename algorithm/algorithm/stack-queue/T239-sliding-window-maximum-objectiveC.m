//
//  T239-sliding-window-maximum-objectiveC.m
//  algorithm
//
//  Created by Ankui on 7/22/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/sliding-window-maximum/

#import "T239-sliding-window-maximum-objectiveC.h"

@implementation T239_sliding_window_maximum_objectiveC

- (NSArray *)maxSlidingWindow:(NSArray *)nums k:(NSInteger)k {
    if (nums.count == 0 || k < 1) { return nil; }
    if (k == 1) { return nums; }
    
//    NSMutableArray *list = [NSMutableArray arrayWithCapacity:(nums.count - k + 1)];
    NSMutableArray *list = [NSMutableArray array];

    NSMutableArray *deque = [NSMutableArray array];
    for (NSInteger i = 0; i < nums.count; i++) {
        while (deque.count && [nums[i] integerValue] >= [nums[[deque.lastObject integerValue]] integerValue]) {
            [deque removeLastObject];
        }

        [deque addObject:@(i)];
                
        NSInteger w = i - k + 1;
        if (w < 0) { continue; }
        
        if ([deque.firstObject integerValue] < w) {
            [deque removeObjectAtIndex:0];
        }
        
        [list addObject:nums[[deque.firstObject integerValue]]];
    }
    
    return [list copy];
}

@end
