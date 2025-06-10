# 🌧️ Trapping Rain Water in C++

This project implements the **Trapping Rain Water** problem using C++. It calculates how much water can be trapped between elevation bars after rainfall.

## 📘 Problem Statement

Given an array `height[]` of non-negative integers representing the elevation map where the width of each bar is 1, compute how much water it can trap after raining.

## ✅ Features

- Uses prefix and suffix maximum arrays (`prev[]` and `next[]`) to calculate water trapped at each index.
- Optimized approach for time complexity.
- Demonstrates clear logic using helper arrays and clean iteration.

## 🧠 Algorithm Overview

1. **Left Max Array (`prev[]`)**:
   - Stores the highest bar to the left of the current bar.
2. **Right Max Array (`next[]`)**:
   - Stores the highest bar to the right of the current bar.
3. **Water Calculation**:
   - For each bar, calculate the minimum of `prev[i]` and `next[i]` and subtract the height of the current bar to get trapped water.

## 💻 Code

```cpp
#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int prev[n];
    prev[0] = -1;
    int max = height[0];
    for(int i = 1; i < n; i++) {
        prev[i] = max;
        if(max < height[i]) max = height[i];
    }

    int next[n];
    next[n - 1] = -1;
    max = height[n - 1];
    for(int i = n - 2; i > 0; i--) {
        next[i] = max;
        if(max < height[i]) max = height[i]; // missing update in original code
    }

    int mini[n];
    for(int i = 0; i < n; i++) {
        mini[i] = min(prev[i], next[i]);
    }

    int water = 0;
    for(int i = 0; i < n - 1; i++) {
        if(height[i] < mini[i]) {
            water += (mini[i] - height[i]);
        }
    }

    return water;
}

int main() {
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Input Heights:\n";
    for(int h : v) cout << h << " ";
    cout << "\n";

    int totalWater = trap(v);
    cout << "Total Water Trapped: " << totalWater << " units\n";

    return 0;
}
