/*
 * 2958. Length of Longest Subarray With at Most K Frequency
 * 不定长滑动窗口 · 求最长/最大（基础）
 *
 * 思路：
 *   维护窗口内每个元素的出现次数 ≤ k。
 *   当 cnt[nums[right]] > k 时收缩 left 直至满足条件。
 *   这是 3 (k=1) 和 3090 (k=2) 的通解泛化版本。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(n)
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, left = 0;
        unordered_map<int, int> cnt;

        for (int right = 0; right < nums.size(); right++) {
            cnt[nums[right]]++;

            while (cnt[nums[right]] > k) {   // 通解：>k 时收缩
                cnt[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
