//
//  T303-range-sum-query-immutable.swift
//  algorithm
//
//  Created by Ankui on 5/4/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/range-sum-query-immutable/


import Foundation


class t303_NumArray {
    var sums: [Int] = []
    init(_ nums: [Int]) {
        self.sums = Array(repeating: 0, count: nums.count + 1)
        for i in 0..<nums.count {
            self.sums[i + 1] = self.sums[i] + nums[i]
        }
    }
    
    func sumRange(_ left: Int, _ right: Int) -> Int {
        return sums[right + 1] - sums[left]
    }
}




class t303_NumArray__ {
    var nums: [Int]
    init(_ nums: [Int]) {
        self.nums = nums
        if nums.count > 1 {
            for i in 1..<nums.count {
                self.nums[i] += self.nums[i - 1]
            }
        }
    }
    
    func sumRange(_ left: Int, _ right: Int) -> Int {
        if left == 0 {
            return nums[right]
        }
        return nums[right] - nums[left - 1]
    }
}



class t303_NumArray_ {
    var nums: [Int]
    init(_ nums: [Int]) {
        self.nums = nums
    }
    
    func sumRange(_ left: Int, _ right: Int) -> Int {
        var res = 0
        for i in left...right {
            res += nums[i]
        }
        return res
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray(nums)
 * let ret_1: Int = obj.sumRange(left, right)
 */
