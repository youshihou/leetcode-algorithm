//
//  T654-maximum-binary-tree-objectiveC.h
//  algorithm
//
//  Created by Ankui on 7/24/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TreeNode : NSObject {
@public
    id val;
    TreeNode *left;
    TreeNode *right;
}

@end



@interface T654_maximum_binary_tree_objectiveC : NSObject

- (TreeNode *)constructMaximumBinaryTree:(NSArray<NSNumber *> *)nums;

- (NSArray<NSNumber *> *)parentIndexes:(NSArray<NSNumber *> *)nums;

@end

NS_ASSUME_NONNULL_END
