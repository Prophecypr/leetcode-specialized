/*
 * 904. Fruit Into Baskets
 * 不定长滑动窗口 · 求最长/最大（基础）
 *
 * 思路：
 *   求最长子数组，其中最多包含 2 种不同的数字（水果）。
 *   用 unordered_map 记录窗口内每种水果的数量。
 *   当 cnt.size() > 2 时收缩左边界，直至仅剩 2 种。
 *
 * C++ 细节（官方解法所学）：
 *   - cnt.size() → 当前窗口内不同水果种类数
 *   - cnt.erase(key) → 当某种水果数量归零时，从 map 中移除该键
 *   - string 可用 .length() 和 .size()；vector 只能用 .size()
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)（最多 2 种水果）
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, left = 0;
        unordered_map<int, int> cnt;

        for (int right = 0; right < fruits.size(); right++) {
            cnt[fruits[right]]++;              // 入窗

            while (cnt.size() > 2) {           // 超过 2 种水果 → 收缩
                int out = fruits[left];
                cnt[out]--;
                if (cnt[out] == 0) {
                    cnt.erase(out);            // 归零时移除键
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
