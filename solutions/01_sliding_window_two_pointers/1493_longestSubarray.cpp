/*
 * 1493. Longest Subarray of 1's After Deleting One Element
 * 不定长滑动窗口 · 求最长/最大（基础）
 *
 * 思路：
 *   窗口内最多允许包含 1 个 0（因为只能删除一个元素）。
 *   维持 cnt0 ≤ 1，当 cnt0 > 1 时收缩 left 指针。
 *   答案取 max(right - left)，注意不是 right - left + 1：
 *     无论窗口内是否有 0，删完一个元素后的 1 子数组长度 = 窗口长度 - 1。
 *
 * 关键技巧：
 *   - 1 - nums[right] 将 1→0, 0→1，直接统计 0 的个数
 *   - 本题本质是 "最多 1 个 0" 的最长窗口，比字符频数更简单
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0, cnt0 = 0, left = 0;

        for (int right = 0; right < n; right++) {
            cnt0 += 1 - nums[right];          // 0→cnt0++, 1→cnt0 不变

            while (cnt0 > 1) {                // 超过 1 个 0 → 收缩
                cnt0 -= 1 - nums[left];
                left++;
            }

            ans = max(ans, right - left);     // 删一个元素后长度 = 窗口 - 1
        }

        return ans;
    }
};
