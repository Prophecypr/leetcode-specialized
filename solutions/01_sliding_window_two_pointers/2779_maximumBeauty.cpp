/*
 * 2779. Maximum Beauty of an Array After Applying Operations
 * 不定长滑动窗口 · 求最长/最大（进阶选做）
 *
 * 思路：
 *   每个元素可以加减 k，若想使子序列全部相等为 x，
 *   则所有元素必须在 [x-k, x+k] 范围内，跨度 ≤ 2k。
 *   排序后找最长子数组满足 max - min ≤ 2k。
 *
 * 复杂度：
 *   时间 O(n log n) 空间 O(1)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ranges::sort(nums);
        int ans = 0, left = 0;

        for (int right = 0; right < nums.size(); right++) {
            while (nums[right] - nums[left] > 2 * k) {
                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
