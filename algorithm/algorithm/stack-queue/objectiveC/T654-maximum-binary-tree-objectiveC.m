//
//  T654-maximum-binary-tree-objectiveC.m
//  algorithm
//
//  Created by Ankui on 7/24/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

#import "T654-maximum-binary-tree-objectiveC.h"

@implementation T654_maximum_binary_tree_objectiveC

- (TreeNode *)constructMaximumBinaryTree:(NSArray<NSNumber *> *)nums {
    if (nums.count == 0) { return nil; }
    
    return [self findRoot:nums l:0 r:nums.count];
}

- (TreeNode *)findRoot:(NSArray<NSNumber *> *)nums l:(NSInteger)l r:(NSInteger)r {
    if (l == r) { return nil; }
    
    NSInteger maxIdx = l;
    for (NSInteger i = l + 1; i < r; i++) {
        if ([nums[i] integerValue] > [nums[maxIdx] integerValue]) {
            maxIdx = i;
        }
    }
    
    TreeNode *root = [[TreeNode alloc] init];
    root->val = nums[maxIdx];
    root->left = [self findRoot:nums l:l r:maxIdx];
    root->right = [self findRoot:nums l:maxIdx + 1 r:r];
    return root;
}


- (NSArray<NSNumber *> *)parentIndexes:(NSArray<NSNumber *> *)nums {
    if (nums.count == 0) { return nil; }
    
    NSMutableArray<NSNumber *> *stack = [NSMutableArray array];
    NSInteger count = nums.count;
    NSMutableArray<NSNumber *> *lis = [NSMutableArray arrayWithCapacity:count];
    NSMutableArray<NSNumber *> *ris = [NSMutableArray arrayWithCapacity:count];
    for (NSInteger i = 0; i < count; i++) {
        lis[i] = ris[i] = @-1;
    }
    for (NSInteger i = 0; i < count; i++) {
        while (stack.count && [nums[i] integerValue] > [nums[[stack.lastObject integerValue]] integerValue]) {
            ris[[stack.lastObject integerValue]] = @(i);
            [stack removeLastObject];
        }

        if (stack.count) {
            lis[i] = stack.lastObject;
        }
        [stack addObject:@(i)];
    }
    
//    NSLog(@"%@", lis);
//    NSLog(@"%@", ris);
    
    NSMutableArray<NSNumber *> *pis = [NSMutableArray arrayWithCapacity:count];
    for (NSInteger i = 0; i < count; i++) {
        NSInteger l = [lis[i] integerValue];
        NSInteger r = [ris[i] integerValue];
        if (l == -1 && r == -1) {
            pis[i] = @-1;
            continue;
        }
        
        if (l == -1) {
            pis[i] = ris[i];
        } else if (r == -1) {
            pis[i] = lis[i];
        } else if ([nums[l] integerValue] < [nums[r] integerValue]) {
            pis[i] = lis[i];
        } else {
            pis[i] = ris[i];
        }
    }
    
    return [pis copy];
}

@end






@implementation TreeNode

@end
