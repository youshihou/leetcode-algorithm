//
//  T155-min-stack-objectiveC.h
//  algorithm
//
//  Created by Ankui on 7/25/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface T155_min_stack_objectiveC : NSObject

+ (instancetype)minstack;
- (void)push:(id)object;
- (void)pop;
- (id)top;
- (id)getMin;

@end

NS_ASSUME_NONNULL_END
