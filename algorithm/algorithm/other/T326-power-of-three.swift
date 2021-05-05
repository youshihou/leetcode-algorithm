//
//  T326-power-of-three.swift
//  algorithm
//
//  Created by Ankui on 5/5/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/power-of-three/


import Foundation

class t326_Solution {
    func isPowerOfThree(_ n: Int) -> Bool {
        if (n < 1) { return false }
        var res = n
        while res % 3 == 0 {
            res /= 3
        }
        return res == 1
        
//        return n > 0 && 1162261467 % n == 0
    }
}
