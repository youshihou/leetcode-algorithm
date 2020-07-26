//
//  T329-longest-increasing-path-in-a-matrix.cpp
//  algorithm
//
//  Created by Ankui on 7/26/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

// https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/


#include "T329-longest-increasing-path-in-a-matrix.hpp"

#include<math.h>
#include<vector>

using namespace::std;


class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j, int m, int n) {
        int left, right, top, bottom;
        left = right = top = bottom = 0;
        
        if (i >= 1 && matrix[i - 1][j] > matrix[i][j]) {
            top = visited[i - 1][j] > 1 ? visited[i - 1][j] : dfs(matrix, visited, i - 1, j, m, n);
        }
        if (j >= 1 && matrix[i][j - 1] > matrix[i][j]) {
            left = visited[i][j - 1] > 1 ? visited[i][j - 1] : dfs(matrix, visited, i, j - 1, m, n);
        }
        if (i < m - 1 && matrix[i + 1][j] > matrix[i][j]) {
            bottom = visited[i + 1][j] > 1 ? visited[i + 1][j] : dfs(matrix, visited, i + 1, j, m, n);
        }
        if (j < n - 1 && matrix[i][j + 1] > matrix[i][j]) {
            right = visited[i][j + 1] > 1 ? visited[i][j + 1] : dfs(matrix, visited, i, j + 1, m, n);
        }
        visited[i][j] = 1 + max(max(top, bottom), max(left, right));
        return visited[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        if (m == 0) { return 0; }
        int n = (int)matrix[0].size();
        vector<vector<int>> visited (m, vector<int>(n, 1));
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, (int)dfs(matrix, visited, i, j, m, n));
            }
        }
        return result;
    }
};
