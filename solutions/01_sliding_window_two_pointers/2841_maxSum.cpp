/*
 * 2841. Maximum Sum of Almost Unique Subarray
 * 定长滑动窗口 · 基础
 *
 * 思路：
 *   固定窗口大小 k，维护窗口内不同元素的种类数（cnt.size()）。
 *   当 cnt.size() >= m 时更新最大和。
 *
 * 与 2461 的对比：
 *   2461：distinct == k（全部互异）
 *   2841：cnt.size() >= m（允许重复，只要求至少 m 种）
 *
 * C++ 技巧：
 *   cnt.size() → 当前窗口内不同元素的数量（unordered_map 的键数）
 *   cnt.erase(key) → 归零时移除键，保持 size() 准确
 *
 * 复杂度：
 *   时间 O(n) 空间 O(k)
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0, sum = 0;
        int left = 0;
        unordered_map<int, int> cnt;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            cnt[nums[right]]++;

            if (right - k + 1 < 0) continue;   // 窗口未满

            if (cnt.size() >= m) {              // 至少 m 种不同元素
                ans = max(ans, sum);
            }

            // 滑出左边界
            sum -= nums[left];
            cnt[nums[left]]--;
            if (cnt[nums[left]] == 0) {
                cnt.erase(nums[left]);
            }
            left++;
        }

        return ans;
    }
};
