# 494. Target Sum

## Problem Statement

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols &#39;+&#39; and &#39;-&#39; before each integer in nums and then concatenate all the integers.

	For example, if nums = [2, 1], you can add a &#39;+&#39; before 2 and a &#39;-&#39; before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:

Input: nums = [1], target = 1
Output: 1

Constraints:

	1 <= nums.length <= 20
	0 <= nums[i] <= 1000
	0 <= sum(nums[i]) <= 1000
	-1000 <= target <= 1000

## Solution

The solution is implemented in C++ and can be found in the `solution.cpp` file.

## Complexity Analysis

- **Time Complexity:** O(?) - Please analyze and update
- **Space Complexity:** O(?) - Please analyze and update

## Tags

*Medium*

## LeetCode Link

[494. Target Sum](https://leetcode.com/problems/target-sum/)

---

*This solution was automatically downloaded from LeetCode.*
