/*
 * @lc app=leetcode.cn id=912 lang=cpp
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
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
        {
            return;
        }
        int mid = (r - l) / 2 + l;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    void merge(vector<int> &nums, int l, int mid, int r)
    {
        vector<int> l1, l2;
        for (int i = l; i <= mid; i++)
        {
            l1.emplace_back(nums[i]);
        }
        for (int i = mid + 1; i <= r; i++)
        {
            l2.emplace_back(nums[i]);
        }
        l1.emplace_back(INT_MAX);
        l2.emplace_back(INT_MAX);
        int x = 0, y = 0;
        for (int i = l; i <= r; i++)
        {
            if (l1[x] <= l2[y])
            {
                nums[i] = l1[x];
                x++;
            }
            else
            {
                nums[i] = l2[y];
                y++;
            }
        }
    }
};
// @lc code=end
