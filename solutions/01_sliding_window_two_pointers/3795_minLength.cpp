/*
 * 3795. 按位与运算后不同元素的最小长度
 * 不定长滑动窗口 · 求最短/最小 ⭐
 *
 * 思路：
 *   求最短子数组，其中不同元素之和 ≥ k。
 *   sum 只统计窗口内不同元素（每个值只加一次）。
 *   用 unordered_map 跟踪频率，首次出现时加 sum，末次消失时减 sum。
 *   与 209 同模板，但约束条件从"全部元素和"变为"不同元素和"。
 *
 * 关键：
 *   - cnt[x] == 1 → 首次出现，加入 sum
 *   - cnt[x] == 0 → 末次消失，从 sum 移除
 *   - 无解返回 -1（与 209 返回 0 不同）
 *
 * 复杂度：
 *   时间 O(n) 空间 O(n)
 */

#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int ans = INT_MAX, sum = 0, left = 0;
        unordered_map<int, int> cnt;

        for (int right = 0; right < nums.size(); right++) {
            // 右边界入窗，首次出现才计入 sum
            if (cnt[nums[right]] == 0) sum += nums[right];
            cnt[nums[right]]++;

            while (sum >= k) {
                ans = min(ans, right - left + 1);
                // 左边界出窗，末次消失才从 sum 移除
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 0) sum -= nums[left];
                left++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
