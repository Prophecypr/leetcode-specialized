/*
 * 1208. Get Equal Substrings Within Budget
 * 不定长滑动窗口 · 求最长/最大（基础）
 *
 * 思路：
 *   维护滑动窗口，累计窗口内字符转换成本 sum。
 *   当 sum > maxCost 时收缩左边界直到符合预算。
 *   用 max(ans, right - left + 1) 更新最长窗口。
 *
 * 模板化：
 *   这是不定长窗口的"最直白"应用——只有一维约束（sum ≤ maxCost）。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(), sum = 0, ans = 0, left = 0;

        for (int right = 0; right < n; right++) {
            sum += abs(s[right] - t[right]);   // 右边界成本

            while (sum > maxCost) {            // 超预算 → 收缩
                sum -= abs(s[left] - t[left]);
                left++;
            }

            ans = max(ans, right - left + 1);  // 更新最长
        }

        return ans;
    }
};
