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
        if nums.count < 2 {
            return nums
        }
        var list = nums
        sort(&list, 0, nums.count)
        return list
    }
    
    func sort(_ nums: inout [Int], _ begin: Int, _ end: Int) {
        if end - begin < 2 {
            return
        }
        let mid = pivotIndex(&nums, begin, end);
        sort(&nums, begin, mid) // is begin NOT 0 !!!
        sort(&nums, mid + 1, end)
    }
    
    func pivotIndex(_ nums: inout [Int], _ begin: Int, _ end: Int) -> Int {
        var l = begin
        var r = end - 1
        let v = nums[begin]
        
        while l < r {
            while l < r {
                if nums[r] > v {
                    r -= 1
                } else {
                    nums[l] = nums[r]
                    l += 1
                    break
                }
            }
            while l < r {
                if nums[l] < v {
                    l += 1
                } else {
                    nums[r] = nums[l]
                    r -= 1
                    break
                }
            }
        }
        nums[l] = v
        return l
    }
    
    func sortArray2(_ nums: [Int]) -> [Int] {
        if (nums.count <= 1) { return nums }

        var left: [Int] = []
        var right: [Int] = []
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
