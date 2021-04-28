//
//  T468-validate-ip-address.m
//  algorithm
//
//  Created by Ankui on 4/28/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/validate-ip-address/


#import "T468-validate-ip-address.h"

@implementation T468_validate_ip_address


@end


BOOL isNum(NSString *str) {
    if (str.length == 0) { return NO; }
    NSInteger result = 0;
    NSScanner *scaner = [NSScanner scannerWithString:str];
    return [scaner scanInteger:&result] && [scaner isAtEnd];
}

BOOL validateNum(NSString *str) {
    BOOL result = NO;
    NSCharacterSet *set = [NSCharacterSet characterSetWithCharactersInString:@"0123456789"];
    for (int i = 0; i < str.length; i++) {
        NSString *s = [str substringWithRange:NSMakeRange(i, 1)];
        NSRange range = [s rangeOfCharacterFromSet:set];
        if (range.length == 0) {
            result = NO;
            break;
        }
    }
    return result;
}

BOOL isIPv4(NSString *string) {
    if (string.length == 0) { return NO; }
    
    NSArray *array = [string componentsSeparatedByString:@"."];
    if (array.count < 4) { return NO; }
    
    for (int i = 0; i < array.count; i++) {
        NSString *str = array[i];
        if (!isNum(str)) { return NO; }
        NSInteger value = str.integerValue;
        if (i == 0 && value == 255) {
            return NO;
        }
        if (i == 3 && value == 0) {
            return NO;
        }
        if (value < 0 || value > 255) {
            return NO;
        }
    }
    return YES;
}



//int main(int argc, const char * argv[]) {
//    @autoreleasepool {
//        NSString *string = @"192.168.2.1";
//        string = @"a.b.c.d";
//        string = @"1.a.b.2";
//        string = @"255.192.0.1";
//        string = @"192.168.0.0";
//        string = @"1a.2b.34.4d";
//        BOOL result = isIPv4(string);
//        NSLog(@"%d", result);
//    }
//    return 0;
//}
