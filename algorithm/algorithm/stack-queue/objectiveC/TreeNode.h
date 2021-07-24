//
//  TreeNode.h
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

NS_ASSUME_NONNULL_END
