//
//  T454-4sum-ii.swift
//  algorithm
//
//  Created by Ankui on 7/31/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/4sum-ii/


import Foundation

func fourSumCount(_ nums1: [Int], _ nums2: [Int], _ nums3: [Int], _ nums4: [Int]) -> Int {
    var count = 0
    var map: [Int: Int] = [:]
    for i in nums1 {
        for j in nums2 {
            map[i + j] = (map[i + j] ?? 0) + 1
        }
    }
    for i in nums3 {
        for j in nums4 {
            count += map[0 - i - j] ?? 0
        }
    }
    
    return count
}
