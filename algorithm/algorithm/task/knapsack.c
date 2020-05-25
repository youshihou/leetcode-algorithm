//
//  knapsack.c
//  algorithm
//
//  Created by Ankui on 5/25/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "knapsack.h"
#include "algorithm-common.h"


int knapsack_maxValue_exactly(int* values, int* weights, int size, int capacity) {
    if (values == NULL || weights == NULL || size <= 0 || capacity <= 0) { return 0; }
    
    int dp[capacity + 1];
    dp[0] = 0;
    for (int j = 1; j <= capacity; j++) {
        dp[j] = INT_MIN;
    }
    for (int i = 1; i <= size; i++) {
        for (int j = capacity; j >= weights[i - 1]; j--) {
            dp[j] = MAX(dp[j], values[i - 1] + dp[j - weights[i - 1]]);
        }
    }
    
    return dp[capacity] < 0 ? - 1 : dp[capacity];
}




int knapsack_maxValue(int* values, int* weights, int size, int capacity) {
    if (values == NULL || weights == NULL || size <= 0 || capacity <= 0) { return 0; }
    
    int dp[capacity + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= size; i++) {
        for (int j = capacity; j >= weights[i - 1]; j--) { // CARE!!! j >= weights[i - 1]
            dp[j] = MAX(dp[j], values[i - 1] + dp[j - weights[i - 1]]);
        }
    }
    
    return dp[capacity];
}




int knapsack_maxValue3(int* values, int* weights, int size, int capacity) {
    if (values == NULL || weights == NULL || size <= 0 || capacity <= 0) { return 0; }
    
    int dp[capacity + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= size; i++) {
        for (int j = capacity; j >= 1; j--) {
            if (j < weights[i - 1]) { continue; }
            dp[j] = MAX(dp[j], values[i - 1] + dp[j - weights[i - 1]]);
            
//            if (j < weights[i - 1]) {
//                dp[j] = dp[j];
//            } else {
//                dp[j] = MAX(dp[j], values[i - 1] + dp[j - weights[i - 1]]);
//            }
        }
    }
    
    return dp[capacity];
}





int knapsack_maxValue2(int* values, int* weights, int size, int capacity) {
    if (values == NULL || weights == NULL || size <= 0 || capacity <= 0) { return 0; }
    
    int dp[2][capacity + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= size; i++) {
        int row = i & 1;
        int preRow = (i - 1) & 1;
        for (int j = 1; j <= capacity; j++) {
            if (j < weights[i - 1]) {
                dp[row][j] = dp[preRow][j];
            } else {
                dp[row][j] = MAX(dp[preRow][j], values[i - 1] + dp[preRow][j - weights[i - 1]]);
            }
        }
    }
    
    return dp[size & 1][capacity];
}



int knapsack_maxValue1(int* values, int* weights, int size, int capacity) {
    if (values == NULL || weights == NULL || size <= 0 || capacity <= 0) { return 0; }
    
    int dp[size + 1][capacity + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (j < weights[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = MAX(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]); // CARE!!! values[i - 1], weights[i - 1]
            }
        }
    }
    
    return dp[size][capacity];
}
