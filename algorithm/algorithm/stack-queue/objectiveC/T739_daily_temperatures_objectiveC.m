//
//  T739_daily_temperatures_objectiveC.m
//  algorithm
//
//  Created by Ankui on 7/24/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

#import "T739_daily_temperatures_objectiveC.h"

@implementation T739_daily_temperatures_objectiveC

- (NSArray<NSNumber *> *)dailyTemperatures2:(NSArray<NSNumber *> *)nums {
    if (nums.count == 0) { return nil; }

    NSInteger count = nums.count;
    NSMutableArray<NSNumber *> *list = [NSMutableArray arrayWithCapacity:count];
    for (NSInteger i = 0; i < count; i++) {
        list[i] = @0;
    }
    for (NSInteger i = count - 2; i >= 0; i--) {
        NSInteger j = i + 1;
        while (true) {
            NSInteger vi = [nums[i] integerValue];
            NSInteger vj = [nums[j] integerValue];
            NSInteger lj = [list[j] integerValue];
            if (vi < vj) {
                list[i] = @(j - i);
                break;
            } else if (lj == 0) {
//                list[i] = @0;
                break;
            }
            j = j + lj;
        }
    }
    return [list copy];
}

- (NSArray<NSNumber *> *)dailyTemperatures1:(NSArray<NSNumber *> *)nums {
    if (nums.count == 0) { return nil; }

    NSInteger count = nums.count;
    NSMutableArray<NSNumber *> *list = [NSMutableArray arrayWithCapacity:count];
    for (NSInteger i = 0; i < count; i++) {
        list[i] = @0;
    }
    for (NSInteger i = count - 2; i >= 0; i--) {
        NSInteger j = i + 1;
        while (true) {
            NSInteger vi = [nums[i] integerValue];
            NSInteger vj = [nums[j] integerValue];
            NSInteger lj = [list[j] integerValue];
            if (vi < vj) {
                list[i] = @(j - i);
                break;
            } else if (lj == 0) {
//                list[i] = @0;
                break;
            } else if (vi == vj) {
                list[i] = @(lj + j - i);
                break;
            } else {
                j = j + lj;
            }
        }
    }
    
    return [list copy];
}

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
