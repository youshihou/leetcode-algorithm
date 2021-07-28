//
//  T199-binary-tree-right-side-view.swift
//  algorithm
//
//  Created by Ankui on 7/28/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/binary-tree-right-side-view/

import Foundation

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution2 {
    public class TreeNode {
        public var val: Int
        public var left: TreeNode?
        public var right: TreeNode?
        public init() {
            self.val = 0;
            self.left = nil;
            self.right = nil;
        }
        public init(_ val: Int) {
            self.val = val;
            self.left = nil;
            self.right = nil;
        }
        public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
            self.val = val
            self.left = left
            self.right = right
        }
    }
    
    func rightSideView(_ root: TreeNode?) -> [Int] {
        guard let root = root else { return [] }
        
        var queue: [TreeNode] = []
        var result: [Int] = []
        
        queue.append(root)
        while !queue.isEmpty {
//            var count = queue.count - 1
//            while count >= 0 {
//                let node = queue.removeFirst()
//                if count == 0 {
//                    result.append(node.val)
//                }
//                if let left = node.left {
//                    queue.append(left)
//                }
//                if let right = node.right {
//                    queue.append(right)
//                }
//                count -= 1
//            }
            
            let count = queue.count
            for i in 0..<count {
                let node = queue.removeFirst()
                if i == count - 1 {
                    result.append(node.val)
                }
                if let left = node.left {
                    queue.append(left)
                }
                if let right = node.right {
                    queue.append(right)
                }
            }
        }
        
        return result
    }
}
