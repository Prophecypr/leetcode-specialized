/*
 * 3. Longest Substring Without Repeating Characters
 * 不定长滑动窗口 · 求最长/最大（基础）
 *
 * 思路：
 *   用 left, right 双指针维护一个无重复字符的窗口。
 *   每次右指针扩展一个字符 c，若 c 出现次数 >1，则收缩左指针
 *   直到 c 的计数为 1，此时窗口内一定无重复。
 *   每次更新 ans = max(ans, window_size)。
 *
 * 关键：
 *   - 用 while 收缩直到条件满足（而不是 if），因为可能连续移除多个
 *   - unordered_map 记录字符出现次数（或用数组更快）
 *
 * 复杂度：
 *   时间 O(n) 空间 O(|字符集|)
 */

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0, left = 0;
        unordered_map<char, int> cnt;

        for (int right = 0; right < n; right++) {
            char c = s[right];
            cnt[c]++;

            // 窗口内有重复 → 收缩左边界直到无重复
            while (cnt[c] > 1) {
                cnt[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
