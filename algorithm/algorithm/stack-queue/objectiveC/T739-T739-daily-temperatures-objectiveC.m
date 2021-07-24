//
//  T739-T739-daily-temperatures-objectiveC.m
//  algorithm
//
//  Created by Ankui on 7/24/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

#import "T739-T739-daily-temperatures-objectiveC.h"

@implementation T739_T739_daily_temperatures_objectiveC

- (NSArray<NSNumber *> *)dailyTemperatures:(NSArray<NSNumber *> *)nums {
    if (nums.count == 0) { return nil; }
    
    NSInteger count = nums.count;
    NSMutableArray<NSNumber *> *list = [NSMutableArray arrayWithCapacity:count];
    for (NSInteger i = 0; i < count; i++) {
        list[i] = @0;
    }
    NSMutableArray<NSNumber *> *stack = [NSMutableArray array];
    for (NSInteger i = 0; i < count; i++) {
        while (stack.count && [nums[i] integerValue] > [nums[[stack.lastObject integerValue]] integerValue]) {
            NSInteger top = [stack.lastObject integerValue];
            list[top] = @(i - top);
            [stack removeLastObject];
        }
        [stack addObject:@(i)];
    }
    
    return [list copy];
}

@end
