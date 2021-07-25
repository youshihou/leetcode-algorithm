//
//  T155-min-stack-objectiveC.m
//  algorithm
//
//  Created by Ankui on 7/25/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

#import "T155-min-stack-objectiveC.h"

@interface Node : NSObject {
    @public
    id val;
    id min;
    Node *next;
}

@end

@implementation Node

@end



@interface T155_min_stack_objectiveC () {
//    NSMutableArray *stack;
//    NSMutableArray *minsStack;
    
    Node *head;
}

@end

@implementation T155_min_stack_objectiveC

- (instancetype)init {
    self = [super init];
    if (self) {
//        stack = [NSMutableArray array];
//        minsStack = [NSMutableArray array];
        
        head = [[Node alloc] init];
        head->min = @(INT_MAX);
    }
    return self;
}

+ (instancetype)minstack {
    return [[self alloc] init];
}

- (void)push:(id)object {
//    [stack addObject:object];
//    if (minsStack.count == 0) {
//        [minsStack addObject:object];
//    } else {
//        NSInteger top = [minsStack.lastObject integerValue];
//        NSInteger cur = [object integerValue];
//        NSInteger last = MIN(top, cur);
//        [minsStack addObject:@(last)];
//    }
    
    NSInteger first = [head->min integerValue];
    NSInteger cur = [object integerValue];
    NSInteger min = MIN(first, cur);
    
    Node *node = [[Node alloc] init];
    node->val = object;
    node->min = @(min);
    node->next = head;
    head = node;
}

- (void)pop {
//    [stack removeLastObject];
//    [minsStack removeLastObject];
    
    head = head->next;
}

- (id)top {
//    return stack.lastObject;
    
    return head->val;
}

- (id)getMin {
//    return minsStack.lastObject;
    
    return head->min;
}

@end
