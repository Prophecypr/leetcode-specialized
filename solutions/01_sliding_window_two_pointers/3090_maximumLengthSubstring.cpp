/*
 * 3090. Maximum Length Substring With Two Occurrences
 * 不定长滑动窗口 · 求最长/最大（基础）
 *
 * 思路：
 *   与 3 完全相同的模板，唯一区别：允许每个字符最多出现 2 次。
 *   while 收缩条件改为 cnt[c] > 2。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(|字符集|)
 */

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length(), ans = 0, left = 0;
        unordered_map<char, int> cnt;

        for (int right = 0; right < n; right++) {
            char c = s[right];
            cnt[c]++;

            // 超过 2 次 → 收缩直到每种字符 ≤2
            while (cnt[c] > 2) {
                cnt[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
