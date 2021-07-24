//
//  T654-maximum-binary-tree-objectiveC.m
//  algorithm
//
//  Created by Ankui on 7/24/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

#import "T654-maximum-binary-tree-objectiveC.h"
#import "TreeNode.h"

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
    NSMutableArray<NSNumber *> *lis = [NSMutableArray array];
    NSMutableArray<NSNumber *> *ris = [NSMutableArray array];
    NSMutableArray<NSNumber *> *stack = [NSMutableArray array];
    for (NSInteger i = 0; i < nums.count; i++) {
        while (stack.count && [nums[i] integerValue] > [nums[[stack.firstObject integerValue]] integerValue]) {
            [stack removeObjectAtIndex:0];
            [ris addObject:@(i)];
        }
        NSNumber *idx = @-1;
        if (stack.count) {
            idx = stack.firstObject;
        }
        [lis addObject:idx];
        [stack addObject:@(i)];
    }
    
    return [stack copy];
}

@end
