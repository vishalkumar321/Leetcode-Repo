# 1061. Lexicographically Smallest Equivalent String

## Problem Statement

You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

	For example, if s1 = "abc" and s2 = "cde", then we have &#39;a&#39; == &#39;c&#39;, &#39;b&#39; == &#39;d&#39;, and &#39;c&#39; == &#39;e&#39;.

Equivalent characters follow the usual rules of any equivalence relation:

	Reflexivity: &#39;a&#39; == &#39;a&#39;.
	Symmetry: &#39;a&#39; == &#39;b&#39; implies &#39;b&#39; == &#39;a&#39;.
	Transitivity: &#39;a&#39; == &#39;b&#39; and &#39;b&#39; == &#39;c&#39; implies &#39;a&#39; == &#39;c&#39;.

For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

Example 1:

Input: s1 = "parker", s2 = "morris", baseStr = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
The characters in each group are equivalent and sorted in lexicographical order.
So the answer is "makkek".

Example 2:

Input: s1 = "hello", s2 = "world", baseStr = "hold"
Output: "hdld"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
So only the second letter &#39;o&#39; in baseStr is changed to &#39;d&#39;, the answer is "hdld".

Example 3:

Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
Output: "aauaaaaada"
Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except &#39;u&#39; and &#39;d&#39; are transformed to &#39;a&#39;, the answer is "aauaaaaada".

Constraints:

	1 <= s1.length, s2.length, baseStr <= 1000
	s1.length == s2.length
	s1, s2, and baseStr consist of lowercase English letters.

## Solution

The solution is implemented in C++ and can be found in the `solution.cpp` file.

## Complexity Analysis

- **Time Complexity:** O(?) - Please analyze and update
- **Space Complexity:** O(?) - Please analyze and update

## Tags

*Medium*

## LeetCode Link

[1061. Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/)

---

*This solution was automatically downloaded from LeetCode.*
