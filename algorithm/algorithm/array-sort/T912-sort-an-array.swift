//
//  T912-sort-an-array.swift
//  algorithm
//
//  Created by Ankui on 7/26/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/sort-an-array/


import Foundation

class Solution {
    func sortArray(_ nums: [Int]) -> [Int] {
        if (nums.count <= 1) { return nums }

        var left: [Int] = []
        var right: [Int] = []
        // let pivot = nums[0] // ERROR!!!
        let pivot = nums[nums.count - 1]
        for i in 0..<nums.count - 1 {
            if nums[i] < pivot {
                left.append(nums[i])
            } else {
                right.append(nums[i])
            }
        }
        return sortArray(left) + [pivot] + sortArray(right)
    }
}
