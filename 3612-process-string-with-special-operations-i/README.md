# 3612. Process String with Special Operations I

## Problem Statement

You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

	If the letter is a lowercase English letter append it to result.
	A &#39;*&#39; removes the last character from result, if it exists.
	A &#39;#&#39; duplicates the current result and appends it to itself.
	A &#39;%&#39; reverses the current result.

Return the final string result after processing all characters in s.

Example 1:

Input: s = "a#b%*"

Output: "ba"

Explanation:

			i
			s[i]
			Operation
			Current result

			0
			&#39;a&#39;
			Append &#39;a&#39;
			"a"

			1
			&#39;#&#39;
			Duplicate result
			"aa"

			2
			&#39;b&#39;
			Append &#39;b&#39;
			"aab"

			3
			&#39;%&#39;
			Reverse result
			"baa"

			4
			&#39;*&#39;
			Remove the last character
			"ba"

Thus, the final result is "ba".

Example 2:

Input: s = "z*#"

Output: ""

Explanation:

			i
			s[i]
			Operation
			Current result

			0
			&#39;z&#39;
			Append &#39;z&#39;
			"z"

			1
			&#39;*&#39;
			Remove the last character
			""

			2
			&#39;#&#39;
			Duplicate the string
			""

Thus, the final result is "".

Constraints:

	1 <= s.length <= 20
	s consists of only lowercase English letters and special characters *, #, and %.

## Solution

The solution is implemented in C++ and can be found in the `solution.cpp` file.

## Complexity Analysis

- **Time Complexity:** O(?) - Please analyze and update
- **Space Complexity:** O(?) - Please analyze and update

## Tags

*Medium*

## LeetCode Link

[3612. Process String with Special Operations I](https://leetcode.com/problems/process-string-with-special-operations-i/)

---

*This solution was automatically downloaded from LeetCode.*
