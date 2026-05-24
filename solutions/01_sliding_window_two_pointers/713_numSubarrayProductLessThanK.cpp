/*
 * 713. Subarray Product Less Than K
 * 求子数组个数 · 越短越合法
 *
 * 思路：
 *   计数型问题，与求最长/最短不同。
 *   维护窗口乘积 prod < k，每次右扩展后，
 *   以 right 结尾的有效子数组数 = right - left + 1。
 *   累加这些数量即答案。
 *
 * 关键：
 *   - ans += right - left + 1 是计数问题的核心公式
 *   - k <= 1 时所有正整数乘积都不 < k，直接返回 0
 *   - prod >= k 时用除法移出左边界
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;           // 乘积不可能小于 ≤1 的数

        int ans = 0, prod = 1, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];

            while (prod >= k) {
                prod /= nums[left];
                left++;
            }

            ans += right - left + 1;     // 以 right 结尾的有效子数组数
        }

        return ans;
    }
};
