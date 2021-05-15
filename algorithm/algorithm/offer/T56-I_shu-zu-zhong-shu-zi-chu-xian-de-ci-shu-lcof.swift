//
//  T56-I_shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof.swift
//  algorithm
//
//  Created by Ankui on 5/15/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

import Foundation

class t56_I_Solution {
    func singleNumbers(_ nums: [Int]) -> [Int] {
        var tmp = 0
        for i in 0..<nums.count {
            tmp ^= nums[i]
        }
        var n = 1
        while (tmp & n) == 0 {
            n <<= 1
        }
        var a = 0
        var b = 0
        for i in 0..<nums.count {
            if (nums[i] & n) != 0 {
                a ^= nums[i]
            } else {
                b ^= nums[i]
            }
        }
        return [a, b]
    }
}
