/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (40.68%)
 * Likes:    4401
 * Dislikes: 0
 * Total Accepted:    482.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 *
 *
 * 示例 4：
 *
 *
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 *
 *
 * 示例 5：
 *
 *
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0
 * 0
 * 1
 * -10^6
 *
 *
 *
 *
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 *
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int k = (n1 + n2 + 1) / 2;
        int l = 0, r = n1;
        while (l < r)
        {
            int m1 = (r - l) / 2 + l;
            int m2 = k - m1;
            if (nums1[m1] < nums2[m2 - 1])
            {
                l = m1 + 1;
            }
            else
            {
                r = m1;
            }
        }
        int ml = l;
        int mr = k - l;
        // int mll, mrr;
        int resl = max(ml <= 0 ? INT_MIN : nums1[ml - 1], mr <= 0 ? INT_MIN : nums2[mr - 1]);
        if ((n1 + n2) % 2 == 1)
        {
            return resl * 1.0;
        }
        int resr = min(ml >= n1 ? INT_MAX : nums1[ml], mr >= n2 ? INT_MAX : nums2[mr]);
        return (resl + resr) * 1.0 / 2;
    }
};
// @lc code=end
