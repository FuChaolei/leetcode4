	/*
	 * @lc app=leetcode.cn id=912 lang=golang
	 *
	 * [912] 排序数组
	 *
	 * https://leetcode-cn.com/problems/sort-an-array/description/
	 *
	 * algorithms
	 * Medium (56.57%)
	 * Likes:    361
	 * Dislikes: 0
	 * Total Accepted:    211.9K
	 * Total Submissions: 375.1K
	 * Testcase Example:  '[5,2,3,1]'
	 *
	 * 给你一个整数数组 nums，请你将该数组升序排列。
	 *
	 *
	 *
	 *
	 *
	 *
	 * 示例 1：
	 *
	 * 输入：nums = [5,2,3,1]
	 * 输出：[1,2,3,5]
	 *
	 *
	 * 示例 2：
	 *
	 * 输入：nums = [5,1,1,2,0,0]
	 * 输出：[0,0,1,1,2,5]
	 *
	 *
	 *
	 *
	 * 提示：
	 *
	 *
	 * 1 <= nums.length <= 50000
	 * -50000 <= nums[i] <= 50000
	 *
	 *
	 */

	// @lc code=start
	func sortArray(nums []int) []int {
		mergeSort(nums, 0, len(nums)-1)
		return nums
	}
	func mergeSort(nums []int, l int, r int) {
		if l >= r {
			return
		}
		mid := (r-l)/2 + l
		mergeSort(nums, l, mid)
		mergeSort(nums, mid+1, r)
		merge(nums, l, mid, r)
	}
	func merge(nums []int, l, mid, r int) {
		left := append([]int{}, nums[l:mid+1]...)
		right := append([]int{}, nums[mid+1:r+1]...)
		left = append(left, math.MaxInt)
		right = append(right, math.MaxInt)
		i, j := 0, 0
		for t := l; t <= r; t++ {
			if left[i] < right[j] {
				nums[t] = left[i]
				i++
			} else {
				nums[t] = right[j]
				j++
			}
		}
		return
	}

	// @lc code=end

