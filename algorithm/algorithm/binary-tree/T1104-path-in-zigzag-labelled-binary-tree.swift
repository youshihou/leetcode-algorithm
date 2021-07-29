//
//  T1104-path-in-zigzag-labelled-binary-tree.swift
//  algorithm
//
//  Created by Ankui on 7/29/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

import Foundation


class Solution3 {
    func pathInZigZagTree(_ label: Int) -> [Int] {
        var level = 0
        
        for i in 1...20 {
            if label >= (1<<(i - 1)) && label < (1<<(i)) {
                level = i
            }
        }
        
        var label = label
        var list: [Int] = []
        
        while level > 0 {
            list.append(label)
            level -= 1
            
            if label & 1 == 0 {
                label >>= 1
                let sum = 1<<level - 1 + 1<<(level - 1)
                label = sum - label
            } else {
                let sum = 1<<(level + 1) - 1 + 1<<level
                label = sum - label
                label >>= 1
            }
        }
        
        let count = list.count
        var result = Array(repeating: 0, count: count)
        for i in 0..<count {
            result[i] = list[count - 1 - i]
        }
        
        return result
    }
}
