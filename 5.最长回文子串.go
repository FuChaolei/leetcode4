/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (35.37%)
 * Likes:    4101
 * Dislikes: 0
 * Total Accepted:    727.2K
 * Total Submissions: 2.1M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "a"
 * 输出："a"
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "ac"
 * 输出："a"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由数字和英文字母（大写和/或小写）组成
 *
 *
 */

// @lc code=start
func longestPalindrome(s string) string {
	n := len(s)
	get_l := func(l int, r int) int {
		for l >= 0 && r <= n-1 && s[l] == s[r] {
			l--
			r++
		}
		return r - l - 1
	}
	res := 0
	b := 0
	for i := 0; i < len(s); i++ {
		tmp := max(get_l(i, i), get_l(i, i+1))
		if res < tmp {
			res = tmp
			b = i - (tmp-1)/2
		}
	}
	return s[b : b+res]
}
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

