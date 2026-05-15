/*
 * 3634. 数组元素最小移除数
 * 不定长滑动窗口 · 求最长/最大（基础）
 *
 * 思路：
 *   先排序，排序后窗口内最大值 = nums[right]，最小值 = nums[left]。
 *   维护窗口满足 nums[right] / nums[left] ≤ k。
 *   找最长合法子数组，返回 n - longest。
 *
 *   最小移除数 = 总数 - 最长合法子数组长度。
 *
 * 复杂度：
 *   时间 O(n log n) 空间 O(1)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        ranges::sort(nums);
        int n = nums.size(), ans = 0, left = 0;

        for (int right = 0; right < n; right++) {
            // 不满足 nums[right] / nums[left] ≤ k → 收缩窗口
            while (1LL * nums[left] * k < nums[right]) {
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return n - ans;
    }
};
