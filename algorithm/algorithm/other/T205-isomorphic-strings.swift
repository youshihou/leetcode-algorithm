//
//  T205-isomorphic-strings.swift
//  algorithm
//
//  Created by Ankui on 5/4/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/isomorphic-strings/



import Foundation

class t205_Solution {
    func isIsomorphic(_ s: String, _ t: String) -> Bool {
        let sc = Array(s)
        let tc = Array(t)
        var s2t: [Character: Character] = [:]
        for i in 0..<sc.count {
            if let c = s2t[sc[i]] {
                if c != tc[i] {
                    return false
                }
            } else {
                if s2t.values.contains(tc[i]) {
                    return false
                }
                s2t[sc[i]] = tc[i]
            }
        }
        return true
    }
}
