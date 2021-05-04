//
//  T292-nim-game.swift
//  algorithm
//
//  Created by Ankui on 5/4/21.
//  Copyright © 2021 Ankui. All rights reserved.
//

import Foundation

class t292_Solution {
    func canWinNim(_ n: Int) -> Bool {
        return n % 4 == 0 ? false : true
//        return n % 4 != 0
    }
}
